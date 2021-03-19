


#include "CharacterLogic/ALS_PlayerController_CPP.h"
#include "CameraSystem/ALS_PlayerCameraManager_CPP.h"

void AALS_PlayerController_CPP::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	auto ALS_PlayerCameraManager = Cast< AALS_PlayerCameraManager_CPP>(PlayerCameraManager);
	if (ALS_PlayerCameraManager != nullptr)
	{
		ALS_PlayerCameraManager->OnPossess(aPawn);
	}
}