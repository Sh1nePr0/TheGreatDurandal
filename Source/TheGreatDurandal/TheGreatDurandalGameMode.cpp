// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheGreatDurandalGameMode.h"
#include "Core/Character/TheGreatDurandalCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATheGreatDurandalGameMode::ATheGreatDurandalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
