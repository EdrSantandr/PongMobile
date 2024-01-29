// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PongPlayerState.generated.h"

class APongCamera;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class PONGMOBILE_API APongPlayerState : public APlayerState
{
	GENERATED_BODY()

	APongPlayerState();

public:
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FVector CameraLocation = FVector::ZeroVector;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FRotator CameraRotation = FRotator::ZeroRotator;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TSubclassOf<APongCamera> PongCameraClass;

	UPROPERTY()
	APongCamera* PongCamera;
	
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<AActor> CameraActor;

	UFUNCTION(BlueprintCallable)
	AActor* SpawnPlayerCameraActor();
};
