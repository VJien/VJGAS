// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/VGPlayerController.h"
#include "Player/VGPlayerState.h"
#include "AbilitySystemComponent.h"





void AVGPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	AVGPlayerState* PS = GetPlayerState<AVGPlayerState>();
	if (PS)
	{
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, aPawn);
		
	}
}
