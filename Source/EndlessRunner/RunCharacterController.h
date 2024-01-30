// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RunCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API ARunCharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
protected:

	class ARunCharacter* RunCharacter;

	UFUNCTION()
	void MoveRight(float scale);

	virtual void SetupInputComponent() override;

public:

	virtual void Tick(float DeltaTime) override;
};
