// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DurandalGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class THEGREATDURANDAL_API UDurandalGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UDurandalGameInstance();

	virtual void Init() override;

	/** Create new save file */
	void CreateSaveFile();

	/** Save the game */
	void SaveGame();

	/** Load the game */
	void LoadGame();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int32 totalPoints;
};
