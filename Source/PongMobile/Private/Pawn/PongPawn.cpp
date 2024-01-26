// Copyright EdrSantandr Pongmobile


#include "Pawn/PongPawn.h"

#include "Components/BoxComponent.h"

APongPawn::APongPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>("BoxCollisionComponent");
	SetRootComponent(BoxCollisionComponent);

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
}

void APongPawn::BeginPlay()
{
	Super::BeginPlay();
}