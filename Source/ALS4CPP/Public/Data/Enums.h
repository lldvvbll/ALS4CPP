

#pragma once

#include "ALS4CPP.h"
#include "Enums.generated.h"

UENUM(BlueprintType)
enum class EALS_Gait_CPP : uint8
{
	Walking,
	Running,
	Sprinting,
};

UENUM(BlueprintType)
enum class EALS_MovementAction_CPP : uint8
{
	None,
	LowMantle,
	HightMantle,
	Rolling,
	GettingUp,
};

UENUM(BlueprintType)
enum class EALS_MovementState_CPP : uint8
{
	None,
	Grounded,
	InAir,
	Mantling,
	Ragdoll,
};

UENUM(BlueprintType)
enum class EALS_OverlayState_CPP : uint8
{
	Default,
	Masculine,
	Feminine,
	Injured,
	HandsTied,
	Rifle,
	Pistol1H,
	Pistol2H,
	Bow,
	Torch,
	Binoculars,
	Box,
	Barrel,
};

UENUM(BlueprintType)
enum class EALS_RotationMode_CPP : uint8
{
	VelocityDirection,
	LookingDirection,
	Aiming,
};

UENUM(BlueprintType)
enum class EALS_Stance_CPP : uint8
{
	Standing,
	Crouching,
};

UENUM(BlueprintType)
enum class EALS_ViewMode_CPP : uint8
{
	ThirdPerson,
	FirstPerson,
};

UENUM(BlueprintType)
enum class EAnimFeatureExample_CPP : uint8
{
	StrideBlending,
	AdditiveLeaning,
	SprintImpulse,
};

UENUM(BlueprintType)
enum class EFootstepType_CPP : uint8
{
	Step,
	Walk_Run,
	Jump,
	Land,
};

UENUM(BlueprintType)
enum class EGroundedEntryState_CPP : uint8
{
	None,
	Roll,
};

UENUM(BlueprintType)
enum class EHipsDirection_CPP : uint8
{
	F,
	B,
	RF,
	RB,
	LF,
	LB,
};

UENUM(BlueprintType)
enum class EMantleType_CPP : uint8
{
	HighMantle,
	LowMantle,
	FallingCatch,
};

UENUM(BlueprintType)
enum class EMovementDirection_CPP : uint8
{
	Forward,
	Right,
	Left,
	Backward,
};
