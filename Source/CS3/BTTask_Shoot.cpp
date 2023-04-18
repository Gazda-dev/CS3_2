// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ShooterAIController.h"
#include "ShooterCharacter.h"


UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName =TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    //. instead of -> cause its a address(&OwnerComp)
    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }
    AShooterCharacter* AI_ShooterCharacter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    if(AI_ShooterCharacter == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    AI_ShooterCharacter->Shoot();


    return EBTNodeResult::Succeeded;
}
