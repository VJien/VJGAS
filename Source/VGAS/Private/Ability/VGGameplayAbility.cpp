// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/VGGameplayAbility.h"
#include "Component/VGAbilitySystemComponent.h"


void UVGGameplayAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);


	if (bAutoActivate)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, false);
	}
}
