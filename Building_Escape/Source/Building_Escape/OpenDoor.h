// Copyright Raymond Becking 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Components/AudioComponent.h"
#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	int TotalMassOfActors() const;
	void FindAudioComponent();
	void FindPressurePlate();
	void PlayOpenSound();
	void PlayCloseSound();

private:

float CurrentAngle;
float InitialAngle;

//Tracks if sound has been played
bool OpenHasPlayed = false;
bool CloseHasPlayed = true;

//Tracks if the door should swing open
bool SwingDoorOpen = false; 


UPROPERTY(EditAnywhere)
float OpenAngle = 90.f;

UPROPERTY(EditAnywhere)
float OpenSpeed = 1.6f;	
float DoorLastOpened = 0.f;

UPROPERTY(EditAnywhere)
float DoorCloseDelay = 1.f;

UPROPERTY(EditAnywhere)
float CloseSpeed = 1.6f;

UPROPERTY(EditAnywhere)
int RequiredMassToOpen = 60;

UPROPERTY(EditAnywhere)
bool ExactMassRequired = false;

UPROPERTY(EditAnywhere)
bool StayOpenOnTrigger = false;

UPROPERTY(EditAnywhere)
ATriggerVolume* PressurePlate = nullptr;

UPROPERTY(EditAnywhere)
UAudioComponent* AudioComponent = nullptr;

};
