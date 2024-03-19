// Fill out your copyright notice in the Description page of Project Settings.
#include "BasePickup.h"
// Sets default values
ABasePickup::ABasePickup(){
 	// Set this actor to call Tick() every frame.  
	PrimaryActorTick.bCanEverTick = true;

	type = EPickupType::E_Coin;
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
}

