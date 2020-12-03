// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Component/VGAbilitySystemComponent.h"
#include "Flib_VGAS.generated.h"



/**
 * 
 */
UCLASS()
class VGAS_API UFlib_VGAS : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "VGAS | FunctionLib", meta = (AutoCreateRefTerm = "WithoutTags, WithTags"))
		static void CancelAbilityWithTag(UAbilitySystemComponent* AbilityComponent, const FGameplayTagContainer& WithTags, const FGameplayTagContainer& WithoutTags, UGameplayAbility* Ignore = nullptr);

	UFUNCTION(BlueprintCallable, Category = "VGAS | FunctionLib", meta = (AutoCreateRefTerm = "WithoutTags, WithTags"))
		static void CancelAllAbilities(UAbilitySystemComponent* AbilityComponent, UGameplayAbility* Ignore = nullptr);

	UFUNCTION(BlueprintCallable, Category = "VGAS | FunctionLib", meta = (AutoCreateRefTerm = "WithoutTags, WithTags"))
		static void CancelAbilitySpec(UAbilitySystemComponent* AbilityComponent, const FGameplayAbilitySpec& Spec, UGameplayAbility* Ignore);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "VGAS | FunctionLib", meta = (AutoCreateRefTerm = "GameplayTagContainer, WithTags"))
		static void GetActivatableGameplayAbilitySpecsByAllMatchingTags(UAbilitySystemComponent* AbilityComponent, const FGameplayTagContainer& GameplayTagContainer, TArray < struct FGameplayAbilitySpec >& MatchingGameplayAbilities, bool bOnlyAbilitiesThatSatisfyTagRequirements);

};
