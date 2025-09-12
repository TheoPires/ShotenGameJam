// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Harvestable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHarvestable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOTENGAMEJAM_API IHarvestable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Harvest")
	void Interact(AActor* Interactor);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Harvest")
	FText GetInteractionText() const;
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
};
