// Copyright Epic Games, Inc. All Rights Reserved.

#include "DefendNPCGameMode.h"
#include "DefendNPCCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADefendNPCGameMode::ADefendNPCGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Ue4ASP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADefendNPCGameMode::RespawnCharacter(APlayerController* PlayerController)
{
	RespawnCharacterEvent(PlayerController);
}

void ADefendNPCGameMode::RespawnAICharacter(AAIController* AIController)
{
	RespawnAICharacterEvent(AIController);
}
