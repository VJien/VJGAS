// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/VGAT_WaitReceiveDamage.h"
#include "Abilities/GameplayAbility.h"
#include "Component/VGAbilitySystemComponent.h"

UVGAT_WaitReceiveDamage::UVGAT_WaitReceiveDamage(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}

void UVGAT_WaitReceiveDamage::Activate()
{
	UVGAbilitySystemComponent* ASC = Cast<UVGAbilitySystemComponent>(AbilitySystemComponent);

	if (ASC)
	{
		ASC->OnRecieveDamage.AddDynamic(this, &UVGAT_WaitReceiveDamage::OnDamageReceived);
	}
}

void UVGAT_WaitReceiveDamage::OnDestroy(bool bInOwnerFinished)
{
	UVGAbilitySystemComponent* ASC = Cast<UVGAbilitySystemComponent>(AbilitySystemComponent);

	if (ASC)
	{
		ASC->OnRecieveDamage.RemoveDynamic(this, &UVGAT_WaitReceiveDamage::OnDamageReceived);
	}

	Super::OnDestroy(bInOwnerFinished);
}


UVGAT_WaitReceiveDamage* UVGAT_WaitReceiveDamage::WaitReceiveOwnnerDamage(UGameplayAbility* ownAbility, bool TriggerOnce)
{
	UVGAT_WaitReceiveDamage* MyObj = NewAbilityTask<UVGAT_WaitReceiveDamage>(ownAbility);
	MyObj->bTriggerOnce = TriggerOnce;
	return MyObj;
}

void UVGAT_WaitReceiveDamage::OnDamageReceived(class UVGAbilitySystemComponent* SourceASC, float damage)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		OnReceiveDamage.Broadcast(SourceASC, damage);
	}
	if (bTriggerOnce)
	{
		EndTask();
	}
}
