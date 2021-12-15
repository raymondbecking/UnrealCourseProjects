// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TowerSniper.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATowerSniper : public ABasePawn
{
	GENERATED_BODY()

public:
	
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:	
	UPROPERTY(EditDefaultsOnly, Category = "Combat");
	float FireRange = 4000.f;
	UPROPERTY(EditDefaultsOnly, Category = "Combat");
	float FireRate = 4.f;
		
	FTimerHandle FireRateTimerHandle;

	void CheckFireCondition();

	bool InFireRange();
	
	class ATank* Tank;	
	
};
