// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	state = EEnemyState::E_Default;
	invincibilityTime = 1.0f;
	health = 1;

}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEnemy::TakeDamage(int _damage)
{
	health -= _damage;

	if (state != EEnemyState::E_Invincible)
	{
		if (health - _damage > 0)
		{
			health -= _damage;
			BeginInvincibiltyTimer();
		}
		else
		{
			Die();
		}
	}
}

void ABaseEnemy::Die()
{
	Destroy();
}

void ABaseEnemy::BeginInvincibiltyTimer()
{
	UE_LOG(LogTemp, Warning, TEXT("The Enemy is invincible"));
	GetWorld()->GetTimerManager().SetTimer(invincibiltyTimer, this, &ABaseEnemy::EndInvincibiltyTimer, invincibilityTime, false);
	state = EEnemyState::E_Invincible;
}

void ABaseEnemy::EndInvincibiltyTimer()
{
	state = EEnemyState::E_Default;
}