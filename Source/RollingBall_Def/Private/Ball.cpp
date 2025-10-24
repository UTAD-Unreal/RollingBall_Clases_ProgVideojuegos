// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	//Se hace la jerarquía de componentes
	RootComponent = MyMesh;
	SpringArm->SetupAttachment(MyMesh);
	Camera->SetupAttachment(SpringArm);

	MyMesh->SetSimulatePhysics(true);
	MyMesh->SetMassOverrideInKg(NAME_None, 100);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hola mundo!"));
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
}


// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (Input != nullptr)
	{
		//Cuando MoveAction esté en Triggered (continua), la función "Move" se va a ejecutar.
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABall::Move);
		Input->BindAction(JumpAction, ETriggerEvent::Started, this, &ABall::Jump);
	}

}

void ABall::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputVector = InputActionValue.Get<FVector2D>();

	MyMesh->AddForce(FVector(InputVector.Y, InputVector.X, 0) * Force);
}

void ABall::Jump()
{
	FVector RayEnd = GetActorLocation() + MyMesh->GetCollisionShape().GetExtent().Z * FVector::DownVector;

	DrawDebugLine(GetWorld(), GetActorLocation(), RayEnd, FColor::Red, false, 2);
	if (GetWorld()->LineTraceTestByChannel(GetActorLocation(), RayEnd, ECC_GameTraceChannel1))
	{
		MyMesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
		MyMesh->AddImpulse(FVector::UpVector * JumpForce);
	}
}

