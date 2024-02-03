// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunPickup.generated.h"

UCLASS()
class ENDLESSRUNNER_API ARunPickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARunPickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void OnGet();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
