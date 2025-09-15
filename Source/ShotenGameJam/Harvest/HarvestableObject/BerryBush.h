// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShotenGameJam/Harvest/Harvestable.h"
#include "BerryBush.generated.h"

UCLASS()
class SHOTENGAMEJAM_API ABerryBush : public AActor, public IHarvestable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABerryBush();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(AActor* Interactor) override;
	virtual FText GetInteractionText_Implementation() const override;

	UFUNCTION()
	void VisibleBerries();
	void HiddenBerries();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere)
	USceneComponent* BerriesContainer = nullptr;
	
	UPROPERTY(EditAnywhere)
	class UGatherableComponent* Gatherable = nullptr;

	FTimerHandle RespawnBerriesTimerHandle;
	
	UPROPERTY(EditAnywhere)
	float DelayToRespawnBerries = 5.0f;

	bool bCanBeHarvest = true;
};
