// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ToonTanksHUD.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksHUD : public AHUD
{
	GENERATED_BODY()

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	//Called on Damage Taken
	void SetHealthHUD(float Health);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealthHUD(float CurrentHealth);
	
	float HealthHUD = 0.f;

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

private:
	//class ATank* Tank;

	
};
