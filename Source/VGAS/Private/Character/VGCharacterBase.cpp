// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VGCharacterBase.h"
#include "Component/VGAbilitySystemComponent.h"
#include "VGASDefine.h"
#include "Attribute/VGAttributeSet.h"
#include "Ability/VGGameplayAbility.h"
#include "GameplayAbilitySpec.h"

// Sets default values
AVGCharacterBase::AVGCharacterBase(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

class UAbilitySystemComponent* AVGCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

void AVGCharacterBase::InitAttributes()
{
	if (!AbilitySystemComponent.IsValid())
	{
		UE_LOG(VGAS, Warning, TEXT("InitAttributes failed [no ASC]  !!"));
		return;
	}
	if (!DefaultAttributeEffect)
	{
		UE_LOG(VGAS, Warning, TEXT("InitAttributes failed [no DefaultAttributeEffect]  !!"));
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, GetCharacterLevel(), EffectContextHandle);
	if (SpecHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), AbilitySystemComponent.Get());
	}

}

void AVGCharacterBase::AddCharacterAbilities()
{
	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid() || AbilitySystemComponent->bHasGiveCharacterAbilities)
	{
		return;
	}
	for (auto ga : CharacterAbilities)
	{
		FGameplayAbilitySpec spec = FGameplayAbilitySpec(ga, GetAbilityLevel(ga.GetDefaultObject()->AbilityID), static_cast<int32>(ga.GetDefaultObject()->InputID), this);
		AbilitySystemComponent->GiveAbility(spec);
		
	}
	AbilitySystemComponent->bHasGiveCharacterAbilities = true;
}

void AVGCharacterBase::AddStartUpEffects()
{
	if (GetLocalRole()!=ROLE_Authority || !AbilitySystemComponent.IsValid() || AbilitySystemComponent->bHasApplyStartupEffects)
	{
		UE_LOG(VGAS, Warning, TEXT("Add Startup Effects failed"));
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	for (auto ge : StartupEffects)
	{
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(ge, GetCharacterLevel(), EffectContextHandle);
		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), AbilitySystemComponent.Get());
		}
	}
	AbilitySystemComponent->bHasApplyStartupEffects = true;
}

int32 AVGCharacterBase::GetCharacterLevel() const
{
	if (AttributeSet.IsValid())
	{
		return AttributeSet->GetCharacterLevel();
	}
	return 0;
}

int32 AVGCharacterBase::GetAbilityLevel(EVGAbilityInputID intpuID) const
{
	return 1;
}

bool AVGCharacterBase::IsAlive() const
{
	return GetHealth() > 0;
}

float AVGCharacterBase::GetHealth() const
{
	if (AttributeSet.IsValid())
	{
		return AttributeSet->GetHealth();
	}
	return 0;
}

float AVGCharacterBase::GetMaxHealth() const
{
	if (AttributeSet.IsValid())
	{
		return AttributeSet->GetMaxHealth();
	}
	return 0;
}

float AVGCharacterBase::GetMana() const
{
	if (AttributeSet.IsValid())
	{
		return AttributeSet->GetMana();
	}
	return 0;
}

float AVGCharacterBase::GetMaxMana() const
{
	if (AttributeSet.IsValid())
	{
		return AttributeSet->GetMaxMana();
	}
	return 0;
}

