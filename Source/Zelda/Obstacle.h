// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "MyGameMode.h"
#include <iostream>

#include "Obstacle.generated.h"

UCLASS()
class ZELDA_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	

	friend std::ostream& operator<<(std::ostream& out, const AObstacle& run) {
		out <<"This is an Obstacle\n";

		return out;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* ObstacleSprite;

	AMyGameMode* MyGameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsWall = false;

	// Sets default values for this actor's properties
	AObstacle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepRsult);



};
