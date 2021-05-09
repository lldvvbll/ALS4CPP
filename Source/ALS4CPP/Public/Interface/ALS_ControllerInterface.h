

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "ALS_ControllerInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (Blueprintable))
class UALS_ControllerInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_ControllerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Debug")
	void GetDebugInfo(ACharacter*& Out_DebugFocusCharacter, bool& Out_DebugView, bool& Out_ShowHUD,
		bool& Out_ShowTraces, bool& Out_ShowDebugShapes, bool& Out_ShowLayerColor, bool& Out_Slomo, bool& Out_ShowCharacterInfo);
};
