// Fill out your copyright notice in the Description page of Project Settings.


#include "Maui.h"


// Sets default values
AMaui::AMaui()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	SetRootComponent(CapsuleComp);

	MauiFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("MauiFlipbook"));
	MauiFlipbook->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMaui::BeginPlay()
{
	Super::BeginPlay();
	
	CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AMaui::OverlapBegin);
}

// Called every frame
void AMaui::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (chase)
	{
		FVector playerPosition = playerToChase->GetActorLocation();
		FVector mauiPosition = GetActorLocation();
		FVector2D MovementDirection;

		float difX = playerPosition.X - mauiPosition.X;
		float difY = playerPosition.Z - mauiPosition.Z;

		if (difX > 0.0f)
			MovementDirection.X = 1.0f;
		else
			if(difX == 0.0f)
				MovementDirection.X = 0.0f;
			else
				MovementDirection.X = -1.0f;

		if (difY > 0.0f)
			MovementDirection.Y = 1.0f;
		else
			if (difY == 0.0f)
				MovementDirection.Y = 0.0f;
			else
				MovementDirection.Y = -1.0f;

		FVector2D DistanceToMove = MovementDirection * speed * DeltaTime;
		FVector NewLocation = mauiPosition + FVector(DistanceToMove.X, 0.0f, DistanceToMove.Y);
		SetActorLocation(NewLocation);
	}

}

void AMaui::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepRsult)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	if (Player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, TEXT("CHASE!!!!"));
		chase = true;
		playerToChase = Player;
	}
}


