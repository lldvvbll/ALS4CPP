

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "ALS_CameraInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (CannotImplementInterfaceInBlueprint))
class UALS_CameraInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_CameraInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CameraSystem")
	virtual void GetCameraParameters(UPARAM(ref) float& TP_FOV, UPARAM(ref) float& FP_FOV, UPARAM(ref) bool& RightShoulder) {}

	UFUNCTION(BlueprintCallable, Category = "CameraSystem")
	virtual void GetFpCameraTarget(UPARAM(ref)FVector& ReturnValue) {}

	UFUNCTION(BlueprintCallable, Category = "CameraSystem")
	virtual void Get3pPivotTarget(UPARAM(ref)FTransform& ReturnValue) {}

	UFUNCTION(BlueprintCallable, Category = "CameraSystem")
	virtual void Get3pTraceParams(UPARAM(ref) FVector& TraceOrigin, UPARAM(ref) float& TraceRadius, UPARAM(ref) TEnumAsByte<ETraceTypeQuery>& TarceChannel) {}
};
