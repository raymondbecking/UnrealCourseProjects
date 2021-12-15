// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksHUD.h"
#include "Kismet/GameplayStatics.h"

// void AToonTanksHUD::Tick(float DeltaTime)
// {
//     Super::Tick(DeltaTime);
    
// }

void AToonTanksHUD::SetHealthHUD(float Health)
    {
        HealthHUD = Health; 

        UpdateHealthHUD(HealthHUD);

        UE_LOG(LogTemp, Warning, TEXT("Health: %f"), HealthHUD);
    }
