// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThirstyStatsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnThirstyUpdated, float, HungerValue, float, HungerPercentage);

/**
 * 
 */
UCLASS()
class SHOTENGAMEJAM_API UThirstyStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UThirstyStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category="Survival|Stats")
	float GetThirstyPercent() const;

	void AddThirstyValue(const int& ThirstyValue);
	
	UPROPERTY(BlueprintAssignable, Category="Survival|Stats")
	FOnThirstyUpdated OnThristyUpdated;

	UFUNCTION(BlueprintImplementableEvent, Category="Survival|Thirsty")
	void OnThirstyDepleted();

private:

	UFUNCTION()
	void DecreaseThirsty();
	
private:

	FTimerHandle ThirstyTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Survival|Thirsty")
	float MaxThirsty = 100.0f;

	UPROPERTY()
	float Thirsty = MaxThirsty;

	UPROPERTY(EditAnywhere, Category = "Survival|Thirsty")
	float ThirstyDecreaseAmount = 20.0f;

	UPROPERTY(EditAnywhere, Category = "Survival|Thirsty")
	float ThirstyDecreaseRate = 5.0f;
};
