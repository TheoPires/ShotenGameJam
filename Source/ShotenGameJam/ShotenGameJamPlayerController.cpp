// Copyright Epic Games, Inc. All Rights Reserved.


#include "ShotenGameJamPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LocalPlayer.h"

void AShotenGameJamPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	if (SurvivalUIClass)
	{
		UUserWidget* UI = CreateWidget<UUserWidget>(this, SurvivalUIClass);
		if (UI)
		{
			UI->AddToViewport();
		}
	}
}