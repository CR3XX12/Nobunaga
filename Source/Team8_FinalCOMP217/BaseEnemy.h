// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemy.generated.h"

UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	E_Default UMETA(DisplayName = "DEFAULT"),
	E_Invincible UMETA(DisplayName = "INVINCIBLE")


};

UCLASS()
class TEAM8_FINALCOMP217_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	ABaseEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int _damage);

	UFUNCTION(BlueprintCallable)
	void Die();
	
	UFUNCTION(BlueprintCallable)
	void BeginInvincibiltyTimer();

	void EndInvincibiltyTimer();

	EEnemyState state;

	FTimerHandle invincibiltyTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float invincibilityTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool IsFacingLeft;

};
