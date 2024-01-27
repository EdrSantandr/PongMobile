// Copyright EdrSantandr Pongmobile


#include "Pawn/PongPawn.h"

#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"
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

void APongPawn::BeginPlay()
{
	Super::BeginPlay();
}
