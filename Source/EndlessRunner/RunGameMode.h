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

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class TSubclassOf<class ARunTile>TileClass;

	UPROPERTY(VisibleAnywhere)
		class ARunTile* LastArrow;

	UPROPERTY(VisibleAnywhere)
		FTransform transform;

	void AddTile();

	UPROPERTY(EditAnywhere)
	int TileNumber = 3;
};
