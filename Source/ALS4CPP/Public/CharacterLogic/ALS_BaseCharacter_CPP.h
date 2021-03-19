

#pragma once

#include "ALS4CPP.h"
#include "GameFramework/Character.h"
#include "Interface/ALS_CharacterInterface.h"
#include "Interface/ALS_CameraInterface.h"
#include "ALS_BaseCharacter_CPP.generated.h"

UCLASS()
class ALS4CPP_API AALS_BaseCharacter_CPP : public ACharacter, public IALS_CharacterInterface, public IALS_CameraInterface
{
	GENERATED_BODY()


};
