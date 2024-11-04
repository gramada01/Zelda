// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMyGameMode::ResetLevel(bool IsWin)
{
	float ResetTime = LoseResetTime;
	if (!IsWin)
	{
		GetWorldTimerManager().SetTimer(ResetGameTimer, this, &AMyGameMode::OnResetGameTimerTimeOut, 1.0f, false, ResetTime);
	}
	
}

void AMyGameMode::OnResetGameTimerTimeOut()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainLevel"));
}
