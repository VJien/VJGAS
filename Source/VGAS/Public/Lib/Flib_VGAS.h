// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Component/VGAbilitySystemComponent.h"
#include "VGASDefine.h"
#include "Flib_VGAS.generated.h"



/**
 * 
 */
UCLASS()
class VGAS_API UFlib_VGAS : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "VGAS | Ability", meta = (AutoCreateRefTerm = "WithoutTags, WithTags"))
		static void CancelAbilityWithTag(UAbilitySystemComponent* AbilityComponent, const FGameplayTagContainer& WithTags, const FGameplayTagContainer& WithoutTags, UGameplayAbility* Ignore = nullptr);

	UFUNCTION(BlueprintCallable, Category = "VGAS | Ability", meta = (AutoCreateRefTerm = "WithoutTags, WithTags"))
		static void CancelAllAbilities(UAbilitySystemComponent* AbilityComponent, UGameplayAbility* Ignore = nullptr);

	UFUNCTION(BlueprintCallable, Category = "VGAS | Ability", meta = (AutoCreateRefTerm = "WithoutTags, WithTags"))
		static void CancelAbilitySpec(UAbilitySystemComponent* AbilityComponent, const FGameplayAbilitySpec& Spec, UGameplayAbility* Ignore);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VGAS | Ability", meta = (AutoCreateRefTerm = ""))
		static void GetActivatableGameplayAbilitySpecsByAllMatchingTags(UAbilitySystemComponent* AbilityComponent, const FGameplayTagContainer& GameplayTagContainer, TArray < struct FGameplayAbilitySpec >& MatchingGameplayAbilities, bool bOnlyAbilitiesThatSatisfyTagRequirements);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VGAS | Data", meta = (AutoCreateRefTerm = ""))
		static FVGASpec BreakGASpec(const FGameplayAbilitySpec& Spec);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VGAS | Data", meta = (AutoCreateRefTerm = ""))
		static FGameplayAbilitySpec MakeGASpec(FVGASpec Spec);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VGAS | Data", meta = (AutoCreateRefTerm = ""))
		static FVGESpec BreakGESpec(const FGameplayEffectSpec& s);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VGAS | Data", meta = (AutoCreateRefTerm = ""))
		static FGameplayEffectSpec MakeGESpec(FVGESpec s);


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VGAS | Effect", meta = (AutoCreateRefTerm = ""))
		static float GetEffectLevel(const FGameplayEffectSpec& spec);
};

