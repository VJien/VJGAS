// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "VGAbilitySystemComponent.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRecieveDamage, UVGAbilitySystemComponent*, AbilityComponent, float, Damage);

UCLASS()
class VGAS_API UVGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_UCLASS_BODY()
public:
	virtual void LocalInputConfirm()override;

	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FOnRecieveDamage OnRecieveDamage;

	bool bHasApplyStartupEffects =  false;
	bool bHasGiveCharacterAbilities = false;
};
