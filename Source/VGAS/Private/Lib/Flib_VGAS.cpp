// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib/Flib_VGAS.h"



void UFlib_VGAS::CancelAbilityWithTag(UAbilitySystemComponent* AbilityComponent, const FGameplayTagContainer& WithTags, const FGameplayTagContainer& WithoutTags, UGameplayAbility* Ignore)
{
	if (!AbilityComponent)
	{
		return;
	}
	AbilityComponent->CancelAbilities(&WithTags, &WithoutTags, Ignore);
}

void UFlib_VGAS::CancelAllAbilities(UAbilitySystemComponent* AbilityComponent, UGameplayAbility* Ignore /*= nullptr*/)
{
	if (!AbilityComponent)
	{
		return;
	}
	AbilityComponent->CancelAllAbilities(Ignore);
}

void UFlib_VGAS::CancelAbilitySpec(UAbilitySystemComponent* AbilityComponent, const FGameplayAbilitySpec& Spec, UGameplayAbility* Ignore)
{
	if (!AbilityComponent)
	{
		return;
	}
	AbilityComponent->CancelAbility(Spec.Ability);
}

void UFlib_VGAS::GetActivatableGameplayAbilitySpecsByAllMatchingTags(UAbilitySystemComponent* AbilityComponent, const FGameplayTagContainer& GameplayTagContainer, TArray < struct FGameplayAbilitySpec >& MatchingGameplayAbilities, bool bOnlyAbilitiesThatSatisfyTagRequirements) 
{

	if (!AbilityComponent)
	{
		return;
	}
	TArray <FGameplayAbilitySpec* > returnAbilities;

	AbilityComponent->GetActivatableGameplayAbilitySpecsByAllMatchingTags(GameplayTagContainer, returnAbilities, bOnlyAbilitiesThatSatisfyTagRequirements);
	for (FGameplayAbilitySpec* i : returnAbilities)
	{
		MatchingGameplayAbilities.Add(*i);
	}
	
}
