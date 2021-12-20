// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"
#include "Math/UnrealMathUtility.h"
#include "TimerManager.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;
	
	//Disable default connected weapon mesh
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	
	ActiveGunIndex = 0;
	//Spawn & Attach all guns and hide them ingame
	for(int Index = 0; Index < 3; Index++)
	{
		//Spawn each gun
		Gun[Index] = GetWorld()->SpawnActor<AGun>(GunClass[Index]);

		if(Gun[Index])
		{
			Gun[Index]->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
			Gun[Index]->SetOwner(this);

			//Hide all weapons except the active weapon
			if(Index != ActiveGunIndex)
			{				
				Gun[Index]->SetActorHiddenInGame(true);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Gun index: %i not selected!"), Index);
		}
	}
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//WASD axis binding
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);

	//Mouse axis binding
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);

	//Controller axis binding
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooterCharacter::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooterCharacter::LookRightRate);

	//Swap weapons binding
	PlayerInputComponent->BindAxis(TEXT("SwitchWeapon"), this, &AShooterCharacter::SwitchGuns);

	//Jump action binding
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);

	//Shoot action binding
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShooterCharacter::Shoot);



}

float AShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);

	if(IsDead())
	{
		//Notify GameMode that this Pawn has been killed
		ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
		if(GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}

	return DamageToApply;
}

bool AShooterCharacter::IsDead() const
{
	return Health <= 0;
}

// bool AShooterCharacter::IsFireDisabled() const
// {
// 	return CanFire;
// }


float AShooterCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

void AShooterCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AShooterCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AShooterCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());	
}

void AShooterCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::Shoot()
{
	Gun[ActiveGunIndex]->PullTrigger();
}

// bool AShooterCharacter::HasSwapped() const
// {

// }

void AShooterCharacter::SwitchGuns(float Slot)
{	
	//Disable gun that got switched away
	Gun[ActiveGunIndex]->SetActorHiddenInGame(true);	

	//Adjust ActiveGun based on scrollwheel	
	int32 SlotIndex = static_cast<int32>(Slot);
	ActiveGunIndex -= SlotIndex;
	if(ActiveGunIndex > 2) ActiveGunIndex = 0;
	ActiveGunIndex = FMath::Clamp(ActiveGunIndex, 0, 2);

	//Enable new Active Gun
	Gun[ActiveGunIndex]->SetActorHiddenInGame(false);

	//TODO : Add Weapon swap & cooldown
	//Weapon cooldown between weapon swap
	//CanFire = false;
	//GetWorldTimerManager().SetTimer(SwapTimer, this, &AShooterCharacter::HasSwapped, SwapDelay);

}
