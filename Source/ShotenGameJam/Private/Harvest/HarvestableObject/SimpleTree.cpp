// Fill out your copyright notice in the Description page of Project Settings.


#include "Harvest/HarvestableObject/SimpleTree.h"

// Sets default values
ASimpleTree::ASimpleTree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleTree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

