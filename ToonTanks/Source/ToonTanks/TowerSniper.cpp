// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerSniper.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"


void ATowerSniper::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //Check if tank is in range
    //UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance);
    if(InFireRange())
    {
        //If in range, rotate turret toward tank
        RotateTurret(Tank->GetActorLocation());
        DrawDebugLine(GetWorld(), this->GetActorLocation(), Tank->GetActorLocation(), FColor::Red, false, -1.0f, 0U, 1.5f);
    }
    
}

void ATowerSniper::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}


void ATowerSniper::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATowerSniper::CheckFireCondition, FireRate, true);
}

void ATowerSniper::CheckFireCondition()
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

bool ATowerSniper::InFireRange()
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