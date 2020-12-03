// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_EXTERN(VGAS, Log, All);



UENUM(BlueprintType)
enum class EVGAbilityInputID : uint8
{
	NONE,
	CONFIRM,
	CANCEL,
	ABILITY1,
	ABILITY2,
	ABILITY3,
	ABILITY4,
	ABILITY5,
	ABILITY6,
	SPRINT,
	JUMP
};