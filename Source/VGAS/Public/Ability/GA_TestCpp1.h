// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability/VGGameplayAbility.h"
#include "GA_TestCpp1.generated.h"

/**
 * 
 */
UCLASS()
class VGAS_API UGA_TestCpp1 : public UVGGameplayAbility
{
	GENERATED_BODY()
public:
	virtual void ApplyCooldown(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)const override;
	virtual const FGameplayTagContainer* GetCooldownTags()const override;




	UFUNCTION(BlueprintCallable)
		FGameplayAbilitySpec GetSpec()const;
	UFUNCTION(BlueprintCallable)
		void LevelUp(int32 up);

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
		FScalableFloat CD;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FGameplayTagContainer CDTags;


	FGameplayTagContainer tempTags;
};
