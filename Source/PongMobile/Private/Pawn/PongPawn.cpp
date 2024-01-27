// Copyright EdrSantandr Pongmobile


#include "Pawn/PongPawn.h"

#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"

APongPawn::APongPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
	
}

void APongPawn::BeginPlay()
{
	Super::BeginPlay();
}
