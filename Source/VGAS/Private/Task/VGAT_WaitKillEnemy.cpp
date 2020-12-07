// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/VGAT_WaitKillEnemy.h"
#include "Component/VGAbilitySystemComponent.h"
#include "Character/VGCharacterBase.h"

UVGAT_WaitKillEnemy::UVGAT_WaitKillEnemy(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}


void UVGAT_WaitKillEnemy::Activate()
{
	UVGAbilitySystemComponent* ASC = Cast<UVGAbilitySystemComponent>(AbilitySystemComponent);

	if (ASC)
	{
		AVGCharacterBase* c = Cast<AVGCharacterBase>(ASC->GetAvatarActor());
		if (c)
		{
			c->OnKillEnmey.AddDynamic(this, &UVGAT_WaitKillEnemy::KillEnemy);
		}

	}
	UE_LOG(LogTemp, Warning, TEXT("UVGAT_WaitKillEnemy**************"));
}

void UVGAT_WaitKillEnemy::OnDestroy(bool bInOwnerFinished)
{
	UVGAbilitySystemComponent* ASC = Cast<UVGAbilitySystemComponent>(AbilitySystemComponent);

	if (ASC)
	{
		AVGCharacterBase* c = Cast<AVGCharacterBase>(ASC->GetAvatarActor());
		if (c)
		{
			c->OnKillEnmey.RemoveDynamic(this, &UVGAT_WaitKillEnemy::KillEnemy);
		}


	}
	Super::OnDestroy(bInOwnerFinished);
}

UVGAT_WaitKillEnemy* UVGAT_WaitKillEnemy::WaitKillEnemey(UGameplayAbility* ownAbility, bool TriggerOnce)
{
	UVGAT_WaitKillEnemy* obj = NewAbilityTask<UVGAT_WaitKillEnemy>(ownAbility);
	obj->bTriggerOnece = TriggerOnce;
	return obj;
}

void UVGAT_WaitKillEnemy::KillEnemy( AActor* enemy)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnKillEnemy.Broadcast(enemy);
	}
	if (bTriggerOnece)
	{
		EndTask();
	}
	
}
