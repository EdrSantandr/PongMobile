// Copyright EdrSantandr Pongmobile


#include "Pawn/PongPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/PongPlayerState.h"
#include "PongMobile/PongMobile.h"

APongPawn::APongPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent= CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	BoxComponent->SetupAttachment(GetRootComponent());
	
	BoxComponent->SetCollisionObjectType(ECC_Pong);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	BoxComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
}

void APongPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (APongPlayerState* PongPlayerState = Cast<APongPlayerState>(GetPlayerState()))
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(NewController))
		{
			AActor* PongCamera = PongPlayerState->SpawnPlayerCameraActor();
			PlayerController->SetViewTargetWithBlend(PongCamera,0.f);
		}
	}
}

void APongPawn::BeginPlay()
{
	Super::BeginPlay();
	
}
