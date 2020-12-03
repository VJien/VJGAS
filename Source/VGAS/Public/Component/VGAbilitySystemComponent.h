// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "VGAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class VGAS_API UVGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_UCLASS_BODY()
public:
	virtual void LocalInputConfirm()override;


	bool bHasApplyStartupEffects =  false;
	bool bHasGiveCharacterAbilities = false;
};
