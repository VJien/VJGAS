// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/VGAbilitySystemComponent.h"
#include "VGASDefine.h"

UVGAbilitySystemComponent::UVGAbilitySystemComponent(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	
}

void UVGAbilitySystemComponent::LocalInputConfirm()
{
	Super::LocalInputConfirm();
	UE_LOG(VGAS, Log, TEXT(" UVGAbilitySystemComponent::LocalInputConfirm()"));
}
