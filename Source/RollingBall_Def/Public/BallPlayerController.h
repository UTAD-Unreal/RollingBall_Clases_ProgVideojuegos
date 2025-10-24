// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BallPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ROLLINGBALL_DEF_API ABallPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Inputs")
	class UInputMappingContext* ControlsMap;
	
};
