// Fill out your copyright notice in the Description page of Project Settings.


#include "GatherableComponent.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UGatherableComponent::UGatherableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGatherableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UGatherableComponent::Respawn()
{
	CurrentAmount = MaxAmount;
	GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHandle);
}

int32 UGatherableComponent::Gather(AActor* Interactor)
{
	if (CurrentAmount <= 0)
	{
		return 0;
	}

	FVector SpawnLocation = Interactor->GetActorLocation() + FVector(0,0,100); // exemple : au-dessus du perso
	FRotator SpawnRotation = FRotator::ZeroRotator;


	if (GatherVFX)
	{
		UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			GatherVFX,
			SpawnLocation,
			SpawnRotation,
			true
		);
	}

	if (GatherSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			this,
			GatherSound,
			Interactor->GetActorLocation()
		);
	}

	if (CurrentAmount == 0)
	{
		GetOwner()->SetActorHiddenInGame(true);

		GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &UGatherableComponent::Respawn, RespawnTimer, false);
	}
	--CurrentAmount;
	return FMath::RandRange(1, MaxItemGathered);
}


// Called every frame
void UGatherableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

