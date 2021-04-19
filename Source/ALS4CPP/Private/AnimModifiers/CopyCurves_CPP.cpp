


#include "AnimModifiers/CopyCurves_CPP.h"
#include "AnimationBlueprintLibrary.h"

void UCopyCurves_CPP::OnApply_Implementation(UAnimSequence* AnimationSequence)
{
    AnimSequence = AnimationSequence;

    TArray<FName>* Curves = bCopyAllCurves ? &AllCurves : &CurvesToCopy;
    for (auto& Name : *Curves)
    {
        CurveName = Name;

        if (UAnimationBlueprintLibrary::DoesCurveExist(AnimToCopyFrom, CurveName, ERawCurveTrackTypes::RCT_Float))
        {
            if (UAnimationBlueprintLibrary::DoesCurveExist(AnimSequence, CurveName, ERawCurveTrackTypes::RCT_Float))
            {
                UAnimationBlueprintLibrary::RemoveCurve(AnimSequence, CurveName);
            }

            UAnimationBlueprintLibrary::AddCurve(AnimSequence, CurveName, ERawCurveTrackTypes::RCT_Float);

            TArray<float> Times;
            TArray<float> Values;
            UAnimationBlueprintLibrary::GetFloatKeys(AnimToCopyFrom, CurveName, Times, Values);
            UAnimationBlueprintLibrary::AddFloatCurveKeys(AnimSequence, CurveName, Times, Values);
        }
    }
}

UAnimSequence* UCopyCurves_CPP::GetAnimToCopyFrom() const
{
    return AnimToCopyFrom;
}

void UCopyCurves_CPP::SetAnimToCopyFrom(UAnimSequence* NewAnim)
{
    AnimToCopyFrom = NewAnim;
}

bool UCopyCurves_CPP::IsCopyAllCurves() const
{
    return bCopyAllCurves;
}

void UCopyCurves_CPP::SetIsCopyAllCurves(bool IsCopyAllCurves)
{
    bCopyAllCurves = IsCopyAllCurves;
}

TArray<FName>& UCopyCurves_CPP::GetCurvesToCopy()
{
    return CurvesToCopy;
}
