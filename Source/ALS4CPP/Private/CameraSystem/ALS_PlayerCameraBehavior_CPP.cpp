


#include "CameraSystem/ALS_PlayerCameraBehavior_CPP.h"
#include "CharacterLogic/ALS_Base_CharacterCPP.h"
#include "CharacterLogic/ALS_PlayerController_CPP.h"

void UALS_PlayerCameraBehavior_CPP::NativeUpdateAnimation(float DeltaSeconds)
{
	if (ControlledPawn != nullptr)
	{
		TEnumAsByte<EMovementMode> DummyMovementMode;
		EALS_MovementState_CPP DummyPrevMovementState = EALS_MovementState_CPP::None;
		EALS_OverlayState_CPP DummyOverlayState = EALS_OverlayState_CPP::Default;

		ControlledPawn->GetCurrentStates(DummyMovementMode, MovementState, 
			DummyPrevMovementState, MovementAction, RotationMode, Gait, Stance,
			ViewMode, DummyOverlayState);

		float Dummy = 0.0f;
		ControlledPawn->GetCameraParameters(Dummy, Dummy, RightShoulder);
	}

	if (PlayerController != nullptr)
	{
		ACharacter* DummyChar = nullptr;
		bool Dummy = false;

		PlayerController->GetDebugInfo(DummyChar, DebugView, Dummy, Dummy, Dummy, Dummy, Dummy, Dummy);
	}
}