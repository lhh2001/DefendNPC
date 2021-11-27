// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void UMyGameInstance::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}

		// 当前需要显示鼠标
		APlayerController* PlayerController =
			UGameplayStatics::GetPlayerController(GWorld, 0);
		PlayerController->bShowMouseCursor = true;
		PlayerController->SetInputMode(FInputModeUIOnly());
	}
	else // 当前不需要显示菜单, 隐藏鼠标
	{
		APlayerController* PlayerController =
			UGameplayStatics::GetPlayerController(GWorld, 0);
		PlayerController->bShowMouseCursor = false;
		PlayerController->SetInputMode(FInputModeGameOnly());
	}
}
