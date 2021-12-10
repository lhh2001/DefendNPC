// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFrameWork/PlayerController.h"
#include "AIController.h"
#include "GameFramework/GameModeBase.h"
#include "DefendNPCGameMode.generated.h"

UCLASS(minimalapi)
class ADefendNPCGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADefendNPCGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
	uint8 MaxPlayerNum;

	UFUNCTION(BlueprintImplementableEvent)
	void RespawnCharacterEvent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	void RespawnCharacter(APlayerController* PlayerController);
	
	UFUNCTION(BlueprintImplementableEvent)
	void RespawnAICharacterEvent(AAIController* AIController);

	UFUNCTION(BlueprintCallable)
	void RespawnAICharacter(AAIController* AIController);
};
