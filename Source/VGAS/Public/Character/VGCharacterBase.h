// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "VGCharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKillOthers,AActor*, Actor);

UCLASS()
class VGAS_API AVGCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_UCLASS_BODY()

public:
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Implement IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//初始化属性
	virtual void InitAttributes();
	//添加技能
	virtual void AddCharacterAbilities();
	//添加初始效果
	virtual void AddStartUpEffects();

	
	UFUNCTION(BlueprintCallable, Category = "VGAS | VGCharacter | Attributes")
		int32 GetCharacterLevel()const;
	UFUNCTION(BlueprintCallable, Category = "VGAS | VGCharacter")
		int32 GetAbilityLevel(EVGAbilityInputID intpuID)const;
	UFUNCTION(BlueprintCallable, Category = "VGAS | VGCharacter")
		bool IsAlive()const;




	/*getter attributes from attributeSet*/
	
	UFUNCTION(BlueprintCallable, Category = "VGAS | VGCharacter")
		float GetHealth()const;
	UFUNCTION(BlueprintCallable, Category = "VGAS | VGCharacter")
		float GetMaxHealth()const;
	UFUNCTION(BlueprintCallable, Category = "VGAS | VGCharacter")
		float GetMana()const;
	UFUNCTION(BlueprintCallable, Category = "VGAS | VGCharacter")
		float GetMaxMana()const;



	/*getter attributes from attributeSet end*/

protected:

	TWeakObjectPtr<class UVGAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<class UVGAttributeSet> AttributeSet;

public:

	//角色技能
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VGAS | Abilities")
		TArray<TSubclassOf<class UVGGameplayAbility>> CharacterAbilities;

	//初始效果,用来初始化属性
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VGAS | Abilities")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	//初始应用的GE效果
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VGAS | Abilities")
		TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;



	UPROPERTY(BlueprintCallable,BlueprintAssignable)
		FOnKillOthers	OnKillEnmey;
};
