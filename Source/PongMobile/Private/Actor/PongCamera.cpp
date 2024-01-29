// Copyright EdrSantandr Pongmobile


#include "Actor/PongCamera.h"

#include "Camera/CameraComponent.h"

// Sets default values
APongCamera::APongCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
	MeshComponent->SetHiddenInGame(true);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());
}

void APongCamera::BeginPlay()
{
	Super::BeginPlay();
}
