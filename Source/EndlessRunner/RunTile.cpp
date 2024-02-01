// Fill out your copyright notice in the Description page of Project Settings.


#include "RunTile.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "RunCharacter.h"


// Sets default values
ARunTile::ARunTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	SetRootComponent(Scene);

	AttachPoint = CreateDefaultSubobject<UArrowComponent>("AttachPoint");
	AttachPoint->SetupAttachment(Scene);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(Scene);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ARunTile::PlayerOverlap);

	SpawnObstacle = CreateDefaultSubobject<UBoxComponent>("SpawnObstacle");
	SpawnObstacle->SetupAttachment(Scene);
}

// Called when the game starts or when spawned
void ARunTile::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnObstacles();
}

void ARunTile::PlayerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Send message if is RunCharacter overlap
	if (ARunCharacter* RunCharacter = Cast<ARunCharacter>(OtherActor)) {
		fTileExit.Broadcast(this);//Send message is Exited
	}
}

void ARunTile::SpawnObstacles()
{
	if (Array.Num() > 0) {
		UChildActorComponent* obstacle = NewObject<UChildActorComponent>(this, "Obstacle");
		obstacle->SetChildActorClass(Array[FMath::RandHelper(Array.Num() - 1)]);//call Random bounding box
		obstacle->RegisterComponent();
		obstacle->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
		obstacle->SetRelativeLocation(UKismetMathLibrary::RandomPointInBoundingBox(SpawnObstacle->GetRelativeLocation(), SpawnObstacle->GetScaledBoxExtent()));
	}
}

FTransform ARunTile::AttachedTransform()
{
	return AttachPoint->GetComponentTransform();
}

// Called every frame
void ARunTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

