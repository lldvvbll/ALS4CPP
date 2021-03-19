

#pragma once

#include "ALS4CPP.h"
#include "Camera/PlayerCameraManager.h"
#include "ALS_PlayerCameraManager_CPP.generated.h"

class AALS_BaseCharacter_CPP;

UCLASS()
class ALS4CPP_API AALS_PlayerCameraManager_CPP : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent)
	void OnPossess(APawn* NewPawn);
	virtual void OnPossess_Implementation(APawn* NewPawn);

	void CustomCameraBehavior(FTViewTarget& OutVT, float DeltaTime);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector CalculateAxisIndepedentLag(const FVector& CurrentLocation, const FVector& TargetLocation, 
		const FRotator& CameraRotation, const FVector& LagSpeeds, float DeltaTime) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCameraBehaviorParam(const FName& CurveName) const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	EDrawDebugTrace::Type GetDebugTraceType(EDrawDebugTrace::Type ShowTraceType) const;

protected:
	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Default, Meta = (AllowPrivateAccess = true))
	USkeletalMeshComponent* CameraBehavior;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	AALS_BaseCharacter_CPP* ControlledPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FVector DebugViewOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FRotator DebugViewRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FVector RootLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FTransform SmoothedPivotTarget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FVector PivotLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FVector TargetCameraLocation;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FRotator TargetCameraRotation;
};
