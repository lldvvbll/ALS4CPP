


#include "CharacterLogic/ALS_PlayerController_CPP.h"
#include "CameraSystem/ALS_PlayerCameraManager_CPP.h"
#include "CharacterLogic/ALS_BaseCharacter_CPP.h"
#include "Blueprint/UserWidget.h"
#include "EngineUtils.h"

AALS_PlayerController_CPP::AALS_PlayerController_CPP()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> ALS_HUD_CLASS(
		TEXT("/Game/AdvancedLocomotionV4/Blueprints/UI/ALS_HUD.ALS_HUD_C"));
	if (ALS_HUD_CLASS.Succeeded())
	{
		ALS_HudClass = ALS_HUD_CLASS.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> OVERLAY_SWITCHER_CLASS(
		TEXT("/Game/AdvancedLocomotionV4/Blueprints/UI/OverlayStateSwitcher.OverlayStateSwitcher_C"));
	if (OVERLAY_SWITCHER_CLASS.Succeeded())
	{
		OverlaySwitcherClass = OVERLAY_SWITCHER_CLASS.Class;
	}
}

void AALS_PlayerController_CPP::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	auto ALS_PlayerCameraManager = Cast< AALS_PlayerCameraManager_CPP>(PlayerCameraManager);
	if (ALS_PlayerCameraManager != nullptr)
	{
		ALS_PlayerCameraManager->OnPossess(aPawn);
	}
}

void AALS_PlayerController_CPP::BeginPlay()
{
	Super::BeginPlay();

	ALS_HUD = CreateWidget<UUserWidget>(this, ALS_HudClass);
	ALS_HUD->AddToViewport();

	for (const auto& Char : TActorRange<AALS_BaseCharacter_CPP>(GetWorld()))
	{
		AvailableDebugCharacters.Add(Char);
	}

	DebugFocusCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}
