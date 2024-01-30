// Fill out your copyright notice in the Description page of Project Settings.


#include "RunTile.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ARunTile::ARunTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	Scene->SetupAttachment(this->GetRootComponent());

	AttachPoint = CreateDefaultSubobject<UArrowComponent>("AttachPoint");
	AttachPoint->SetupAttachment(Scene);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(Scene);
}

// Called when the game starts or when spawned
void ARunTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

