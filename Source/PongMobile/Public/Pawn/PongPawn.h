// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PongPawn.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class PONGMOBILE_API APongPawn : public APawn
{
	GENERATED_BODY()

public:
	
	APongPawn();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="PongPawn")
	TObjectPtr<UBoxComponent> BoxCollisionComponent;
	
	UPROPERTY(EditAnywhere, Category="PongPawn")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	

};
