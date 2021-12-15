// Copyright Raymond Becking 2021


#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	InitialAngle = GetOwner()->GetActorRotation().Yaw;
	CurrentAngle = InitialAngle;
	OpenAngle += InitialAngle;

	//Make sure components exist
	FindPressurePlate();
	FindAudioComponent();
}

void UOpenDoor::FindPressurePlate()
{
	if(!PressurePlate)
	{
		FString ActorName = GetOwner()->GetName();
		UE_LOG(LogTemp, Error, TEXT("The %s object has the open door component, but no pressureplate is set!"), *ActorName);
	}
}

void UOpenDoor::FindAudioComponent()
{	
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	if(!AudioComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Missing audio component!"), *GetOwner()->GetName());
	}
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if(TotalMassOfActors() > RequiredMassToOpen && !ExactMassRequired)
	{
		UE_LOG(LogTemp, Warning, TEXT("Total weight is: %i"), TotalMassOfActors());
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else if(TotalMassOfActors() == RequiredMassToOpen && ExactMassRequired || SwingDoorOpen)
	{
		UE_LOG(LogTemp, Warning, TEXT("Total weight is: %i"), TotalMassOfActors());
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
		
		if(StayOpenOnTrigger)
		{
			//Makes sure the door never closes			  
			DoorLastOpened = GetWorld()->GetTimeSeconds() * 2;
			//Causes door to swing open
			SwingDoorOpen = true;
		}
	}
	else
	{
		if(DoorLastOpened + DoorCloseDelay < GetWorld()->GetTimeSeconds())
		{
		//If the door has been open longer than DoorCloseDelay
		CloseDoor(DeltaTime);
		}
	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	CurrentAngle = FMath::FInterpTo(CurrentAngle, OpenAngle, DeltaTime, OpenSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();	
	DoorRotation.Yaw = CurrentAngle;
	GetOwner()->SetActorRotation(DoorRotation);
	//UE_LOG(LogTemp, Warning, TEXT("Current yaw is: %f"), DoorRotation.Yaw);

	PlayOpenSound();
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	CurrentAngle = FMath::FInterpTo(CurrentAngle, InitialAngle, DeltaTime, CloseSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();	
	DoorRotation.Yaw = CurrentAngle;
	GetOwner()->SetActorRotation(DoorRotation);
	//UE_LOG(LogTemp, Warning, TEXT("Current yaw is: %f"), DoorRotation.Yaw);
	
	PlayCloseSound();	
}

void UOpenDoor::PlayOpenSound()
{
	//Exit if component doesnt exist
	if(!AudioComponent) {return;}	
	if(!AudioComponent->IsPlaying())
	{ 
		if(!OpenHasPlayed)
		{
		AudioComponent->Play();
		OpenHasPlayed = true;
		CloseHasPlayed = false;
		}	
	}
}

void UOpenDoor::PlayCloseSound()
{
	//Exit if component doesnt exist
	if(!AudioComponent) {return;}	
	if(!AudioComponent->IsPlaying())
	{ 
		if(!CloseHasPlayed)
		{
		AudioComponent->Play();
		OpenHasPlayed = false;
		CloseHasPlayed = true;
		}
	}
}	

int UOpenDoor::TotalMassOfActors() const
{	
	int TotalMass = 0;

	//Find overlapping actors
	TArray<AActor*> ActorsThatOverlap;
	if (!PressurePlate) {return TotalMass;}
	PressurePlate->GetOverlappingActors(OUT ActorsThatOverlap);

	//Add up their masses
	for(AActor* Actor : ActorsThatOverlap)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	} 

	return TotalMass;
}