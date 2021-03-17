

#pragma once

#include "ALS4CPP.h"
#include "GameFramework/Character.h"
#include "Interface/ALS_CharacterInterface.h"
#include "Interface/ALS_CameraInterface.h"
#include "ALS_Base_CharacterCPP.generated.h"

UCLASS()
class ALS4CPP_API AALS_Base_CharacterCPP : public ACharacter, public IALS_CharacterInterface, public IALS_CameraInterface
{
	GENERATED_BODY()


};
