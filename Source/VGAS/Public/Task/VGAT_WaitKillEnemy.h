// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "VGAT_WaitKillEnemy.generated.h"

class UVGAbilitySystemComponent;
class UGameplayAbility;

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKillEnemy, AActor*, Actor);

UCLASS()
class VGAS_API UVGAT_WaitKillEnemy : public UAbilityTask
{
	GENERATED_UCLASS_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "VGAS | Task", meta = (HidePin = "ownAbility", DefaultToSelf = "ownAbility", BlueprintInternalUseOnly = "TRUE"))
		static UVGAT_WaitKillEnemy* WaitKillEnemey(UGameplayAbility* ownAbility, bool TriggerOnce);
	UFUNCTION()
		void KillEnemy( AActor* enemy);

	bool bTriggerOnece;

	UPROPERTY(BlueprintCallable,BlueprintAssignable)
		FOnKillEnemy OnKillEnemy;


	virtual void Activate()override;
	virtual void OnDestroy(bool bInOwnerFinished)override;



};
