// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_InvestigateArea.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UBTTask_InvestigateArea : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_InvestigateArea();
	

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
private:
	UPROPERTY(Category = Node, EditAnywhere)
	int InvestigateRange;

	UPROPERTY(Category = Blackboard, EditAnywhere)
	struct FBlackboardKeySelector InvestigateLocationVectorKey;
	
};
