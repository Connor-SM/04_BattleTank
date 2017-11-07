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

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}