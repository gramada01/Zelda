// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"
#include "PlayerCharacter.h"

#include "EmergencyRun.h"
#include <iostream>

#include "Maui.generated.h"

UCLASS()
class ZELDA_API AMaui : public AActor
{
	GENERATED_BODY()
private:
	bool chase = false;
	APlayerCharacter* playerToChase;
	
public:
	friend std::ostream& operator<<(std::ostream& out, const AMaui& maui) {
		out << "This is Maui\n";

		return out;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperFlipbookComponent* MauiFlipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 250.0f;

	// Sets default values for this actor's properties
	AMaui();

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepRsult);

};
