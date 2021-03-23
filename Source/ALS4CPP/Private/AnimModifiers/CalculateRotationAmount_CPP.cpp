


#include "AnimModifiers/CalculateRotationAmount_CPP.h"
#include "AnimationBlueprintLibrary.h"

void UCalculateRotationAmount_CPP::OnApply_Implementation(UAnimSequence* AnimationSequence)
{
	Super::OnApply_Implementation(AnimationSequence);

	AnimSequence = AnimationSequence;

	if (UAnimationBlueprintLibrary::DoesCurveExist(AnimSequence, CurveName, ERawCurveTrackTypes::RCT_Float))
	{
		UAnimationBlueprintLibrary::RemoveCurve(AnimSequence, CurveName);
	}

	UAnimationBlueprintLibrary::AddCurve(AnimSequence, CurveName, ERawCurveTrackTypes::RCT_Float);

	for (int32 Idx = 0; Idx < AnimSequence->GetNumberOfFrames(); ++Idx)
	{
		int32 Frame = (AnimSequence->RateScale < 0.0f) ? -1 : 1;

		FTransform TransformA;
		UAnimationBlueprintLibrary::GetBonePoseForFrame(AnimSequence, RootBoneName, Idx + Frame, false, TransformA);

		FTransform TransformB;
		UAnimationBlueprintLibrary::GetBonePoseForFrame(AnimSequence, RootBoneName, Idx, false, TransformA);

		float Time = AnimSequence->GetTimeAtFrame(Idx);
		float Value = (TransformA.GetRotation().Rotator().Yaw - TransformB.GetRotation().Rotator().Yaw) * FMath::Abs(AnimSequence->RateScale);
		UAnimationBlueprintLibrary::AddFloatCurveKey(AnimSequence, CurveName, Time, Value);
	}
}

FName UCalculateRotationAmount_CPP::GetCurveName() const
{
	return CurveName;
}

void UCalculateRotationAmount_CPP::SetCurveName(const FName& NewCurveName)
{
	CurveName = NewCurveName;
}

FName UCalculateRotationAmount_CPP::GetRootBoneName() const
{
	return RootBoneName;
}

void UCalculateRotationAmount_CPP::SetRootBoneName(const FName& NewRootBoneName)
{
	RootBoneName = NewRootBoneName;
}
