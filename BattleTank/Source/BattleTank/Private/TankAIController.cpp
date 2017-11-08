// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledAITank = GetAITank();
	auto HumanTank = GetPlayerTank();

	if (!HumanTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("I haven't found the player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("I've found player tank: %s"), *(HumanTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());

		// TODO Fire if ready
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}