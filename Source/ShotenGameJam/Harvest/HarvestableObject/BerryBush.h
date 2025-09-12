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

	virtual void Interact(AActor* Interactor);
	virtual FText GetInteractionText() const { return FText::FromString("Cueillir des baies"); }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(EditAnywhere)
	class UGatherableComponent* Gatherable;
};
