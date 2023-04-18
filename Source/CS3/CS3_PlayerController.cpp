// Fill out your copyright notice in the Description page of Project Settings.


#include "CS3_PlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"


void ACS3_PlayerController::BeginPlay()
{
    Super::BeginPlay();

    MenuUI = CreateWidget(this, MenuClass);

    if(BackgroundSound != nullptr)
    {
        UGameplayStatics::PlaySound2D(GetWorld(), BackgroundSound, 0.2f);
    }
    

    if(MenuUI != nullptr)
    {
        MenuUI->AddToViewport();
        UE_LOG(LogTemp, Warning, TEXT("Current map name: %s"), *GetWorld()->GetMapName());
    }

    if (GetWorld()->GetMapName() == "UEDPIE_0_Sandbox")
{
    UE_LOG(LogTemp, Warning, TEXT("Current map name: %s"), *GetWorld()->GetMapName());
    
    if (MenuUI != nullptr)
    {
        MenuUI->RemoveFromViewport();
    }
    
    FTimerHandle TimerHandle;
    GetWorldTimerManager().SetTimer(TimerHandle, [this]()
    {
        Hud = CreateWidget(this, HudClass);
        if (Hud != nullptr)
        {
            Hud->AddToViewport();
        }
    }, 20.0f, false);
}

    
}

void ACS3_PlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    if (GetWorld()->GetMapName() == "UEDPIE_0_Sandbox")
    {
        Hud->RemoveFromViewport();
    

    if(bIsWinner)
    {
        UUserWidget *WinScreen = CreateWidget(this, WinScreenClass);

        if(WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
            UE_LOG(LogTemp, Warning, TEXT("WinScreen added"));

        }

        GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, 20);
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);

        if(LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
            UE_LOG(LogTemp, Warning, TEXT("LoseScreen added"));
        }

        GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
    }  
    }
    
}

// void AShooterCharacter::OnPauseGame()
// {
// 	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
// 	if (PlayerController != nullptr)
// 	{
// 		PlayerController->bShowMouseCursor = true;
// 	}
	
// 	SetPause(true);
// 	SetInputMode(FInputModeUIOnly());
// 	UE_LOG(LogTemp, Warning, TEXT("Game has been paused"));
// }

// void AShooterCharacter::OnUnpauseGame()
// {
// 	SetPause(false);

// 	bShowMouseCursor = false;
// 	SetInputMode(FInputModeGameOnly());

// 	UE_LOG(LogTemp, Warning, TEXT("Game has been unpaused"));
// }

