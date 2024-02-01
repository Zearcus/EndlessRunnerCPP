// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunObstacle.generated.h"

UCLASS()
class ENDLESSRUNNER_API ARunObstacle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARunObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* StaticMesh;

	UFUNCTION(BlueprintImplementableEvent)
		void OnTrigger();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
