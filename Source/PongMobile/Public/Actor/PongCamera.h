// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongCamera.generated.h"

class UCameraComponent;

UCLASS()
class PONGMOBILE_API APongCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	APongCamera();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FVector CameraLocation = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FRotator CameraRotation = FRotator::ZeroRotator;
};

