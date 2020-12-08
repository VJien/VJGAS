// Fill out your copyright notice in the Description page of Project Settings.


#include "Cue/GC_Base.h"
#include "Kismet/KismetSystemLibrary.h"

UGC_Base::~UGC_Base()
{
	UE_LOG(LogTemp, Warning, TEXT("GameplayCue [%s]  GC"), *UKismetSystemLibrary::GetDisplayName(this));
}
