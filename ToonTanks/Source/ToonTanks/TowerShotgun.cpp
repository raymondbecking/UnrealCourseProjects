// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerShotgun.h"
#include "Tank.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ATowerShotgun::ATowerShotgun()
{
    //Create 2nd and 3rd barrel
    SecondBarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Second Barrel"));
	SecondBarrel->SetupAttachment(TurretMesh);  
    ThirdBarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Third Barrel"));
	ThirdBarrel->SetupAttachment(TurretMesh);

    ProjectileSpawnPoint2 = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn 2"));
	ProjectileSpawnPoint2->SetupAttachment(SecondBarrel);    
    ProjectileSpawnPoint3 = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn 3"));
	ProjectileSpawnPoint3->SetupAttachment(ThirdBarrel);   
}

void ATowerShotgun::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //Check if tank is in range
    //UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance);
    if(InFireRange())
    {
        //If in range, rotate turret toward tank
        RotateTurret(Tank->GetActorLocation());
    }
    
}

void ATowerShotgun::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}


void ATowerShotgun::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATowerShotgun::CheckFireCondition, FireRate, true);
}

void ATowerShotgun::Fire()
{
    Super::Fire();
    
    UE_LOG(LogTemp, Warning, TEXT("FIRING"));

    if(ProjectileSpawnPoint2)
	{
        
		FVector Location = ProjectileSpawnPoint2->GetComponentLocation();
		FRotator Rotation = ProjectileSpawnPoint2->GetComponentRotation();

		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
		Projectile->SetOwner(this); 
	}

    if(ProjectileSpawnPoint3)
	{
	 	FVector Location = ProjectileSpawnPoint3->GetComponentLocation();
	 	FRotator Rotation = ProjectileSpawnPoint3->GetComponentRotation();

	 	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	 	Projectile->SetOwner(this); 
	}
}

void ATowerShotgun::CheckFireCondition()
{    
    if(Tank == nullptr)
    {
        return;
    }
    
    //Check if target is within fire range
    if(InFireRange() && Tank->bAlive)   
    {
        //Call fire function
        Fire();                    
    }
    
}

bool ATowerShotgun::InFireRange()
{
    if(Tank)
    {
        //Find distance to tank
        float Distance = FVector::Distance(this->GetActorLocation(), Tank->GetActorLocation());    
        if(Distance <= FireRange)
        {
            return true;
        }
    }
    return false;
}