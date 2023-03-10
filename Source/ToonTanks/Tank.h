// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APlayerController* GetPlayerController() const
	{
		return PlayerController_;
	}

	// 플레이어가 유요한가를 체크
	bool Alive_ = true;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraCom_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmCom_;

	// 이동속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Speed Variable", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed_ = 400.f;

	// 회전속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Speed Variable", meta = (AllowPrivateAccess = "true"))
	float TurnSpeed_ = 30.f;

	void Move(float _value);

	void Turn(float _value);

	APlayerController* PlayerController_;
};
