// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set up gun components
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	if(AmmoCount != 0)
	{	
		//Subtract Ammo when trigger is pulled
		AmmoCount--;

		UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));	
		UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));

		FHitResult Hit;
		FVector ShotDirection;
		bool bSuccess = GunTrace(Hit, ShotDirection);
		if(bSuccess)
		{
			//Spawn Emitter where something was hit by the line trace
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
			UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
			
			
			AActor* HitActor = Hit.GetActor();
			if(HitActor != nullptr)
			{
				FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
				AController* OwnerController = GetOwnerController();
				HitActor->TakeDamage(Damage, DamageEvent, GetOwnerController(), this);
			}
		}
	}
	else
	{		
		UGameplayStatics::SpawnSoundAttached(EmptyMagSound, Mesh, TEXT("MuzzleFlashSocket"));
	}
}

void AGun::RefillMagazine()
{
	if(AmmoReserves > 0)
	{
		if(AmmoReserves < (MagazineSize - AmmoCount))
		{
			AmmoCount += AmmoReserves;
			AmmoReserves = 0;
		}
		else		
		{
			int AmmoMissing = (MagazineSize - AmmoCount);
			AmmoCount += AmmoMissing;
			AmmoReserves -= AmmoMissing;
		}
	}
}

float AGun::GetAmmoCountPercent() const
{
	return AmmoCount / MagazineSize * 100;
}

int AGun::GetAmmoAmount() const
{
	return AmmoCount;
}

int AGun::GetAmmoReserves() const
{
	return AmmoReserves;
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
	//Set up ammo
	AmmoCount = MagazineSize;

	UE_LOG(LogTemp, Warning, TEXT("Ammo: %i"), MagazineSize);
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{	
	AController* OwnerController = GetOwnerController();
	if(OwnerController == nullptr) 
		return false;

	//Get the location & rotation of the Camera
	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);	
	ShotDirection = -Rotation.Vector();

	//Extend end position to where the camera is looking 
	FVector End = Location + Rotation.Vector() * MaxRange;
	FCollisionQueryParams Params;
	//Ignore self and gun for line trace
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());	
	//Create line trace to find out where the line hits something
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);	
}

AController* AGun::GetOwnerController() const
{	
	//Get Character(pawn) and its Controller
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if(OwnerPawn == nullptr) 
		return nullptr;
	return OwnerPawn->GetController();
}