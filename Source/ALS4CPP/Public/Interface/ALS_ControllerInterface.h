

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "ALS_ControllerInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (CannotImplementInterfaceInBlueprint))
class UALS_ControllerInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_ControllerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Debug")
	virtual void GetDebugInfo(UPARAM(ref) ACharacter*& DebugFocusCharacter, UPARAM(ref) bool& DebugView, UPARAM(ref) bool& ShowHUD,
		UPARAM(ref) bool& ShowTraces, UPARAM(ref) bool& ShowDebugShapes, UPARAM(ref) bool& ShowLayerColor, UPARAM(ref) bool& Slomo, UPARAM(ref) bool& ShowCharacterInfo) {}
};
