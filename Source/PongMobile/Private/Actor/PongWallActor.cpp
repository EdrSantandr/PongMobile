// Copyright EdrSantandr Pongmobile


#include "Actor/PongWallActor.h"

APongWallActor::APongWallActor()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
}
