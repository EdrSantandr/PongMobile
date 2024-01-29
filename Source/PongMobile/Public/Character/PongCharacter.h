// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PongCharacter.generated.h"

class UBoxComponent;

UCLASS()
class PONGMOBILE_API APongCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	APongCharacter();

protected:

public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	float GetSpeed(){ return Speed; }

	UPROPERTY(EditDefaultsOnly, Category="PongCharacter")
	float Speed = 200.f;

	UPROPERTY(EditDefaultsOnly, Category="PongCharacter")
	TObjectPtr<UBoxComponent> BoxComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="PongCharacter")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
