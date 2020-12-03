// Fill out your copyright notice in the Description page of Project Settings.


#include "Attribute/VGAttributeSet.h"
#include "VGASDefine.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

UVGAttributeSet::UVGAttributeSet(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{


}

void UVGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	
	DOREPLIFETIME_CONDITION_NOTIFY(UVGAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVGAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVGAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVGAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVGAttributeSet, XP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UVGAttributeSet, CharacterLevel, COND_None, REPNOTIFY_Always);
}

void UVGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	UE_LOG(VGAS, Log, TEXT("Attribute Pre Changed old = %s, new= %f"), Attribute.GetUProperty(), NewValue);
}

void UVGAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)
{
	UE_LOG(VGAS, Log, TEXT("PostGameplayEffectExecute  "));
}



void UVGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVGAttributeSet, Health, OldHealth);
}

void UVGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVGAttributeSet, MaxHealth, OldHealth);
}

void UVGAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVGAttributeSet, Mana, OldMana);
}

void UVGAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVGAttributeSet, MaxMana, OldMana);
}

void UVGAttributeSet::OnRep_CharacterLevel(const FGameplayAttributeData& OldCharacterLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVGAttributeSet, CharacterLevel, OldCharacterLevel);
}

void UVGAttributeSet::OnRep_XP(const FGameplayAttributeData& OldXP)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UVGAttributeSet, XP, OldXP);
}
