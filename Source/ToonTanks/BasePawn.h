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

	// AProjectile타입의 클래스만 사용가능하게 하는 탬플릿클래스
	// AProjectile을 그냥 사용하면 파생클래스도 선언이 가능하지만 TSubclassOf는 AProjectile만 사용할 수 있게 제한됨
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Component Positions", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AProjectile> Projectile_;

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
