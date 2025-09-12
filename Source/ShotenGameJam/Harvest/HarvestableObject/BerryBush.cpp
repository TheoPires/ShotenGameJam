// Fill out your copyright notice in the Description page of Project Settings.


#include "BerryBush.h"

#include "ShotenGameJam/ShotenGameJamCharacter.h"
#include "ShotenGameJam/Harvest/GatherableComponent.h"
#include "ShotenGameJam/Inventory/InventoryComponent.h"

// Sets default values
ABerryBush::ABerryBush()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ABerryBush::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABerryBush::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABerryBush::Interact(AActor* Interactor)
{
	if (Gatherable)
	{
		int32 Got = Gatherable->Gather(Interactor);

		AShotenGameJamCharacter* Character = Cast<AShotenGameJamCharacter>(Interactor);
		if (Character != nullptr && Character->Inventory != nullptr)
		{
			Character->Inventory->AddItem(FName("Berry"), Got);
		}
	}
}
