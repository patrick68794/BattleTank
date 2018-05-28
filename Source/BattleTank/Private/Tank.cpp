// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"

float ATank::GetHealthPercent() const
{
	return currentHealth / startingHealth;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	currentHealth = startingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInvestgator, AActor* DamageCauser)
{
	auto DamageToApply = FMath::Clamp(DamageAmount, 0.0f, currentHealth);
	currentHealth -= DamageToApply;
	if (currentHealth <= 0.0f)
	{
		OnDeath.Broadcast();
	}

	return DamageToApply;
}