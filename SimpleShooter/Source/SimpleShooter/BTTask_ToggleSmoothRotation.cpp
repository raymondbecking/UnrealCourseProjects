// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ToggleSmoothRotation.h"
#include "ShooterCharacter.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTTask_ToggleSmoothRotation::UBTTask_ToggleSmoothRotation()
{
    NodeName = TEXT("Smooth Rotation");
}

EBTNodeResult::Type UBTTask_ToggleSmoothRotation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    ACharacter* AICharacter = Cast<ACharacter>(OwnerComp.GetAIOwner()->GetPawn());
    if(AICharacter == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    UCharacterMovementComponent* AICharacterMovement = AICharacter->GetCharacterMovement();
    if(AICharacterMovement == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    if(bEnableSmoothRotation)
    {
        //Enable Smooth AI rotation
        AICharacter->bUseControllerRotationYaw = false;
        AICharacterMovement->bOrientRotationToMovement = true;

    }
    else
    {
        //Allow SetDefaultFocus to target the player since smooth rotation only works when moving
        AICharacter->bUseControllerRotationYaw = true;
        AICharacterMovement->bOrientRotationToMovement = false;     
    }



    return EBTNodeResult::Succeeded;
}