// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (ensure(PlayerTank))
	{
		// TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in centimeters

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fires every frame
		ControlledTank->Fire(); // TODO Limit firing rate
	}
}