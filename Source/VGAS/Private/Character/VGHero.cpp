// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VGHero.h"
#include "Player/VGPlayerState.h"
#include "AbilitySystemComponent.h"
#include "Component/VGAbilitySystemComponent.h"
#include "VGASDefine.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Attribute/VGAttributeSet.h"

AVGHero::AVGHero(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}

// Server only
void AVGHero::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AVGPlayerState* PS = GetPlayerState<AVGPlayerState>();
	if (PS)
	{
		AbilitySystemComponent = Cast<UVGAbilitySystemComponent>(PS->GetAbilitySystemComponent());

		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);

		AttributeSet = PS->GetAttributeSet();



		InitAttributes();
		AddStartUpEffects();
		AddCharacterAbilities();
	}
}

// Client only
void AVGHero::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	AVGPlayerState* PS = GetPlayerState<AVGPlayerState>();
	if (PS)
	{
		AbilitySystemComponent = Cast<UVGAbilitySystemComponent>(PS->GetAbilitySystemComponent());

		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);

		AttributeSet = PS->GetAttributeSet();

		BindASCInput();

		InitAttributes();
	}
}

void AVGHero::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AVGHero::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AVGHero::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AVGHero::LookUp);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AVGHero::LookUpRate);
	PlayerInputComponent->BindAxis("Turn", this, &AVGHero::Turn);
	PlayerInputComponent->BindAxis("TurnRate", this, &AVGHero::TurnRate);

	BindASCInput();
}

void AVGHero::BindASCInput()
{
	if (!bHasBindInput && AbilitySystemComponent.IsValid() && InputComponent)
	{
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, FGameplayAbilityInputBinds(TEXT("CONFIRM"), TEXT("CANCEL"),
			TEXT("EVGAbilityInputID"), static_cast<int32>(EVGAbilityInputID::CONFIRM), static_cast<int32>(EVGAbilityInputID::CANCEL)));
		bHasBindInput = true;
	}
}

void AVGHero::MoveForward(float value)
{
	FRotator rot = GetBaseAimRotation();
	AddMovementInput(UKismetMathLibrary::GetForwardVector(rot), value);
}

void AVGHero::MoveRight(float value)
{
	FRotator rot = GetBaseAimRotation();
	AddMovementInput(UKismetMathLibrary::GetRightVector(rot), value);
}

void AVGHero::LookUp(float value)
{
	if (IsAlive())
	{
		this->AddControllerPitchInput(value);
	}
	
}

void AVGHero::LookUpRate(float value)
{

	if (IsAlive())
	{
		this->AddControllerPitchInput(value * BaseLookUpRate * GetWorld()->DeltaTimeSeconds);
	}
}

void AVGHero::Turn(float value)
{
	if (IsAlive())
	{
		this->AddControllerYawInput(value);
	}
	
}

void AVGHero::TurnRate(float value)
{
	if (IsAlive())
	{
		this->AddControllerYawInput(value * BaseTurnRate * GetWorld()->DeltaTimeSeconds);
	}
}

void AVGHero::Confirm()
{

}

void AVGHero::Cancel()
{

}
