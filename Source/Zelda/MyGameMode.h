// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Engine/TimerHandle.h"
#include <iostream>

#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ZELDA_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	friend std::ostream& operator<<(std::ostream& out, const AMyGameMode& gm) {
		out <<"This is MyGameMode\n";

		return out;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoseResetTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WinResetTime = 3.0f;

	FTimerHandle ResetGameTimer;

	void ResetLevel(bool IsWin);
	void OnResetGameTimerTimeOut();
	
};
