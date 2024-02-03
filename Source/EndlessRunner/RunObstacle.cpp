// Fill out your copyright notice in the Description page of Project Settings.


#include "RunObstacle.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARunObstacle::ARunObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(this->GetRootComponent());

}

// Called when the game starts or when spawned
void ARunObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

