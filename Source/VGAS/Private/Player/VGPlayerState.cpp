// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/VGPlayerState.h"
#include "Component/VGAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"
#include "Attribute/VGAttributeSet.h"

AVGPlayerState::AVGPlayerState(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	//ASC
	AbilitySystemComponent = CreateDefaultSubobject<UVGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	//AttSet
	AttributeSet = CreateDefaultSubobject<UVGAttributeSet>(TEXT("AttributeSet"));

	NetUpdateFrequency = 100.0f;
	

}

UAbilitySystemComponent* AVGPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UVGAttributeSet* AVGPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
