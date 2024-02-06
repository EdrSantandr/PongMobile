// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PongBall.generated.h"

class USphereComponent;

UCLASS()
class PONGMOBILE_API APongBall : public ACharacter
{
	GENERATED_BODY()

public:
	APongBall();

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	float GetSpeed(){ return Speed; }

	UPROPERTY(EditDefaultsOnly, Category="PongBall")
	float Speed = 200.f;

	UPROPERTY(EditDefaultsOnly, Category="PongBall")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category="PongBall")
	float BallImpulse = 40000.f;

	UPROPERTY(EditDefaultsOnly, Category="PongBall")
	TObjectPtr<USphereComponent> SphereComponent;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
