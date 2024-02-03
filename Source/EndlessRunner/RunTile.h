// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RunObstacle.h"
#include "RunPickup.h"
#include "RunTile.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTileExit, class ARunTile*, Tile);//create the exit and return the tile 

UCLASS()
class ENDLESSRUNNER_API ARunTile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARunTile();

	UPROPERTY(BlueprintAssignable)
		FTileExit fTileExit;

	UFUNCTION()
		FTransform AttachedTransform();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void PlayerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void SpawnObstacles();
	UFUNCTION()
		void SpawnItems();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UArrowComponent* AttachPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxObstacle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoxItem;
	UPROPERTY(EditAnywhere, Category = "ObjectClass")
		TArray<TSubclassOf<ARunObstacle>> ArrayObs;
	UPROPERTY(EditAnywhere, Category = "ObjectClass")
		TArray<TSubclassOf<ARunPickup>> ArrayItems;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
