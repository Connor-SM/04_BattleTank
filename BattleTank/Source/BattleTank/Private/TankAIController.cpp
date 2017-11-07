// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledAITank = GetAITank();

	if (!ControlledAITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't find controlled tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Possesing: %s"), *(ControlledAITank->GetName()));
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}