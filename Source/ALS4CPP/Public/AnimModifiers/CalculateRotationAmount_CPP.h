

#pragma once

#include "ALS4CPP.h"
#include "AnimationModifier.h"
#include "CalculateRotationAmount_CPP.generated.h"

UCLASS()
class ALS4CPP_API UCalculateRotationAmount_CPP : public UAnimationModifier
{
	GENERATED_BODY()
	
public:
	virtual void OnApply_Implementation(UAnimSequence* AnimationSequence) override;

	UFUNCTION(BlueprintCallable)
	FName GetCurveName() const;

	UFUNCTION(BlueprintCallable)
	void SetCurveName(const FName& NewCurveName);

	UFUNCTION(BlueprintCallable)
	FName GetRootBoneName() const;

	UFUNCTION(BlueprintCallable)
	void SetRootBoneName(const FName& NewRootBoneName);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	UAnimSequence* AnimSequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FName CurveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FName RootBoneName;
};
