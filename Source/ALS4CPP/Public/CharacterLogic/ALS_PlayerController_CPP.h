

#pragma once

#include "ALS4CPP.h"
#include "GameFramework/PlayerController.h"
#include "Interface/ALS_ControllerInterface.h"
#include "ALS_PlayerController_CPP.generated.h"

class UUserWidget;

UCLASS()
class ALS4CPP_API AALS_PlayerController_CPP : public APlayerController, public IALS_ControllerInterface
{
	GENERATED_BODY()

public:
	AALS_PlayerController_CPP();

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	ACharacter* DebugFocusCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	TArray<ACharacter*> AvailableDebugCharacters;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	bool bShowHUD;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	bool bDebugView;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	bool bShowTraces;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	bool bShowDebugShapes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	bool bShowLayerColors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	bool bShowCharacterInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Debug, Meta = (AllowPrivateAccess = true))
	bool bSlomo;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	TSubclassOf<UUserWidget> ALS_HudClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	UUserWidget* ALS_HUD;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	TSubclassOf<UUserWidget> OverlaySwitcherClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	UUserWidget* OverlaySwitcher;
};
