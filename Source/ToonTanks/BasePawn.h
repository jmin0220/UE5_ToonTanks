// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandleDestruction();
protected:
	void RotateTurret(FVector _LookAtTarget);
	void Fire();

	
	// ��Ʈ ������Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleCom_;

	// ��ũ ��ü
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh_;

	// ��ũ ��ü
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh_;

	// �Ѿ��� ������ ����Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint_;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	float CapsulePosition_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	float ProjectileSpawnPointPosition_;

	// AProjectileŸ���� Ŭ������ ��밡���ϰ� �ϴ� ���ø�Ŭ����
	// AProjectile�� �׳� ����ϸ� �Ļ�Ŭ������ ������ ���������� TSubclassOf�� AProjectile�� ����� �� �ְ� ���ѵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AProjectile> Projectile_;

	/*
		// VisibleAnywhere �������� ������ �� ����
		// BlueprintReadWrite �������Ʈ �̺�Ʈ �׷������� Get, Set�� ��� �� �� ����
		// meta = (AllowPrivateAccess = "true") private������ �̺�Ʈ �׷������� ������ �� ����
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		int32 VisibleAnywhereInt = 12;

		// EditAnywhere ���̰� ������ �� ����
		// BlueprintReadOnly �������Ʈ �̺�Ʈ �׷������� Get�� �� �� ����
		UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		int32 EditAnywhereInt = 22;

		// VisibleInstanceOnly Outliner�� Detail������ �� �� ���� -> outliner�� Ŭ������ Instance
		// �������Ʈ(default)���� Ȯ���� �� �ִ� ���� Class�� �⺻ �Ӽ���
		UPROPERTY(VisibleInstanceOnly)
		int32 VisibleInstanceOnlyInt = 12;
	*/
};
