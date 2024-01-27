// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/Pawn.h"
#include "PongPawn.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class PONGMOBILE_API APongPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	
	APongPawn();

	FORCEINLINE float GetSpeed() { return BaseSpeed; }

	UFUNCTION(BlueprintCallable)
	void SetSpeed(float NewSpeed) { BaseSpeed = NewSpeed; }

protected:
	
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category="PongPawn")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly, Category="PongPawn")
	float BaseSpeed = 200.f;
};
