

#include "AnimModifiers/CreateCurves_CPP.h"
#include "AnimationBlueprintLibrary.h"

void UCreateCurves_CPP::OnApply_Implementation(UAnimSequence* AnimationSequence)
{
	AnimSequence = AnimationSequence;

	for (auto& CurveParam : CurvesToCreate)
	{
		if (UAnimationBlueprintLibrary::DoesCurveExist(AnimSequence, CurveParam.CurveName, ERawCurveTrackTypes::RCT_Float))
		{
			UAnimationBlueprintLibrary::RemoveCurve(AnimSequence, CurveParam.CurveName);
		}

		UAnimationBlueprintLibrary::AddCurve(AnimSequence, CurveParam.CurveName, ERawCurveTrackTypes::RCT_Float);

		if (CurveParam.KeyEachFrame)
		{
			int32 FrameNum = AnimSequence->GetNumberOfFrames();
			for (int32 Idx = 0; Idx < FrameNum - 2; ++Idx)
			{
				UAnimationBlueprintLibrary::AddFloatCurveKey(AnimSequence, CurveParam.CurveName,
					AnimSequence->GetTimeAtFrame(Idx), 0.0f);
			}
		}
		else
		{
			for (auto& Data : CurveParam.Keys)
			{
				UAnimationBlueprintLibrary::AddFloatCurveKey(AnimSequence, CurveParam.CurveName,
					AnimSequence->GetTimeAtFrame(Data.FrameNumber), Data.CurveValue);
			}
		}
	}
}

TArray<FAnimCurveCreationParams_CPP>& UCreateCurves_CPP::GetCurvesToCreate()
{
	return CurvesToCreate;
}