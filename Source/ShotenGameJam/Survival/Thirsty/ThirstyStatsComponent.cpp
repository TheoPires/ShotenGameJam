// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirstyStatsComponent.h"

UThirstyStatsComponent::UThirstyStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UThirstyStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		ThirstyTimerHandle,
		this,
		&UThirstyStatsComponent::DecreaseThirsty,
		ThirstyDecreaseRate,
		true);
}
void UThirstyStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

float UThirstyStatsComponent::GetThirstyPercent() const
{
	return (MaxThirsty > 0.0f) ? Thirsty / MaxThirsty : 0.0f;
}

void UThirstyStatsComponent::AddThirstyValue(const int& ThirstyValue)
{
	Thirsty += ThirstyValue;
	OnThristyUpdated.Broadcast(Thirsty, GetThirstyPercent());
}

void UThirstyStatsComponent::DecreaseThirsty()
{
	Thirsty = FMath::Clamp(Thirsty - ThirstyDecreaseAmount, 0.0f, MaxThirsty);
	
	OnThristyUpdated.Broadcast(Thirsty, GetThirstyPercent());
	
	if (Thirsty <= 0.0f)
	{
		OnThirstyDepleted();
		GetWorld()->GetTimerManager().ClearTimer(ThirstyTimerHandle);
	}
}