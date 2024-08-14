// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/HealthSystem/HealthComponent.h"

#include "Core/Character/TheGreatDurandalCharacter.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	DefaultHealth = 100.0f;
	Health = DefaultHealth;

	OnTakeDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UHealthComponent::TakeDamage(float Damage)
{
	if(Damage <= 0)
	{
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
		
}


