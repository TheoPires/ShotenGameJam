// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddItem(FName Id, int32 Quantity)
{
	Items.FindOrAdd(Id) += Quantity;

	DebugInventory();
}

void UInventoryComponent::DebugInventory()
{
	UE_LOG(LogTemp, Warning, TEXT("===== Inventaire ====="));

	for (auto& Elem : Items)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s : %d"), *Elem.Key.ToString(), Elem.Value);
	}

	UE_LOG(LogTemp, Warning, TEXT("====================="));
}
