// Fill out your copyright notice in the Description page of Project Settings.


#include "RunPickup.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ARunPickup::ARunPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
}

// Called when the game starts or when spawned
void ARunPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

