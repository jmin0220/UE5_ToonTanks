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

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraCom_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmCom_;

	// 이동속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Speed Variable", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed_ = 400.f;

	void Move(float _value);
};
