// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SurvivalStatsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHungerUpdated, float, HungerValue, float, HungerPercentage);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOTENGAMEJAM_API USurvivalStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USurvivalStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintImplementableEvent, Category="Survival|Hunger")
	void OnHungerDepleted();

	UFUNCTION(BlueprintPure, Category="Survival|Stats")
	float GetHungerPercent() const;

	void AddHungerValue(const int& HungerValue);

	UPROPERTY(BlueprintAssignable, Category="Survival|Stats")
	FOnHungerUpdated OnHungerUpdated;
	
private:

	UFUNCTION()
	void DecreaseHunger();
	
private:

	FTimerHandle HungerTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Survival|Hunger")
	float MaxHunger = 100.0f;

	UPROPERTY()
	float Hunger = MaxHunger;

	UPROPERTY(EditAnywhere, Category = "Survival|Hunger")
	float HungerDecreaseAmount = 20.0f;

	UPROPERTY(EditAnywhere, Category = "Survival|Hunger")
	float HungerDecreaseRate = 5.0f;

};
