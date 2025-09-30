// Fill out your copyright notice in the Description page of Project Settings.


#include "StrandedItemSpawner.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"

// Sets default values
AStrandedItemSpawner::AStrandedItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GatherablesSpawner = CreateDefaultSubobject<UBoxComponent>("GatherableSpawner");
	GatherablesSpawner->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AStrandedItemSpawner::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < 8; i++)
	{
		SpawnProba.Add(0);
	}
	for (int i = 0; i < 2; i++)
	{
		SpawnProba.Add(1);
	}
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &AStrandedItemSpawner::Spawn, DelayToSpawnAgain, true);
}

// Called every frame
void AStrandedItemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TSubclassOf<AActor> AStrandedItemSpawner::WhatToSpawn()
{
	int rand = FMath::RandRange(0, 9);
	switch (SpawnProba[rand])
	{
	case 0 :
		return BP_Actor0;
	case 1 :
		return BP_Actor1;
	default:
		break;
	}
	return NULL;
}

void AStrandedItemSpawner::Spawn() 
{
	UWorld* const World = GetWorld();
	if (World)
	{
		FVector SpawnerWorldLocation = GatherablesSpawner->GetComponentLocation();
		FVector SpawnerBoxExtent = GatherablesSpawner->GetScaledBoxExtent();
		FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(SpawnerWorldLocation, SpawnerBoxExtent);
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		FVector Downward = -(FVector::UpVector);

		float TraceDistance = 10000.0f;
		FVector TraceEnd = SpawnLocation + (Downward * TraceDistance);

		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		bool bHit = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			SpawnLocation,
			TraceEnd,
			ECollisionChannel::ECC_Visibility,
			CollisionParams
		);

		if (bHit)
		{	

			FRotator SpawnRotation;
			SpawnRotation.Yaw = FMath::FRand() * 360;
			SpawnRotation.Pitch = FMath::FRand() * 360;
			SpawnRotation.Roll = FMath::FRand() * 360;

			FTransform SpawnTransform;
			SpawnTransform.SetLocation(SpawnerWorldLocation);
			AActor* SpawnedActor = World->SpawnActor<AActor>(WhatToSpawn(), HitResult.Location + (FVector::UpVector * 100), SpawnRotation, SpawnParams);
		}
	}
}