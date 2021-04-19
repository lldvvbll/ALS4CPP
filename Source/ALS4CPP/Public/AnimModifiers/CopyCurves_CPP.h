

#pragma once

#include "ALS4CPP.h"
#include "AnimationModifier.h"
#include "CopyCurves_CPP.generated.h"

UCLASS()
class ALS4CPP_API UCopyCurves_CPP : public UAnimationModifier
{
	GENERATED_BODY()

public:
	virtual void OnApply_Implementation(UAnimSequence* AnimationSequence) override;

	UFUNCTION(BlueprintCallable)
	UAnimSequence* GetAnimToCopyFrom() const;

	UFUNCTION(BlueprintCallable)
	void SetAnimToCopyFrom(UAnimSequence* NewAnim);

	UFUNCTION(BlueprintCallable)
	bool IsCopyAllCurves() const;

	UFUNCTION(BlueprintCallable)
	void SetIsCopyAllCurves(bool IsCopyAllCurves);

	UFUNCTION(BlueprintCallable)
	TArray<FName>& GetCurvesToCopy();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	UAnimSequence* AnimSequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	UAnimSequence* AnimToCopyFrom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	bool bCopyAllCurves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	TArray<FName> CurvesToCopy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FName CurveName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	TArray<FName> AllCurves;
};
