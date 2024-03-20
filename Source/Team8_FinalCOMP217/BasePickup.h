// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

UENUM(BlueprintType)
enum class EPickupType : uint8
{
	E_Coin UMETA(DisplayName = "COIN"),
	E_PwUp UMETA(DisplayName = "PWUP")

};

UCLASS()
class TEAM8_FINALCOMP217_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickup();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere) 
	EPickupType type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Properties")
	float RotationSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Properties")
	float FloatAmplitude;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Properties")
	float FloatSpeed;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

private:
	float RunningTime;

};
