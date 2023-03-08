// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BaseMesh_;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovementCom_;


	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	float Damage_ = 10.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* _HitCom, AActor* _Other, UPrimitiveComponent* _OtherCom, FVector _normalImpulse, const FHitResult& _Hit);

	// SpawnEmitter에서 사용하기 위한 파티클
	UPROPERTY(EditAnywhere)
	UParticleSystem* HitParticles_;

	// 파티클 컴포넌트
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* TrailParticles_;

	// 발사 사운드 이펙트
	UPROPERTY(EditAnywhere)
	class USoundBase* LaunchSound_;

	// 타격 사운드 이펙트
	UPROPERTY(EditAnywhere)
	class USoundBase* HitSound_;

	// 카메라 쉐이크
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass_;
};
