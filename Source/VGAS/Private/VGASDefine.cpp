// Fill out your copyright notice in the Description page of Project Settings.


#include "VGASDefine.h"

DEFINE_LOG_CATEGORY(VGAS)

FGameplayAbilitySpec FVGASpec::ToGASpec()
{
	FGameplayAbilitySpec sp = FGameplayAbilitySpec(Ability, Level, InputID, SourceObject);
	sp.Handle = Handle;
	sp.ActivationInfo = ActivationInfo;
	sp.ActiveCount = ActiveCount;
	sp.InputPressed = InputPressed;
	sp.RemoveAfterActivation = RemoveAfterActivation;
	sp.PendingRemove = PendingRemove;
	sp.bActivateOnce = bActivateOnce;
	sp.NonReplicatedInstances = NonReplicatedInstances;
	sp.ReplicatedInstances = ReplicatedInstances;
	sp.GameplayEffectHandle = GameplayEffectHandle;
	return sp;
}
