// Fill out your copyright notice in the Description page of Project Settings.
#include "BasePickup.h"
// Sets default values
ABasePickup::ABasePickup(){
 	// Set this actor to call Tick() every frame.  
	PrimaryActorTick.bCanEverTick = true;

	type = EPickupType::E_Coin;

	RotationSpeed = 20.0f; // Set rotation speed
	FloatAmplitude = 5.0f; // Set floating amplitude
	FloatSpeed = 5.0f; // Set floating speed
}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Rotation
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += RotationSpeed * DeltaTime;
    SetActorRotation(NewRotation);

    // Floating
    FVector NewLocation = GetActorLocation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime * FloatSpeed) - FMath::Sin(RunningTime)) * FloatAmplitude;
    NewLocation.Z += DeltaHeight;
    RunningTime += DeltaTime;
    SetActorLocation(NewLocation);
}

