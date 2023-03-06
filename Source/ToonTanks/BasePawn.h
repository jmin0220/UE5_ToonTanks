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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
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
	



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleCom_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint_;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	float CapsulePosition_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	float ProjectileSpawnPointPosition_;

};
