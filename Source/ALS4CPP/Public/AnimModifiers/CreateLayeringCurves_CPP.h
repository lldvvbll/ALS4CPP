

#pragma once

#include "ALS4CPP.h"
#include "AnimationModifier.h"
#include "Data/Structs.h"
#include "CreateLayeringCurves_CPP.generated.h"

UCLASS()
class ALS4CPP_API UCreateLayeringCurves_CPP : public UAnimationModifier
{
	GENERATED_BODY()

public:
	virtual void OnApply_Implementation(UAnimSequence* AnimationSequence) override;

	UFUNCTION(BlueprintCallable)
	TArray<FName>& GetCurvesToCreate();

	UFUNCTION(BlueprintCallable)
	float GetDefaultValue() const;

	UFUNCTION(BlueprintCallable)
	void SetDefaultValue(float NewValue);
		
	UFUNCTION(BlueprintCallable)
	bool IsKeyEachFrame() const;

	UFUNCTION(BlueprintCallable)
	void SetIsKeyEachFrame(bool IsKeyEachFrame);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	UAnimSequence* AnimSequence;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FName Curve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	TArray<FName> CurvesToCreate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	float DefaultValue = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	bool bKeyEachFrame = true;
};
