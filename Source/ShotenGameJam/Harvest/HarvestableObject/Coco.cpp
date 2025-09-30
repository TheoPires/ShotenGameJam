// Fill out your copyright notice in the Description page of Project Settings.


#include "Coco.h"
#include "ShotenGameJam/ShotenGameJamCharacter.h"
#include "ShotenGameJam/Harvest/GatherableComponent.h"
#include "ShotenGameJam/Inventory/InventoryComponent.h"

// Sets default values
ACoco::ACoco()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Gatherable = CreateDefaultSubobject<UGatherableComponent>("Gatherable");

}

// Called when the game starts or when spawned
void ACoco::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(LifeSpan);
	
}

// Called every frame
void ACoco::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FText ACoco::GetInteractionText_Implementation() const
{
	return FText::FromString("Ramasser une coco");
}

void ACoco::Interact_Implementation(AActor* Interactor)
{
	if (Gatherable)
	{
		int32 Got = Gatherable->Gather(Interactor);

		AShotenGameJamCharacter* Character = Cast<AShotenGameJamCharacter>(Interactor);
		if (Character != nullptr && Character->Inventory != nullptr)
		{
			Character->Inventory->AddItem(FName("Coco"), Got);
		}
		K2_DestroyActor();
	}
}
