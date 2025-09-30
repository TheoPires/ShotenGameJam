// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Branch.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ShotenGameJam/Harvest/Harvestable.h"
#include "Tree.generated.h"

UCLASS()
class SHOTENGAMEJAM_API ATree : public AActor, public IHarvestable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATree();

	virtual void Interact_Implementation(AActor* Interactor) override;
	virtual FText GetInteractionText_Implementation() const override;

	UFUNCTION()
	void ShakeTree();
	UFUNCTION()
	void Drop();
	UFUNCTION()
	void ReloadTree();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> BP_Actor;
	UPROPERTY(EditDefaultsOnly)
	int MaxItemToSpawn = 3;
	UPROPERTY(EditAnywhere)
	int CurrentSpawnedItem = 0;
	UPROPERTY(EditAnywhere)
	float DelayToDropAgain = 90.f;

	FTimerHandle ReloadTreeSpawnableItem;
	bool TimerStarted = false;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* GatherablesSpawner = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
