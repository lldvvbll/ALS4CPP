

#pragma once

#include "ALS4CPP.h"
#include "Animation/AnimInstance.h"
#include "Data/Enums.h"
#include "ALS_PlayerCameraBehavior_CPP.generated.h"

class AALS_Player_Controller_CPP;
class AALS_Base_CharacterCPP;

UCLASS()
class ALS4CPP_API UALS_PlayerCameraBehavior_CPP : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Reference, Meta = (AllowPrivateAccess = true))
	AALS_Player_Controller_CPP* PlayerController;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Reference, Meta = (AllowPrivateAccess = true))
	AALS_Base_CharacterCPP* ControlledPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	EALS_MovementState_CPP MovementState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	EALS_MovementAction_CPP MovementAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	EALS_RotationMode_CPP RotationMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	EALS_Gait_CPP Gait;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	EALS_Stance_CPP Stance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	EALS_ViewMode_CPP ViewMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	bool RightShoulder;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = CharacterInfo, Meta = (AllowPrivateAccess = true))
	bool DebugView;
};
