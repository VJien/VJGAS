// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/VGCharacterBase.h"
#include "VGHero.generated.h"

/**
 * 
 */
UCLASS()
class VGAS_API AVGHero : public AVGCharacterBase
{
	GENERATED_UCLASS_BODY()
public:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState()override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;
protected:
	void BindASCInput();


	void MoveForward(float value);
	void MoveRight(float value);
	void LookUp(float value);
	void LookUpRate(float value);
	void Turn(float value);
	void TurnRate(float value);
	void Confirm();
	void Cancel();

public:


protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VGCharacter | Camera")
		float BaseTurnRate = 45.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VGCharacter | Camera")
		float BaseLookUpRate = 45.0f;


private:
	bool bHasBindInput = false;






};
