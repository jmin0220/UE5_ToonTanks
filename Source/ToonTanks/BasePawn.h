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

protected:
	void RotateTurret(FVector _LookAtTarget);
	void Fire();

	
	// 루트 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleCom_;

	// 탱크 하체
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh_;

	// 탱크 상체
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh_;

	// 총알을 생성할 포인트
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Infomation", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint_;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	float CapsulePosition_;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	float ProjectileSpawnPointPosition_;


	/*
		// VisibleAnywhere 보이지만 편집할 수 없음
		// BlueprintReadWrite 블루프린트 이벤트 그래프에서 Get, Set을 모두 할 수 있음
		// meta = (AllowPrivateAccess = "true") private이지만 이벤트 그래프에서 접근할 수 있음
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		int32 VisibleAnywhereInt = 12;

		// EditAnywhere 보이고 편집할 수 있음
		// BlueprintReadOnly 블루프린트 이벤트 그래프에서 Get만 할 수 있음
		UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		int32 EditAnywhereInt = 22;

		// VisibleInstanceOnly Outliner의 Detail에서만 볼 수 있음 -> outliner는 클래스의 Instance
		// 블루프린트(default)에서 확인할 수 있는 것은 Class의 기본 속성임
		UPROPERTY(VisibleInstanceOnly)
		int32 VisibleInstanceOnlyInt = 12;
	*/
};
