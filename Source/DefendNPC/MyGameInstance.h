// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */

UENUM()
enum class EMyGameInstanceState : uint8
{
	MainMenu,
	SelectNetModeMenu,
	JoinServerMenu,
	Loading,
	Playing,
	InGameMenu,
	SettleMenu
};

UCLASS()
class DEFENDNPC_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UMG Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:

private:
	UPROPERTY()
	UUserWidget* CurrentWidget = nullptr;
};
