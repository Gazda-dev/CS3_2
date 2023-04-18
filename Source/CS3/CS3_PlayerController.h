// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CS3_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CS3_API ACS3_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void GameHasEnded(class AActor *EndGameFocus = nullptr, bool bIsWinner = false) override;	

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;

	UPROPERTY(EditAnywhere)
	float RestartDelay = 5;	

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HudClass;

	UPROPERTY()
	UUserWidget* Hud;

	UPROPERTY()
	UUserWidget* MenuUI;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> MenuClass;

	FTimerHandle RestartTimer;

	UPROPERTY(EditAnywhere)
	USoundBase* BackgroundSound;

	// UFUNCTION(BlueprintCallable, Category = "Gameplay")
	// void OnPauseGame();

	// UFUNCTION(BlueprintCallable, Category = "Gameplay")
	// void OnUnpauseGame();
};
