// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TowerShotgun.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATowerShotgun : public ABasePawn
{
	GENERATED_BODY()
	
public:	
	virtual void Tick(float DeltaTime) override;

	ATowerShotgun();

	void HandleDestruction();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SecondBarrel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ThirdBarrel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint2;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint3;

	void Fire()

	UPROPERTY(EditDefaultsOnly, Category = "Combat");
	float FireRange = 1000.f;
	UPROPERTY(EditDefaultsOnly, Category = "Combat");
	float FireRate = 3.f;
		
	FTimerHandle FireRateTimerHandle;

	void CheckFireCondition();

	bool InFireRange();
	
	class ATank* Tank;	
	
};
