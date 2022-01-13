// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_LookAround.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UBTTaskNode_LookAround : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskNode_LookAround();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
