// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "StrandedItemSpawner.generated.h"

UCLASS()
class SHOTENGAMEJAM_API AStrandedItemSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrandedItemSpawner();
	UPROPERTY(EditAnywhere)
	class UBoxComponent* GatherablesSpawner = nullptr;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> BP_Actor0;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> BP_Actor1;
	UPROPERTY(EditAnywhere)
	float DelayToSpawnAgain = 5.f;
	UPROPERTY(EditAnywhere)
	int MaxSpawnItemNb = 4;
	FTimerHandle RespawnTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TArray<int> SpawnProba;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void Spawn();
	TSubclassOf<AActor> WhatToSpawn();
};
