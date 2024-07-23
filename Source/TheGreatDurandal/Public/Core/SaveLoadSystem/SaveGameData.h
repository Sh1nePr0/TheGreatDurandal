// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameData.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATDURANDAL_API USaveGameData : public USaveGame
{
	GENERATED_BODY()

public:

	USaveGameData();

	/** Amount of points that need to be save */
	UPROPERTY(VisibleAnywhere)
	int32 Points;
	
};
