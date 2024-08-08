#pragma once

#include "CoreMinimal.h"

#include "DamageProperties.generated.h"


UENUM(BlueprintType)
enum class EDamageType: uint8
{
	DT_PHYSICAL		UMETA(DisplayName="Physical"),
	DT_MAGICAL		UMETA(DisplayName="Magical"),
	DT_POIZON		UMETA(DisplayName="Poizon"),
	DT_FIRE			UMETA(DisplayName="Fire"),
	NonDamageType	UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EDamageFrequency: uint8
{
	DF_INSTANTANEOUS		UMETA(DisplayName="Insta"),
	DF_PERIODIC				UMETA(DisplayName="Periodic"),
	NonDamageFrequency		UMETA(Hidden)
};