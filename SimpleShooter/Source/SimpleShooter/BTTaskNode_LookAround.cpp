// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_LookAround.h"
#include "ShooterCharacter.h"
#include "AIController.h"

UBTTaskNode_LookAround::UBTTaskNode_LookAround()
{
    NodeName = TEXT("Look Around");
}

EBTNodeResult::Type UBTTaskNode_LookAround::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    APawn* Character = OwnerComp.GetAIOwner()->GetPawn();
    if(Character == nullptr)
    {
        return EBTNodeResult::Failed;
    }
    
    FRotator AIRotation = Character->GetActorRotation();
    AIRotation.Yaw += 2;
    Character->SetActorRotation(AIRotation);



    return EBTNodeResult::Succeeded;
}
