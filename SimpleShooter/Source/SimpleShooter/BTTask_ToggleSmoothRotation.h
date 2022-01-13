// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_ToggleSmoothRotation.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UBTTask_ToggleSmoothRotation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_ToggleSmoothRotation();

	UPROPERTY(Category = Node, EditAnywhere)
	bool bEnableSmoothRotation;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
