

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "Data/Enums.h"
#include "ALS_CharacterInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (CannotImplementInterfaceInBlueprint))
class UALS_CharacterInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_CharacterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CharacterInformation")
	virtual void GetCurrentStates(UPARAM(ref) TEnumAsByte<EMovementMode>& PawnMovementMode, UPARAM(ref) EALS_MovementState_CPP& MovementState,
		UPARAM(ref) EALS_MovementState_CPP& PrevMovementState, UPARAM(ref) EALS_MovementAction_CPP& MovementAction,
		UPARAM(ref) EALS_RotationMode_CPP& RotationMode, UPARAM(ref) EALS_Gait_CPP& ActualGait, UPARAM(ref) EALS_Stance_CPP& ActualStance,
		UPARAM(ref) EALS_ViewMode_CPP& ViewMode, UPARAM(ref) EALS_OverlayState_CPP& OverlayState) {}

	UFUNCTION(BlueprintCallable, Category = "CharacterInformation")
	virtual void GetEssentialValues(UPARAM(ref) FVector& Velocity, UPARAM(ref) FVector& Acceleration, UPARAM(ref) FVector& MovementInput,
		UPARAM(ref) bool& IsMoving, UPARAM(ref) bool& HasMovementInput, UPARAM(ref) float& Speed, UPARAM(ref) float& MovementInputAmount,
		UPARAM(ref) FRotator& AimingRotation, UPARAM(ref) float& AimYawRate) {}

	UFUNCTION(BlueprintCallable, Category = "CharacterStates")
	virtual void SetMovementState(EALS_MovementState_CPP NewMovementState) {}

	UFUNCTION(BlueprintCallable, Category = "CharacterStates")
	virtual void SetMovementAction(EALS_MovementAction_CPP NewMovementAction) {}

	UFUNCTION(BlueprintCallable, Category = "CharacterStates")
	virtual void SetRotationAction(EALS_RotationMode_CPP NewRotationMode) {}

	UFUNCTION(BlueprintCallable, Category = "CharacterStates")
	virtual void SetGait(EALS_Gait_CPP NewGait) {}

	UFUNCTION(BlueprintCallable, Category = "CharacterStates")
	virtual void SetViewMode(EALS_ViewMode_CPP NewViewMode) {}

	UFUNCTION(BlueprintCallable, Category = "CharacterStates")
	virtual void SetOverlayState(EALS_OverlayState_CPP NewMovementAction) {}
};
