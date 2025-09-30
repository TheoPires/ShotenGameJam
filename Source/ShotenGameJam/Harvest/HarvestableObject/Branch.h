// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShotenGameJam/Harvest/Harvestable.h"
#include "Branch.generated.h"

UCLASS()
class SHOTENGAMEJAM_API ABranch : public AActor,public IHarvestable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABranch();

	virtual void Interact_Implementation(AActor* Interactor) override;
	virtual FText GetInteractionText_Implementation() const override;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere)
	class UGatherableComponent* Gatherable = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 60.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
