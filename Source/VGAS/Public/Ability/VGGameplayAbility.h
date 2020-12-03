// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "VGASDefine.h"
#include "VGGameplayAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class VGAS_API UVGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)override;




public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
		EVGAbilityInputID AbilityID = EVGAbilityInputID::NONE;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
		EVGAbilityInputID InputID = EVGAbilityInputID::NONE;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
		bool bAutoActivate = false;
};
