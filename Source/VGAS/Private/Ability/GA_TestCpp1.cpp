// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/GA_TestCpp1.h"


void UGA_TestCpp1::ApplyCooldown(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) const
{
	UGameplayEffect* CooldownGE = GetCooldownGameplayEffect();
	if (CooldownGE)
	{
		FGameplayEffectSpecHandle SpecHandle = MakeOutgoingGameplayEffectSpec(CooldownGE->GetClass(), GetAbilityLevel());
		SpecHandle.Data.Get()->DynamicGrantedTags.AppendTags(CDTags);
		FName tagName = FName(*(CDTags.ToStringSimple()));
		SpecHandle.Data.Get()->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(tagName), CD.GetValueAtLevel(GetAbilityLevel()));
		ApplyGameplayEffectSpecToOwner(Handle, ActorInfo, ActivationInfo, SpecHandle);
	}
}

const FGameplayTagContainer* UGA_TestCpp1::GetCooldownTags() const
{
	FGameplayTagContainer* MutableTags = const_cast<FGameplayTagContainer*>(&tempTags);
	const FGameplayTagContainer* ParentTags = Super::GetCooldownTags();
	if (ParentTags)
	{
		MutableTags->AppendTags(*ParentTags);
	}
	MutableTags->AppendTags(CDTags);
	return MutableTags;


	
}

FGameplayAbilitySpec UGA_TestCpp1::GetSpec() const
{
	return *this->GetCurrentAbilitySpec();
}

void UGA_TestCpp1::LevelUp(int32 up)
{
	GetCurrentAbilitySpec()->Level += up;
}
