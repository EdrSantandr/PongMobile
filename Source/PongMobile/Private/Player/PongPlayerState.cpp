// Copyright EdrSantandr Pongmobile


#include "Player/PongPlayerState.h"

#include "Actor/PongCamera.h"

APongPlayerState::APongPlayerState()
{
}

void APongPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

AActor* APongPlayerState::SpawnPlayerCameraActor()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	const FVector Location = CameraLocation;
	const FRotator Rotation = CameraRotation;
	PongCamera = GetWorld()->SpawnActor<APongCamera>(PongCameraClass,Location, Rotation, SpawnParameters);
	return  PongCamera;
}
