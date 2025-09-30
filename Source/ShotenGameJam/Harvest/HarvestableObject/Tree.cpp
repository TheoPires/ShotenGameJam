// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "ShotenGameJam/ShotenGameJamCharacter.h"
#include "ShotenGameJam/Harvest/GatherableComponent.h"
#include "ShotenGameJam/Inventory/InventoryComponent.h"

// Sets default values
ATree::ATree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	GatherablesSpawner = CreateDefaultSubobject<UBoxComponent>("GatherableSpawner");
	GatherablesSpawner->SetBoxExtent(FVector(300.f,300.f,40.f));
	GatherablesSpawner->SetupAttachment(GetRootComponent());
	GatherablesSpawner->SetRelativeLocation(FVector(0.f,0.f,450.f));
}

// Called when the game starts or when spawned
void ATree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATree::Drop()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		FVector SpawnerWorldLocation = GatherablesSpawner->GetComponentLocation();
		FVector SpawnerBoxExtent = GatherablesSpawner->GetScaledBoxExtent();
		FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(SpawnerWorldLocation, SpawnerBoxExtent);
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		FRotator SpawnRotation;
		SpawnRotation.Yaw = FMath::FRand() * 360;
		SpawnRotation.Pitch = FMath::FRand() * 360;
		SpawnRotation.Roll = FMath::FRand() * 360;

		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SpawnerWorldLocation);
		AActor* SpawnedActor = World->SpawnActor<AActor>(BP_Actor, SpawnLocation, SpawnRotation, SpawnParams);
	}
}


void ATree::ShakeTree()
{
	if (!TimerStarted)
	{
		GetWorldTimerManager().SetTimer(ReloadTreeSpawnableItem, this, &ATree::ReloadTree, DelayToDropAgain, false);
		TimerStarted = true;
	}
	
	if (CurrentSpawnedItem != MaxItemToSpawn) 
	{
		Drop();
		CurrentSpawnedItem += 1;
	}
	
}


void ATree::Interact_Implementation(AActor* Interactor)
{
	ShakeTree();
}

FText ATree::GetInteractionText_Implementation() const
{
	return FText::FromString("Secouer l'arbre");
}

void ATree::ReloadTree()
{
	if (CurrentSpawnedItem != 0) {
		CurrentSpawnedItem = 0;
		UE_LOG(LogTemp, Warning, TEXT("===== ReloadTree ====="));
	}
	TimerStarted = false;
}