// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageProperties.h"
#include "DamageComponent.generated.h"



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class THEGREATDURANDAL_API UDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDamageComponent();

	//First iteration on this function that just broadcast delegate
	//TODO: This logic in damage system
	UFUNCTION(BlueprintCallable)
	void CauseDamage();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	float Damage;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="Damage")
	EDamageType DamageType = EDamageType::NonDamageType;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="Damage")
	EDamageFrequency DamageFrequency = EDamageFrequency::NonDamageFrequency;
	
};
