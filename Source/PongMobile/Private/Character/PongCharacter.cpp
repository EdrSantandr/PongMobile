// Copyright EdrSantandr Pongmobile


#include "Character/PongCharacter.h"

#include "Components/BoxComponent.h"
#include "Player/PongPlayerState.h"
#include "PongMobile/PongMobile.h"


APongCharacter::APongCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(MeshComponent);
	BoxComponent->SetCollisionResponseToChannels(ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECC_Pong,ECR_Overlap);
}

void APongCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APongPlayerState* PongPlayerState = Cast<APongPlayerState>(GetPlayerState()))
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		{
			AActor* PongCamera = PongPlayerState->SpawnPlayerCameraActor();
			PlayerController->SetViewTargetWithBlend(PongCamera,0.f);
		}
	}
}