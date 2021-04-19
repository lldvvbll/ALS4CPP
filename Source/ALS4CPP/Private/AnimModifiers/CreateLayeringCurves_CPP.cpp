


#include "AnimModifiers/CreateLayeringCurves_CPP.h"

void UCreateLayeringCurves_CPP::OnApply_Implementation(UAnimSequence* AnimationSequence)
{
	AnimSequence = AnimationSequence;

	for (auto& CurveName : CurvesToCreate)
	{
		Curve = CurveName;

		if (UAnimationBlueprintLibrary::DoesCurveExist(AnimSequence, Curve, ERawCurveTrackTypes::RCT_Float))
		{
			UAnimationBlueprintLibrary::RemoveCurve(AnimSequence, Curve);
		}

		UAnimationBlueprintLibrary::AddCurve(AnimSequence, Curve, ERawCurveTrackTypes::RCT_Float);

		if (bKeyEachFrame)
		{
			int32 FrameNum = AnimSequence->GetNumberOfFrames();
			for (int32 Idx = 0; Idx < FrameNum - 2; ++Idx)
			{
				UAnimationBlueprintLibrary::AddFloatCurveKey(AnimSequence, Curve, AnimSequence->GetTimeAtFrame(Idx), DefaultValue);
			}
		}
		else
		{
			UAnimationBlueprintLibrary::AddFloatCurveKey(AnimSequence, Curve,
				AnimSequence->GetTimeAtFrame(0), DefaultValue);
		}
	}
}

TArray<FName>& UCreateLayeringCurves_CPP::GetCurvesToCreate()
{
	return CurvesToCreate;
}

float UCreateLayeringCurves_CPP::GetDefaultValue() const
{
	return DefaultValue;
}

void UCreateLayeringCurves_CPP::SetDefaultValue(float NewValue)
{
	DefaultValue = NewValue;
}

bool UCreateLayeringCurves_CPP::IsKeyEachFrame() const
{
	return bKeyEachFrame;
}

void UCreateLayeringCurves_CPP::SetIsKeyEachFrame(bool IsKeyEachFrame)
{
	bKeyEachFrame = IsKeyEachFrame;
}
