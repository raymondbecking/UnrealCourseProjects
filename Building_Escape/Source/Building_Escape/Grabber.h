// Copyright Raymond Becking 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Reach = 180.f;

	UPROPERTY(EditAnywhere)
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UPROPERTY(EditAnywhere)
	UInputComponent* InputComponent = nullptr;	

	void Grab();	
	void Release();	
	void FindPhysicsHandle();
	void SetupInputComponent();
	
	//Return first actor in reach with physics body
	FHitResult GetFirstPhysicsBodyInReach() const;

	//Returns line trace end
	FVector GetPlayerReach() const;

	//Get Player Position in the world
	FVector GetPlayerWorldPos() const;
};
