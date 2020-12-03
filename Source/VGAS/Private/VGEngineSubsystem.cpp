// Fill out your copyright notice in the Description page of Project Settings.


#include "VGEngineSubsystem.h"
#include "AbilitySystemGlobals.h"

void UVGEngineSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UAbilitySystemGlobals::Get().InitGlobalData();
}
