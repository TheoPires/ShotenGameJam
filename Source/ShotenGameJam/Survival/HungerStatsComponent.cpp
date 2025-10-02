// Fill out your copyright notice in the Description page of Project Settings.


#include "HungerStatsComponent.h"

// Sets default values for this component's properties
UHungerStatsComponent::UHungerStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHungerStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		HungerTimerHandle,
		this,
		&UHungerStatsComponent::DecreaseHunger,
		HungerDecreaseRate,
		true);
}


// Called every frame
void UHungerStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UHungerStatsComponent::GetHungerPercent() const
{
    return (MaxHunger > 0.0f) ? Hunger / MaxHunger : 0.0f;
}

void UHungerStatsComponent::AddHungerValue(const int& HungerValue)
{
	Hunger += HungerValue;
	OnHungerUpdated.Broadcast(Hunger, GetHungerPercent());
}

void UHungerStatsComponent::DecreaseHunger()
{
	Hunger = FMath::Clamp(Hunger - HungerDecreaseAmount, 0.0f, MaxHunger);
	
	float Return = GetHungerPercent();
	OnHungerUpdated.Broadcast(Hunger, Return);
	
	if (Hunger <= 0.0f)
	{
		OnHungerDepleted();
	}
}
