// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboarValue.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTTask_ClearBlackboarValue::UBTTask_ClearBlackboarValue()
{
    NodeName =TEXT("Clear Blackboard Value");
}

EBTNodeResult::Type UBTTask_ClearBlackboarValue::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);


    // . instead of -> cause its address & (&OwnerComp)
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    return EBTNodeResult::Succeeded;
}