// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongWallActor.generated.h"

UCLASS()
class PONGMOBILE_API APongWallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APongWallActor();

protected:
	UPROPERTY(EditDefaultsOnly, Category="PongActor")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
