

#pragma once

#include "ALS4CPP.h"
#include "GameFramework/PlayerController.h"
#include "Interface/ALS_ControllerInterface.h"
#include "ALS_PlayerController_CPP.generated.h"

UCLASS()
class ALS4CPP_API AALS_PlayerController_CPP : public APlayerController, public IALS_ControllerInterface
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* aPawn) override;

};
