// Fill out your copyright notice in the Description page of Project Settings.


#include "BallPlayerController.h"
#include "EnhancedInputSubsystems.h"

void ABallPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto Input = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Input->AddMappingContext(ControlsMap, 0);
	
}
