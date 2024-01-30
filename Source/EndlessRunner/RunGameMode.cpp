// Fill out your copyright notice in the Description page of Project Settings.


#include "RunGameMode.h"
#include "RunTile.h"

void ARunGameMode::BeginPlay()
{
	for (int i = 0; i < TileNumber; i++) 
	{
		AddTile();
	}
}

void ARunGameMode::AddTile()
{
	LastArrow = GetWorld()->SpawnActor<ARunTile>(TileClass, transform);

	transform = LastArrow->AttachedTransform();
}
