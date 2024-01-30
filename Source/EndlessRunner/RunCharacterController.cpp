// Fill out your copyright notice in the Description page of Project Settings.


#include "RunCharacterController.h"
#include "RunCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ARunCharacterController::BeginPlay()
{
	Super::BeginPlay();
	RunCharacter = Cast<ARunCharacter>(GetPawn());
}

void ARunCharacterController::MoveRight(float scale)
{
	RunCharacter->GetCharacterMovement()->AddInputVector(RunCharacter->GetActorRightVector() * scale);
}

void ARunCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &ARunCharacterController::MoveRight);
}

void ARunCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunCharacter->GetCharacterMovement()->AddInputVector(RunCharacter->GetActorForwardVector());
}
