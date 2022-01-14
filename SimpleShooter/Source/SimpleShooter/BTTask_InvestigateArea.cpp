// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_InvestigateArea.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"

UBTTask_InvestigateArea::UBTTask_InvestigateArea()
{
    NodeName = TEXT("AreaToInvestigate");
}

EBTNodeResult::Type UBTTask_InvestigateArea::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
    
    //Get AI Location to investigate the area around
    FVector LocationToInvestigate = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());
    
    int32 RandomDirectionX = UKismetMathLibrary::RandomIntegerInRange(-1, 1);
    int32 RandomDirectionY = UKismetMathLibrary::RandomIntegerInRange(-1, 1);

    //Convert Range to distance units (Investigate range 1 is 1 meter), add random direction to investigate
    LocationToInvestigate.X += (RandomDirectionX * InvestigateRange * 100 * 2);
    LocationToInvestigate.Y += (RandomDirectionY * InvestigateRange * 100 * 2);

    //Set a new location to investigate
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(InvestigateLocationVectorKey.SelectedKeyName, LocationToInvestigate);

    return EBTNodeResult::Succeeded;
}