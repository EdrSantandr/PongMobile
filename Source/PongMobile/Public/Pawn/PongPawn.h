// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/Pawn.h"
#include "PongPawn.generated.h"

class UCameraComponent;
class UBoxComponent;

UCLASS(Abstract)
class PONGMOBILE_API APongPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	
	APongPawn();

	FORCEINLINE float GetSpeed() const { return BaseSpeed; }

	UFUNCTION(BlueprintCallable)
	void SetSpeed(float NewSpeed) { BaseSpeed = NewSpeed; }

	virtual void PossessedBy(AController* NewController) override;

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="PongPawn")
	TObjectPtr<UBoxComponent> BoxComponent;

	UPROPERTY(EditDefaultsOnly, Category="PongPawn")
	float BaseSpeed = 200.f;
};
