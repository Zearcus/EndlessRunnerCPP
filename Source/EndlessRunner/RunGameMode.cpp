// Fill out your copyright notice in the Description page of Project Settings.


#include "RunGameMode.h"
#include "RunTile.h"
#include "TimerManager.h"

void ARunGameMode::BeginPlay()
{
	for (int i = 0; i < TileNumber; i++) 
	{
		//Spawn first Tile in 0.0.0
		if (!LastArrow) {
			LastArrow = GetWorld()->SpawnActor<ARunTile>(TileClass);
			transform = LastArrow->AttachedTransform();
			//call AddTile when message is receive
			LastArrow->fTileExit.AddDynamic(this, &ARunGameMode::AddTile);

		}
		else {//Spawn Tile with number
			LastArrow = GetWorld()->SpawnActor<ARunTile>(TileClass, transform);
			//call AddTile when message is receive
			LastArrow->fTileExit.AddDynamic(this, &ARunGameMode::AddTile);
		}
	}
}

void ARunGameMode::Timer()
{
	GetWorldTimerManager().SetTimer(
		fTimerHandle, // handle to cancel timer at a later time
		this, // the owning object
		&ARunGameMode::DestroyTile, // function to call on elapsed
		Time,
		false);
}

void ARunGameMode::DestroyTile()
{
	LastArrow->Destroy();
	UE_LOG(LogTemp, Warning, TEXT("MDR"));
}

void ARunGameMode::AddTile(ARunTile* Tile)
{
	LastArrow = GetWorld()->SpawnActor<ARunTile>(TileClass, transform);
	//set the new Arrow for spawning the next tile
	transform = LastArrow->AttachedTransform();
	//call AddTile when message is receive
	LastArrow->fTileExit.AddDynamic(this, &ARunGameMode::AddTile);
	Timer();
}
