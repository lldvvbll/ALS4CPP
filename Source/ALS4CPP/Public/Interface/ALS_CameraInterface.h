

#pragma once

#include "ALS4CPP.h"
#include "UObject/Interface.h"
#include "ALS_CameraInterface.generated.h"

UINTERFACE(BlueprintType, Meta = (Blueprintable))
class UALS_CameraInterface : public UInterface
{
	GENERATED_BODY()
};

class ALS4CPP_API IALS_CameraInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CameraSystem")
	void GetCameraParameters(float& Out_TP_FOV, float& Out_FP_FOV, bool& Out_RightShoulder);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CameraSystem")
	void GetFpCameraTarget(FVector& Out_ReturnValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CameraSystem")
	void Get3pPivotTarget(FTransform& Out_ReturnValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "CameraSystem")
	void Get3pTraceParams(FVector& Out_TraceOrigin, float& Out_TraceRadius, TEnumAsByte<ETraceTypeQuery>& Out_TarceChannel);
};
