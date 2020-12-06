// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"
#include "GameplayEffect.h"
#include "VGASDefine.generated.h"

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

USTRUCT(BlueprintType)
struct FVGASpec
{
	GENERATED_BODY()
public:
	FVGASpec() 
	{};
	FVGASpec(const FGameplayAbilitySpec& GASpec):Handle(GASpec.Handle),Ability(GASpec.Ability),Level(GASpec.Level),InputID(GASpec.InputID),
		SourceObject(GASpec.SourceObject),ActiveCount(GASpec.ActiveCount),InputPressed(GASpec.InputPressed),RemoveAfterActivation(GASpec.RemoveAfterActivation),
		PendingRemove(GASpec.PendingRemove),bActivateOnce(GASpec.bActivateOnce), GameplayEffectHandle(GASpec.GameplayEffectHandle)
	{}


	FGameplayAbilitySpec ToGASpec();



	UPROPERTY(BlueprintReadWrite)
		FGameplayAbilitySpecHandle Handle;
	
	UPROPERTY(BlueprintReadWrite)
		UGameplayAbility* Ability;
	
	UPROPERTY(BlueprintReadWrite)
		int32	Level;
	
	UPROPERTY(BlueprintReadWrite)
		int32	InputID;
	
	UPROPERTY(BlueprintReadWrite)
		UObject* SourceObject;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint8 ActiveCount;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint8 InputPressed : 1;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint8 RemoveAfterActivation : 1;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint8 PendingRemove : 1;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint8 bActivateOnce : 1;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		FGameplayAbilityActivationInfo	ActivationInfo;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		TArray<UGameplayAbility*> NonReplicatedInstances;

	UPROPERTY(BlueprintReadWrite)
		TArray<UGameplayAbility*> ReplicatedInstances;

	UPROPERTY(NotReplicated, BlueprintReadWrite)
		FActiveGameplayEffectHandle	GameplayEffectHandle;
};




USTRUCT(BlueprintType)
struct FVGESpec
{
	GENERATED_BODY()
public:
	FVGESpec()
	{};
	FVGESpec(const FGameplayEffectSpec& GESpec) :Def(GESpec.Def), ModifiedAttributes(GESpec.ModifiedAttributes), CapturedRelevantAttributes(GESpec.CapturedRelevantAttributes),
		TargetEffectSpecs(GESpec.TargetEffectSpecs), Duration(GESpec.Duration), Period(GESpec.Period), ChanceToApplyToTarget(GESpec.ChanceToApplyToTarget),
		CapturedSourceTags(GESpec.CapturedSourceTags),CapturedTargetTags(GESpec.CapturedTargetTags), DynamicGrantedTags(GESpec.DynamicGrantedTags), DynamicAssetTags(GESpec.DynamicAssetTags),
		Modifiers(GESpec.Modifiers), StackCount(GESpec.StackCount), bCompletedSourceAttributeCapture(GESpec.bCompletedSourceAttributeCapture), 
		bCompletedTargetAttributeCapture(GESpec.bCompletedTargetAttributeCapture), bDurationLocked(GESpec.bDurationLocked), GrantedAbilitySpecs(GESpec.GrantedAbilitySpecs),
		SetByCallerNameMagnitudes(GESpec.SetByCallerNameMagnitudes), SetByCallerTagMagnitudes(GESpec.SetByCallerTagMagnitudes)
	{}


	UPROPERTY(BlueprintReadWrite)
		const UGameplayEffect* Def;

	/** A list of attributes that were modified during the application of this spec */
	UPROPERTY()
		TArray<FGameplayEffectModifiedAttribute> ModifiedAttributes;

	/** Attributes captured by the spec that are relevant to custom calculations, potentially in owned modifiers, etc.; NOT replicated to clients */
	UPROPERTY(NotReplicated)
		FGameplayEffectAttributeCaptureSpecContainer CapturedRelevantAttributes;

	/** other effects that need to be applied to the target if this effect is successful */
	UPROPERTY(BlueprintReadWrite)
	TArray< FGameplayEffectSpecHandle > TargetEffectSpecs;

	/**
	 * The duration in seconds of this effect
	 * instantaneous effects should have a duration of FGameplayEffectConstants::INSTANT_APPLICATION
	 * effects that last forever should have a duration of FGameplayEffectConstants::INFINITE_DURATION
	 */
	UPROPERTY(BlueprintReadWrite)
		float Duration;

	/** The period in seconds of this effect, nonperiodic effects should have a period of FGameplayEffectConstants::NO_PERIOD */
	UPROPERTY(BlueprintReadWrite)
		float Period;

	/** The chance, in a 0.0-1.0 range, that this GameplayEffect will be applied to the target Attribute or GameplayEffect */
	UPROPERTY(BlueprintReadWrite)
		float ChanceToApplyToTarget;

	/** Captured Source Tags on GameplayEffectSpec creation */
	UPROPERTY(NotReplicated)
		FTagContainerAggregator	CapturedSourceTags;

	/** Tags from the target, captured during execute */
	UPROPERTY(NotReplicated)
		FTagContainerAggregator	CapturedTargetTags;

	/** Tags that are granted and that did not come from the UGameplayEffect def. These are replicated. */
	UPROPERTY(BlueprintReadWrite)
		FGameplayTagContainer DynamicGrantedTags;

	/** Tags that are on this effect spec and that did not come from the UGameplayEffect def. These are replicated. */
	UPROPERTY(BlueprintReadWrite)
		FGameplayTagContainer DynamicAssetTags;

	/** The calcuated modifiers for this effect */
	UPROPERTY()
		TArray<FModifierSpec> Modifiers;

	/** Total number of stacks of this effect */
	UPROPERTY(BlueprintReadWrite)
		int32 StackCount;

	/** Whether the spec has had its source attribute capture completed or not yet */
	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint32 bCompletedSourceAttributeCapture : 1;

	/** Whether the spec has had its target attribute capture completed or not yet */
	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint32 bCompletedTargetAttributeCapture : 1;

	/** Whether the duration of the spec is locked or not; If it is, attempts to set it will fail */
	UPROPERTY(NotReplicated, BlueprintReadWrite)
		uint32 bDurationLocked : 1;

	/** List of abilities granted by this effect */
	UPROPERTY(BlueprintReadWrite)
		TArray<FGameplayAbilitySpecDef> GrantedAbilitySpecs;

	/** Map of set by caller magnitudes */
	UPROPERTY(BlueprintReadWrite)
	TMap<FName, float>			SetByCallerNameMagnitudes;
	UPROPERTY(BlueprintReadWrite)
	TMap<FGameplayTag, float>	SetByCallerTagMagnitudes;

};