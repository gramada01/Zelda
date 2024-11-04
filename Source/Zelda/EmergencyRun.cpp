#include "EmergencyRun.h"
#include <Math/MathFwd.h>
#include <stdlib.h>

EmergencyRun::~EmergencyRun()
{
}

void EmergencyRun::doStep(float deltaTime)const
{
	if (_currentStep == 0)
		return;

	FVector2D movementDirection;

	srand(time(NULL));

	int plusOrMinus = rand() % 2;
	if (plusOrMinus == 0)
		movementDirection.X = rand() % 3 ;
	else
		movementDirection.X = -rand() % 3 ;

	plusOrMinus = rand() % 2;
	if (plusOrMinus == 0)
		movementDirection.Y = rand() % 3 ;
	else
		movementDirection.Y = -rand() % 3 ;

	auto distanceToMove = movementDirection * _speed * deltaTime;
	auto currentLocation = _pawn->GetActorLocation();
	auto newLocation = currentLocation + FVector(distanceToMove.X, 0.0f, distanceToMove.Y);
	_pawn->SetActorLocation(newLocation);
	--_currentStep;
}

