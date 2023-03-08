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

	// SpawnEmitter���� ����ϱ� ���� ��ƼŬ
	UPROPERTY(EditAnywhere)
	UParticleSystem* HitParticles_;

	// ��ƼŬ ������Ʈ
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* TrailParticles_;

	// �߻� ���� ����Ʈ
	UPROPERTY(EditAnywhere)
	class USoundBase* LaunchSound_;

	// Ÿ�� ���� ����Ʈ
	UPROPERTY(EditAnywhere)
	class USoundBase* HitSound_;

	// ī�޶� ����ũ
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass_;
};
