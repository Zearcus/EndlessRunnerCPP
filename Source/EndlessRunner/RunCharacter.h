// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunCharacter.generated.h"

UCLASS()
class ENDLESSRUNNER_API ARunCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunCharacter();

	UPROPERTY(VisibleAnywhere)
	bool isDead = false;

	UFUNCTION(BlueprintCallable)
	void Die();
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* SpringArm;

	UFUNCTION(BlueprintCallable)
		void AddCoins();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Coins = 0;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
