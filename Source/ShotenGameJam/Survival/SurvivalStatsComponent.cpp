// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalStatsComponent.h"

// Sets default values for this component's properties
USurvivalStatsComponent::USurvivalStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void USurvivalStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		HungerTimerHandle,
		this,
		&USurvivalStatsComponent::DecreaseHunger,
		HungerDecreaseRate,
		true);
}


// Called every frame
void USurvivalStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float USurvivalStatsComponent::GetHungerPercent() const
{
    return (MaxHunger > 0.0f) ? Hunger / MaxHunger : 0.0f;
}

void USurvivalStatsComponent::AddHungerValue(const int& HungerValue)
{
	Hunger += HungerValue;
	OnHungerUpdated.Broadcast(Hunger, GetHungerPercent());
}

void USurvivalStatsComponent::DecreaseHunger()
{
	Hunger = FMath::Clamp(Hunger - HungerDecreaseAmount, 0.0f, MaxHunger);
	
	float Return = GetHungerPercent();
	OnHungerUpdated.Broadcast(Hunger, Return);
	
	if (Hunger <= 0.0f)
	{
		OnHungerDepleted();
	}
}
