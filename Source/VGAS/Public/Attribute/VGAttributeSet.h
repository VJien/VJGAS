// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Component/VGAbilitySystemComponent.h"
#include "VGAttributeSet.generated.h"




#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class VGAS_API UVGAttributeSet : public UAttributeSet
{
	GENERATED_UCLASS_BODY()

public:

	// Returns properties that are replicated for the lifetime of the actor channel
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	//属性修改之前
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)override;


	//执行GE之前
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)override;







public:
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UVGAttributeSet,Health)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UVGAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_Mana)
		FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UVGAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_MaxMana)
		FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UVGAttributeSet, MaxMana)



	UPROPERTY(BlueprintReadOnly, Category = "Character Level", ReplicatedUsing = OnRep_CharacterLevel)
		FGameplayAttributeData CharacterLevel;
	ATTRIBUTE_ACCESSORS(UVGAttributeSet, CharacterLevel)
		UPROPERTY(BlueprintReadOnly, Category = "XP", ReplicatedUsing = OnRep_XP)
		FGameplayAttributeData XP;
	ATTRIBUTE_ACCESSORS(UVGAttributeSet, XP)

//RepFunction
	UFUNCTION()
		virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
		virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
		virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);	
	UFUNCTION()
		virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
		virtual void OnRep_CharacterLevel(const FGameplayAttributeData& OldCharacterLevel);
	UFUNCTION()
		virtual void OnRep_XP(const FGameplayAttributeData& OldXP);
};
