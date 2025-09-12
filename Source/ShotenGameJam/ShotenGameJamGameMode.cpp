// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShotenGameJamGameMode.h"
#include "ShotenGameJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShotenGameJamGameMode::AShotenGameJamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
