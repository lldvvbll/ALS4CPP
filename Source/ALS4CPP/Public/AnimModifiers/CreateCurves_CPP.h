

#pragma once

#include "ALS4CPP.h"
#include "AnimationModifier.h"
#include "Data/Structs.h"
#include "CreateCurves_CPP.generated.h"

UCLASS()
class ALS4CPP_API UCreateCurves_CPP : public UAnimationModifier
{
	GENERATED_BODY()

public:
	virtual void OnApply_Implementation(UAnimSequence* AnimationSequence) override;

	UFUNCTION(BlueprintCallable)
	TArray<FAnimCurveCreationParams_CPP>& GetCurvesToCreate();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	UAnimSequence* AnimSequence;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FAnimCurveCreationParams_CPP CurveParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	TArray<FAnimCurveCreationParams_CPP> CurvesToCreate;
};
