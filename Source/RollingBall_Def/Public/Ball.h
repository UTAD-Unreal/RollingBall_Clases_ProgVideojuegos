// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "Ball.generated.h"

UCLASS()
class ROLLINGBALL_DEF_API ABall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	void Move(const FInputActionValue& InputActionValue);


	void Jump();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category= "Mis variables") //EditAnywhere, EditDefaultsOnly, EditInstanceOnly
	UStaticMeshComponent* MyMesh;
	
	UPROPERTY(EditDefaultsOnly, Category= "Mis variables")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category= "Mis variables")
	class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, Category= "Mis variables")
	class UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category= "Mis variables")
	UInputAction* JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category= "Mis variables")
	float Force;

	UPROPERTY(EditDefaultsOnly, Category= "Mis variables")
	float JumpForce;
};
