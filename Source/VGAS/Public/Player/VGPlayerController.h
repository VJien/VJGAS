// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VGAS_API AVGPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void OnPossess(APawn* aPawn) override;
};
