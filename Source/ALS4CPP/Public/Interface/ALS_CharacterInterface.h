

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "Data/Enums.h"
#include "ALS_CharacterInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (Blueprintable))
class UALS_CharacterInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_CharacterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterInformation")
	void GetCurrentStates(TEnumAsByte<EMovementMode>& Out_PawnMovementMode, EALS_MovementState_CPP& Out_MovementState,
		EALS_MovementState_CPP& Out_PrevMovementState, EALS_MovementAction_CPP& Out_MovementAction,
		EALS_RotationMode_CPP& Out_RotationMode, EALS_Gait_CPP& Out_ActualGait, EALS_Stance_CPP& Out_ActualStance,
		EALS_ViewMode_CPP& Out_ViewMode, EALS_OverlayState_CPP& Out_OverlayState);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterInformation")
	void GetEssentialValues(FVector& Out_Velocity, FVector& Out_Acceleration, FVector& Out_MovementInput,
		bool& Out_IsMoving, bool& Out_HasMovementInput, float& Out_Speed, float& Out_MovementInputAmount,
		FRotator& Out_AimingRotation, float& Out_AimYawRate);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterStates")
	void SetMovementState(EALS_MovementState_CPP NewMovementState);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterStates")
	void SetMovementAction(EALS_MovementAction_CPP NewMovementAction);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterStates")
	void SetRotationAction(EALS_RotationMode_CPP NewRotationMode);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterStates")
	void SetGait(EALS_Gait_CPP NewGait);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterStates")
	void SetViewMode(EALS_ViewMode_CPP NewViewMode);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CharacterStates")
	void SetOverlayState(EALS_OverlayState_CPP NewMovementAction);
};
