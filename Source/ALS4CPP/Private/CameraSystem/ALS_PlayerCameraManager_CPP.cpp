


#include "CameraSystem/ALS_PlayerCameraManager_CPP.h"
#include "CameraSystem/ALS_PlayerCameraBehavior_CPP.h"
#include "CharacterLogic/ALS_BaseCharacter_CPP.h"
#include "CharacterLogic/ALS_PlayerController_CPP.h"
#include "DrawDebugHelpers.h"

namespace
{
	void DrawDebugSweptSphere(const UWorld* InWorld, FVector const& Start, FVector const& End, float Radius, 
		FColor const& Color, bool bPersistentLines, float LifeTime = -1.f, uint8 DepthPriority = 0)
	{
		FVector const TraceVec = End - Start;
		float const Dist = TraceVec.Size();

		FVector const Center = Start + TraceVec * 0.5f;
		float const HalfHeight = (Dist * 0.5f) + Radius;

		FQuat const CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
		::DrawDebugCapsule(InWorld, Center, HalfHeight, Radius, CapsuleRot, Color, bPersistentLines, LifeTime, DepthPriority);
	}

	void DrawDebugSphereTraceSingle(const UWorld* World, const FVector& Start, const FVector& End, float Radius, 
		EDrawDebugTrace::Type DrawDebugType, bool bHit, const FHitResult& OutHit, FLinearColor TraceColor, FLinearColor TraceHitColor, float DrawTime)
	{
		if (DrawDebugType != EDrawDebugTrace::None)
		{
			bool bPersistent = DrawDebugType == EDrawDebugTrace::Persistent;
			float LifeTime = (DrawDebugType == EDrawDebugTrace::ForDuration) ? DrawTime : 0.f;

			if (bHit && OutHit.bBlockingHit)
			{
				// Red up to the blocking hit, green thereafter
				::DrawDebugSweptSphere(World, Start, OutHit.Location, Radius, TraceColor.ToFColor(true), bPersistent, LifeTime);
				::DrawDebugSweptSphere(World, OutHit.Location, End, Radius, TraceHitColor.ToFColor(true), bPersistent, LifeTime);
				::DrawDebugPoint(World, OutHit.ImpactPoint, 16.0f, TraceColor.ToFColor(true), bPersistent, LifeTime);
			}
			else
			{
				// no hit means all red
				::DrawDebugSweptSphere(World, Start, End, Radius, TraceColor.ToFColor(true), bPersistent, LifeTime);
			}
		}
	}
}

void AALS_PlayerCameraManager_CPP::OnPossess_Implementation(APawn* NewPawn)
{
	ControlledPawn = Cast<AALS_BaseCharacter_CPP>(NewPawn);

	auto ALS_CameraBehavior = Cast<UALS_PlayerCameraBehavior_CPP>(CameraBehavior->GetAnimInstance());
	if (ALS_CameraBehavior != nullptr)
	{
		ALS_CameraBehavior->SetPlayerController(GetOwningPlayerController());
		ALS_CameraBehavior->SetControlledPawn(ControlledPawn);
	}
}

void AALS_PlayerCameraManager_CPP::CustomCameraBehavior(FTViewTarget& OutVT, float DeltaTime)
{
	// Step1
	FTransform PivotTarget;
	ControlledPawn->Get3pPivotTarget(PivotTarget);

	FVector FpTarget;
	ControlledPawn->GetFpCameraTarget(FpTarget);

	float TpFOV = 0.0f;
	float FpFOV = 0.0f;
	bool Dummy = false;
	ControlledPawn->GetCameraParameters(TpFOV, FpFOV, Dummy);

	// Step2
	static const FName RotationLagSpeed = TEXT("RotationLagSpeed");
	FRotator CamRot = FMath::RInterpTo(GetCameraRotation(), GetOwningPlayerController()->GetControlRotation(), 
		DeltaTime, GetCameraBehaviorParam(RotationLagSpeed));

	static const FName Override_Debug = TEXT("Override_Debug");
	TargetCameraRotation = FMath::Lerp(CamRot, DebugViewRotation, GetCameraBehaviorParam(Override_Debug));

	// Step3
	static const FName PivotLagSpeed_X = TEXT("PivotLagSpeed_X");
	static const FName PivotLagSpeed_Y = TEXT("PivotLagSpeed_Y");
	static const FName PivotLagSpeed_Z = TEXT("PivotLagSpeed_Z");
	FVector LegSpeeds(GetCameraBehaviorParam(PivotLagSpeed_X), GetCameraBehaviorParam(PivotLagSpeed_Y), 
		GetCameraBehaviorParam(PivotLagSpeed_Z));

	FVector Location = CalculateAxisIndepedentLag(SmoothedPivotTarget.GetLocation(), PivotTarget.GetLocation(),
		TargetCameraRotation, LegSpeeds, DeltaTime);

	SmoothedPivotTarget = FTransform(PivotTarget.GetRotation(), Location);

	// Step4
	static const FName PivotOffset_X = TEXT("PivotOffset_X");
	static const FName PivotOffset_Y = TEXT("PivotOffset_Y");
	static const FName PivotOffset_Z = TEXT("PivotOffset_Z");
	PivotLocation = SmoothedPivotTarget.GetLocation() +
		(SmoothedPivotTarget.GetRotation().GetForwardVector() * GetCameraBehaviorParam(PivotOffset_X)) +
		(SmoothedPivotTarget.GetRotation().GetRightVector() * GetCameraBehaviorParam(PivotOffset_Y)) +
		(SmoothedPivotTarget.GetRotation().GetUpVector() * GetCameraBehaviorParam(PivotOffset_Z));

	// Step5
	static const FName CameraOffset_X = TEXT("CameraOffset_X");
	static const FName CameraOffset_Y = TEXT("CameraOffset_Y");
	static const FName CameraOffset_Z = TEXT("CameraOffset_Z");
	FVector CameraPos = PivotLocation +
		(TargetCameraRotation.Quaternion().GetForwardVector() * GetCameraBehaviorParam(CameraOffset_X)) +
		(TargetCameraRotation.Quaternion().GetRightVector() * GetCameraBehaviorParam(CameraOffset_Y)) +
		(TargetCameraRotation.Quaternion().GetUpVector() * GetCameraBehaviorParam(CameraOffset_Z));

	TargetCameraLocation = FMath::Lerp(CameraPos, PivotTarget.GetLocation() + DebugViewOffset, 
		GetCameraBehaviorParam(Override_Debug));

	// Step6
	FVector TraceOrigin;
	float TranceRadius;
	TEnumAsByte<ETraceTypeQuery> TraceChannel = ETraceTypeQuery::TraceTypeQuery1;
	ControlledPawn->Get3pTraceParams(TraceOrigin, TranceRadius, TraceChannel);

	UWorld* World = GetWorld();

	FHitResult OutHit;
	FCollisionQueryParams Params(NAME_None, false, this);
	bool const bHit = (World != nullptr) ? World->SweepSingleByChannel(OutHit, TraceOrigin, TargetCameraLocation, FQuat::Identity,
		UEngineTypes::ConvertToCollisionChannel(TraceChannel.GetValue()), FCollisionShape::MakeSphere(TranceRadius), Params) : false;

#if ENABLE_DRAW_DEBUG
	constexpr float DRAW_TIME = 5.0f;
	::DrawDebugSphereTraceSingle(World, TraceOrigin, TargetCameraLocation, TranceRadius, GetDebugTraceType(EDrawDebugTrace::ForOneFrame),
		bHit, OutHit, FLinearColor::Red, FLinearColor::Green, DRAW_TIME);
#endif

	if (OutHit.bBlockingHit && !OutHit.bStartPenetrating)
	{
		TargetCameraLocation += OutHit.Location - OutHit.TraceEnd;
	}

	// Step7
#if ENABLE_DRAW_DEBUG
	auto ALS_PlayerController = Cast<AALS_PlayerController_CPP>(GetOwningPlayerController());
	if (ALS_PlayerController != nullptr)
	{
		ACharacter* DummyChar = nullptr;
		bool bDummy = false;
		bool bShowDebugShapes = false;
		ALS_PlayerController->GetDebugInfo(DummyChar, bDummy, bDummy, bDummy, bShowDebugShapes, bDummy, bDummy, bDummy);

		if (bShowDebugShapes)
		{
			::DrawDebugSphere(World, PivotTarget.GetLocation(), 16.0f, 8.0f, FColor::Green, false, 0.0f, 0, 0.5f);
			::DrawDebugSphere(World, SmoothedPivotTarget.GetLocation(), 16.0f, 8.0f, FColor::Orange, false, 0.0f, 0, 0.5f);
			::DrawDebugLine(World, PivotLocation, SmoothedPivotTarget.GetLocation(), FColor::Cyan, false, 0.0f, 0, 0.5f);
		}
	}
#endif

	// Step8
	static const FName Weight_FirstPerson = TEXT("Weight_FirstPerson");

	FTransform FinalTransform(TargetCameraRotation, TargetCameraLocation);
	FinalTransform.BlendWith(FTransform(TargetCameraRotation, FpTarget), GetCameraBehaviorParam(Weight_FirstPerson));
	FinalTransform.BlendWith(FTransform(DebugViewRotation, TargetCameraLocation), GetCameraBehaviorParam(Override_Debug));

	OutVT.POV.Location = FinalTransform.GetLocation();
	OutVT.POV.Rotation = FinalTransform.GetRotation().Rotator();
	OutVT.POV.FOV = FMath::Lerp(TpFOV, FpFOV, GetCameraBehaviorParam(Weight_FirstPerson));
}

FVector AALS_PlayerCameraManager_CPP::CalculateAxisIndepedentLag(const FVector& CurrentLocation, 
	const FVector& TargetLocation, const FRotator& CameraRotation, const FVector& LagSpeeds, float DeltaTime) const
{
	FRotator CameraRotationYaw(0.0f, 0.0f, CameraRotation.Yaw);

	FVector CurUnrot = CameraRotationYaw.UnrotateVector(CurrentLocation);
	FVector TargetUnrot = CameraRotationYaw.UnrotateVector(TargetLocation);

	FVector Vec(FMath::FInterpTo(CurUnrot.X, TargetUnrot.X, DeltaTime, LagSpeeds.X),
		FMath::FInterpTo(CurUnrot.Y, TargetUnrot.Y, DeltaTime, LagSpeeds.Y),
		FMath::FInterpTo(CurUnrot.Z, TargetUnrot.Z, DeltaTime, LagSpeeds.Z));

	return CameraRotationYaw.RotateVector(Vec);
}

float AALS_PlayerCameraManager_CPP::GetCameraBehaviorParam(const FName& CurveName) const
{
	UAnimInstance* AnimInstance = CameraBehavior->GetAnimInstance();
	if (!::IsValid(AnimInstance))
		return 0.0f;

	return AnimInstance->GetCurveValue(CurveName);
}

EDrawDebugTrace::Type AALS_PlayerCameraManager_CPP::GetDebugTraceType(EDrawDebugTrace::Type ShowTraceType) const
{
	auto Controller = Cast<AALS_PlayerController_CPP>(GetOwningPlayerController());
	if (Controller != nullptr)
	{
		ACharacter* DummyChar = nullptr;
		bool bDummy = false;
		bool bShowTraces = false;
		Controller->GetDebugInfo(DummyChar, bDummy, bDummy, bShowTraces, bDummy, bDummy, bDummy, bDummy);

		if (bShowTraces)
		{
			return ShowTraceType;
		}
	}

	return EDrawDebugTrace::None;
}

void AALS_PlayerCameraManager_CPP::UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime)
{
	if (OutVT.Target != nullptr && OutVT.Target->ActorHasTag(FName(TEXT("ALS_Character"))))
	{
		CustomCameraBehavior(OutVT, DeltaTime);
	}
	else
	{
		Super::UpdateViewTargetInternal(OutVT, DeltaTime);
	}
}

