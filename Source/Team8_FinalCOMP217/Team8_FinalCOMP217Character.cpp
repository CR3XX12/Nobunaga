// Copyright Epic Games, Inc. All Rights Reserved.

#include "Team8_FinalCOMP217Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ATeam8_FinalCOMP217Character::ATeam8_FinalCOMP217Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	state = ECharacterState::E_Default;
	invincibilityTime = 1.0f;
	health = 3;
}


//////////////////////////////////////////////////////////////////////////
// Input

void ATeam8_FinalCOMP217Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATeam8_FinalCOMP217Character::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATeam8_FinalCOMP217Character::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATeam8_FinalCOMP217Character::TouchStopped);
}

void ATeam8_FinalCOMP217Character::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void ATeam8_FinalCOMP217Character::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ATeam8_FinalCOMP217Character::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

void ATeam8_FinalCOMP217Character::TakeDamage(int _damageAmount, bool _hitOnLeft)
{	
	if (state != ECharacterState::E_Invincible)
	{
		if (health - _damageAmount < 0)
		{
			health = 0;
			Die();
		}
		else {
			health -= _damageAmount;
			BeginInvincibiltyTimer();			

			if (_hitOnLeft)
			{
				LaunchCharacter(FVector(0.0f, -800.0f, 700.0f), false, false);
			}
			else
			{
				LaunchCharacter(FVector(0.0f, 800.0f, 700.0f), false, false);
			}
		}
	}
}

void ATeam8_FinalCOMP217Character::Die()
{
	Destroy();
}

void ATeam8_FinalCOMP217Character::BeginInvincibiltyTimer()
{
	UE_LOG(LogTemp, Warning, TEXT("The player is invincible"));
	GetWorld()->GetTimerManager().SetTimer(invincibiltyTimer, this, &ATeam8_FinalCOMP217Character::EndInvincibiltyTimer, invincibilityTime, false);
	state = ECharacterState::E_Invincible;
}

void ATeam8_FinalCOMP217Character::EndInvincibiltyTimer()
{
	state = ECharacterState::E_Default;
}