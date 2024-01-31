// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RunGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNER_API ARunGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void AddTile(ARunTile* Tile);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class TSubclassOf<class ARunTile>TileClass;

	UPROPERTY(VisibleAnywhere)
		class ARunTile* LastArrow;

	UPROPERTY(VisibleAnywhere)
		FTransform transform;

	UPROPERTY(VisibleAnywhere)
		FTimerHandle fTimerHandle;

	UFUNCTION()
		void Timer();
	UFUNCTION()
		void DestroyTile();


	UPROPERTY(EditAnywhere)
	int TileNumber;

	UPROPERTY(EditAnywhere)
		float Time;
};
