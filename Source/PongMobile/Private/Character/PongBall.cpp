// Copyright EdrSantandr Pongmobile


#include "Character/PongBall.h"

#include "Character/PongCharacter.h"
#include "Components/CapsuleComponent.h"
#include "PongMobile/PongMobile.h"

APongBall::APongBall()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(GetRootComponent());
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pong,ECR_Overlap);
}

void APongBall::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APongBall::OnBeginOverlap);
}

void APongBall::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("pongballl other actor: %s"), *OtherActor->GetName());
	// Activate an impulse effect contrary to the impact point and speed up the ball movement
	// Impulse to ball
	FVector Direction = (OtherActor->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	FVector DirectionInverse = Direction * -1;
	LaunchCharacter(DirectionInverse*BallImpulse, true,false);

	// Impulse to character
	if (APongCharacter* PongCharacter = Cast<APongCharacter>(OtherActor))
	{
		PongCharacter->LaunchCharacter(Direction*PongCharacter->GetCharacterImpulse(), true,false);
	}
}
