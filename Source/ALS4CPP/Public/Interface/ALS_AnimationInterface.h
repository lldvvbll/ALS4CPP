

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "Data/Enums.h"
#include "ALS_AnimationInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (Blueprintable))
class UALS_AnimationInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_AnimationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Jumped();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetGroundedEntryState(EGroundedEntryState_CPP GroundedEntryState);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetOverlayOverrideState(int OverlayOverrideState);
};
