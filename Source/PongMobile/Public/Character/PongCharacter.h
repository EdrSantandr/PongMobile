// Copyright EdrSantandr Pongmobile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PongCharacter.generated.h"

UCLASS()
class PONGMOBILE_API APongCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	APongCharacter();

protected:
	
	virtual void BeginPlay() override;

public:	

};
