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

FVGASpec UFlib_VGAS::BreakGASpec(const FGameplayAbilitySpec& Spec)
{
	return FVGASpec(Spec);
}

FGameplayAbilitySpec UFlib_VGAS::MakeGASpec(FVGASpec Spec)
{
	auto sp = Spec.ToGASpec();
	return sp;
}

FVGESpec UFlib_VGAS::BreakGESpec(const FGameplayEffectSpec& s)
{
	return FVGESpec(s);
}

FGameplayEffectSpec UFlib_VGAS::MakeGESpec(FVGESpec s)
{
	FGameplayEffectSpec sp;
	sp.Def = s.Def;
	sp.ModifiedAttributes = s.ModifiedAttributes;
	sp.CapturedRelevantAttributes = s.CapturedRelevantAttributes;
	sp.TargetEffectSpecs = s.TargetEffectSpecs;
	sp.Duration = s.Duration;
	sp.Period = s.Period;
	sp.ChanceToApplyToTarget = s.ChanceToApplyToTarget;
	sp.CapturedTargetTags = s.CapturedTargetTags;
	sp.CapturedSourceTags = s.CapturedSourceTags;
	sp.DynamicGrantedTags = s.DynamicGrantedTags;
	sp.DynamicAssetTags = s.DynamicAssetTags;
	sp.Modifiers = s.Modifiers;
	sp.StackCount = s.StackCount;
	sp.bCompletedSourceAttributeCapture = s.bCompletedSourceAttributeCapture;
	sp.bCompletedTargetAttributeCapture = s.bCompletedTargetAttributeCapture;
	sp.bDurationLocked = s.bDurationLocked;
	sp.GrantedAbilitySpecs = s.GrantedAbilitySpecs;
	sp.SetByCallerNameMagnitudes = s.SetByCallerNameMagnitudes;
	sp.SetByCallerTagMagnitudes = s.SetByCallerTagMagnitudes;

	return sp;
}

float UFlib_VGAS::GetEffectLevel(const FGameplayEffectSpec& spec)
{
	return spec.GetLevel();
}

