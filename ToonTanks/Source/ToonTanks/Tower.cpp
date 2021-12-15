// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"


void ATower::Tick(float DeltaTime)
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

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}


void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
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

bool ATower::InFireRange()
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