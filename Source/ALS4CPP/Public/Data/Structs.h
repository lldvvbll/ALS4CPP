

#pragma once

#include "ALS4CPP.h"
#include "Structs.generated.h"

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
