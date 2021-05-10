

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "Data/Enums.h"
#include "ALS_AnimationInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (CannotImplementInterfaceInBlueprint))
class UALS_AnimationInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_AnimationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void Jumped() {}

	UFUNCTION(BlueprintCallable)
	virtual void SetGroundedEntryState(EGroundedEntryState_CPP GroundedEntryState) {}

	UFUNCTION(BlueprintCallable)
	virtual void SetOverlayOverrideState(int OverlayOverrideState) {}
};
