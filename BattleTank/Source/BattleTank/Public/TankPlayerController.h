// Copyright Sports Mogul, Inc.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"	// Must be the last include

// Forward Declaration
class ATank;
class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	// Start the tnak moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT paramater, true if hit landscape
	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookDirection(FVector2D, FVector&) const;

	bool GetLookVectorHitLocation(FVector, FVector&) const;


	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;
};
