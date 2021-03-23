

#pragma once

#include "ALS4CPP.h"
#include "Structs.generated.h"

USTRUCT(BlueprintType)
struct FAnimCurveCreationData_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	int32 FrameNumber;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float CurveValue;
};

USTRUCT(BlueprintType)
struct FAnimCurveCreateParams_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FName CurveName;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	bool KeyEachFrame;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	TArray<FAnimCurveCreationData_CPP> Keys;
};

USTRUCT(BlueprintType)
struct FALS_ComponentAndTransform_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FTransform Transform;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UPrimitiveComponent* Component;
};

USTRUCT(BlueprintType)
struct FCameraSettings_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float TargetArmLength;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FVector SocketOffset;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float LagSpeed;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float RotationLagSpeed;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	bool DoCollisionTest = true;
};

USTRUCT(BlueprintType)
struct FCameraSettings_Gait_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FCameraSettings_CPP Walking;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FCameraSettings_CPP Runnig;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FCameraSettings_CPP Sprinting;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FCameraSettings_CPP Crouching;
};

USTRUCT(BlueprintType)
struct FCameraSettings_State_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FCameraSettings_Gait_CPP VelocityDirection;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FCameraSettings_Gait_CPP LookingDirection;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FCameraSettings_Gait_CPP Aiming;
};

USTRUCT(BlueprintType)
struct FDynamicMontageParams_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UAnimSequenceBase* Animation;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float BlendInTime;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float BlendOutTime;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float PlayRate;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float StartTime;
};

USTRUCT(BlueprintType)
struct FLeanAmount_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float LR;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float FB;
};

USTRUCT(BlueprintType)
struct FMantle_Asset_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UAnimMontage* AnimMontage;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UCurveVector* PositionCorrectionCurve;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FVector StartingOffset;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float LowHeight;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float LowPlayRate;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float LowStartPosition;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float HighHeight;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float HighPlayRate;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float HighStartPosition;
};

USTRUCT(BlueprintType)
struct FMantle_Params_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UAnimMontage* AnimMontage;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UCurveVector* PositionCorrectionCurve;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float StartingPosition;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float PlayRate;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FVector StartingOffset;
};

USTRUCT(BlueprintType)
struct FMantle_TraceSettings_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float MaxLedgeHeight;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float MinLedgeHeight;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float ReachDistance;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float ForwardTraceRadius;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float DownwardTraceRadius;
};

USTRUCT(BlueprintType)
struct FMovementSettings_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float WalkSpeed;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float RunSpeed;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float SprintSpeed;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UCurveVector* MovementCurve;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UCurveFloat* RotationRateCurve;
};

USTRUCT(BlueprintType)
struct FMovementSettings_Stance_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FMovementSettings_CPP Standing;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FMovementSettings_CPP Crouching;
};

USTRUCT(BlueprintType)
struct FMovementSettings_State_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FMovementSettings_Stance_CPP VelocityDirection;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FMovementSettings_Stance_CPP LookingDirection;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FMovementSettings_Stance_CPP Aiming;
};

USTRUCT(BlueprintType)
struct FRotateInPlayce_Asset_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UAnimSequenceBase* Animation;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FName SlotName;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float SlowTurnRate;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float FastTurnRate;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float SlowPlayRate;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float FastPlayRate;
};

USTRUCT(BlueprintType)
struct FTurnInPlace_Asset_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	UAnimSequenceBase* Animation;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float AnimatedAngle;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	FName SlotName;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float PlayRate = 1.0f;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	bool ScaleTurnAngle = true;
};

USTRUCT(BlueprintType)
struct FVelocityBlend_CPP
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float F;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float B;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float L;

	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite)
	float R;
};
