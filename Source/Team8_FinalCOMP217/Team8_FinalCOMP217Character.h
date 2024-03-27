// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Team8_FinalCOMP217Character.generated.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	E_Default UMETA(DisplayName = "DEFAULT"),
	E_Invincible UMETA(DisplayName = "INVINCIBLE"),
	E_PwUpPickup_i UMETA(DisplayName = "PWUPINVINCIBLE")

};

UCLASS(config=Game)
class ATeam8_FinalCOMP217Character : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	ATeam8_FinalCOMP217Character();

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int _damageAmount, bool _hitOnLeft);

	UFUNCTION(BlueprintCallable)
	void Die();

	UFUNCTION(BlueprintCallable)
	void Respawn();


	UFUNCTION(BlueprintCallable)
	void BeginInvincibiltyTimer();

	void EndInvincibiltyTimer();

	UFUNCTION(BlueprintCallable)
	void AddCoins(int _numToAdd);

	UFUNCTION(BlueprintCallable)
	void StartInvincibleState(float _pwinvincibleTime);

	void EndInvincibleState();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealthIcons();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ECharacterState state;

	FTimerHandle invincibiltyTimer;

	FTimerHandle PWUPInvincibleTimer;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float invincibilityTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int numCoins;

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
