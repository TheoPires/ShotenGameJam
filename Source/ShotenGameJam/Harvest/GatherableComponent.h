// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GatherableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOTENGAMEJAM_API UGatherableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGatherableComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	int32 Gather(AActor* Interactor);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void Respawn();
	
public:
	
	UPROPERTY(EditAnywhere)
	FText DisplayName;

	UPROPERTY(EditAnywhere)
	FName ItemId = "DefaultItem";

	UPROPERTY(EditAnywhere)
	int32 MaxItemGathered = 3;
	
	UPROPERTY(EditAnywhere)
	int32 MaxAmount = 3;

	UPROPERTY(EditAnywhere)
	int32 CurrentAmount = 3;

	UPROPERTY(EditAnywhere)
	float RespawnTimer = 30.f;

	UPROPERTY(EditAnywhere)
	USoundBase* GatherSound;

	UPROPERTY(EditAnywhere)
	UAnimMontage* GatherAnim;

	UPROPERTY(EditAnywhere)
	UParticleSystem* GatherVFX;

	FTimerHandle RespawnTimerHandle;
};
