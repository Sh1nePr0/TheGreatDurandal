// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/DamageSystem/DamageComponent.h"

#include "Core/Character/TheGreatDurandalCharacter.h"
#include "Core/HealthSystem/HealthComponent.h"


// Sets default values for this component's properties
UDamageComponent::UDamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Damage = 25.0f;
}

// Called when the game starts
void UDamageComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UDamageComponent::CauseDamage()
{
	ATheGreatDurandalCharacter* Character = Cast<ATheGreatDurandalCharacter>(GetOwner());
	if(Character != nullptr)
	{
		Character->GetHealthComponent()->OnTakeDamage.Broadcast(Damage);
	}
}


