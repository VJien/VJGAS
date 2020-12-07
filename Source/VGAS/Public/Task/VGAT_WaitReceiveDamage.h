// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "VGAT_WaitReceiveDamage.generated.h"

class UVGAbilitySystemComponent;
class UGameplayAbility;

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRecieveDamageDlg, UVGAbilitySystemComponent*, AbilityComponent, float, Damage);

UCLASS()
class VGAS_API UVGAT_WaitReceiveDamage : public UAbilityTask
{
	GENERATED_UCLASS_BODY()

public:
	virtual void Activate()override;
	virtual void OnDestroy(bool bInOwnerFinished)override;

	UFUNCTION(BlueprintCallable)
	static UVGAT_WaitReceiveDamage* WaitReceiveOwnnerDamage(UGameplayAbility* ownAbility, bool TriggerOnce);

	UFUNCTION()
		void OnDamageReceived(UVGAbilitySystemComponent* SourceASC, float damage);
public:
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FOnRecieveDamageDlg OnReceiveDamage;


	UPROPERTY(BlueprintReadOnly,EditAnywhere)
		bool bTriggerOnce;
};
