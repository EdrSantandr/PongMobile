// Copyright EdrSantandr Pongmobile


#include "Player/PongPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

APongPlayerController::APongPlayerController()
{
	bReplicates = true;
}

void APongPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(PongContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem =ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(PongContext, 0);
	bShowMouseCursor = false;
	FInputModeGameAndUI InputModeGameAndUI;
	InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputModeGameAndUI.SetHideCursorDuringCapture(true);
	SetInputMode(InputModeGameAndUI);
}

void APongPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APongPlayerController::Move);	
}

void APongPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	
}
