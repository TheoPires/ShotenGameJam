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

	BerriesContainer = CreateDefaultSubobject<UStaticMeshComponent>("BerriesContainer");
	BerriesContainer->SetupAttachment(GetRootComponent());
	
	Gatherable = CreateDefaultSubobject<UGatherableComponent>("Gatherable");
}

void ABerryBush::HiddenBerries()
{
	bCanBeHarvest = false;
	BerriesContainer->SetVisibility(false, true);

	GetWorldTimerManager().SetTimer(RespawnBerriesTimerHandle, this, &ABerryBush::VisibleBerries, DelayToRespawnBerries, false);
}

// Called when the game starts or when spawned
void ABerryBush::BeginPlay()
{
	Super::BeginPlay();

	BerriesContainer->SetVisibility(true, true);
	
}

// Called every frame
void ABerryBush::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABerryBush::Interact_Implementation(AActor* Interactor)
{
	if (!bCanBeHarvest)
	{
		return;		
	}
	
	if (Gatherable)
	{
		int32 Got = Gatherable->Gather(Interactor);

		AShotenGameJamCharacter* Character = Cast<AShotenGameJamCharacter>(Interactor);
		if (Character != nullptr && Character->Inventory != nullptr)
		{
			Character->Inventory->AddItem(FName("Berry"), Got);
		}
	
		HiddenBerries();
	}
}

FText ABerryBush::GetInteractionText_Implementation() const
{
	return FText::FromString("Cueillir des baies");
}

void ABerryBush::VisibleBerries()
{
	bCanBeHarvest = true;
	GetWorldTimerManager().ClearTimer(RespawnBerriesTimerHandle);
	BerriesContainer->SetVisibility(true, true);
}
