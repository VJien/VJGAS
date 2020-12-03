// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "VGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class VGAS_API AVGPlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_UCLASS_BODY()
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent()const override;

	virtual class UVGAttributeSet* GetAttributeSet()const;









protected:
	UPROPERTY()
		class UVGAbilitySystemComponent* AbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly)
		class UVGAttributeSet* AttributeSet;
};
