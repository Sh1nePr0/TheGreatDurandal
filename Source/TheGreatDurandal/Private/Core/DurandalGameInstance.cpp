// Fill out your copyright notice in the Description page of Project Settings.


#include "TheGreatDurandal/Public/Core/DurandalGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TheGreatDurandal/Public/Core/SaveLoadSystem/SaveGameData.h"

UDurandalGameInstance::UDurandalGameInstance()
{
	totalPoints = 0;
}

void UDurandalGameInstance::Init()
{
	Super::Init();

	//Load the game upon initializing DurandalGameInstance
	LoadGame();
}

void UDurandalGameInstance::CreateSaveFile()
{
	//Create a SaveGame object and save to the default slot
	USaveGameData* dataToSave = Cast<USaveGameData>(
		UGameplayStatics::CreateSaveGameObject(
			USaveGameData::StaticClass()));
	UGameplayStatics::SaveGameToSlot(dataToSave, "Slot1", 0);
}

void UDurandalGameInstance::SaveGame()
{
	//Init data to save
	USaveGameData* dataToSave = Cast<USaveGameData>(
		UGameplayStatics::LoadGameFromSlot("Slot1", 0));

	//If there is valid SaveGame object to use for saving
	if(dataToSave != nullptr)
	{
		dataToSave->Points = totalPoints;
		UGameplayStatics::SaveGameToSlot(dataToSave,"Slot1", 0);
	}
	else if(!UGameplayStatics::DoesSaveGameExist("Slot1", 0))
	{
		//Create a default save file since
		CreateSaveFile();
	}
	
}

void UDurandalGameInstance::LoadGame()
{
	//Retrieve data to load
	USaveGameData* dataToLoad = Cast<USaveGameData>(UGameplayStatics::LoadGameFromSlot("Slot1", 0));

	//If there is valid data to load
	if(dataToLoad != nullptr)
	{
		totalPoints = dataToLoad->Points;
	}
	else if(!UGameplayStatics::DoesSaveGameExist("Slot1", 0))
	{
		//Create default save file since
		CreateSaveFile();
	}
	
}
