// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	UFUNCTION(BlueprintPure)
	bool IsSwappingWeapons() const;

	UFUNCTION(BlueprintPure)
	bool IsReloading() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	void Shoot();
	void Reload();


private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	void SwitchGuns(float Slot);

	void StartReload();
	
	UPROPERTY(EditAnywhere)
	float RotationRate = 50;

	UPROPERTY(EditAnywhere)
	float SwapDelay = .5f;
	
	FTimerHandle SwapTimer;

	UPROPERTY(EditAnywhere)
	float ReloadDuration = 1.2f;

	FTimerHandle ReloadTimer;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 150.f;

	UPROPERTY(VisibleAnywhere)
	float Health = 100.f;

	UPROPERTY(EditDefaultsOnly)
	int ActiveGunIndex = 0;

	UPROPERTY(EditAnywhere)
	int TotalGuns = 0;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass[3];

	UPROPERTY()
	AGun* Gun[3];
	
};
