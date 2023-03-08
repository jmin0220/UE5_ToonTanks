// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <GameFramework/DamageType.h>
#include <Kismet/GameplayStatics.h>
#include <Particles/ParticleSystemComponent.h>
#include <Camera/CameraShakeBase.h>

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BaseMesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile"));
	RootComponent = BaseMesh_;

	ProjectileMovementCom_ = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementCom"));
	ProjectileMovementCom_->MaxSpeed = 1300.f;

	TrailParticles_ = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TrailParticles"));
	TrailParticles_->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	// Hit 이벤트에 콜백함수를 바인딩
	BaseMesh_->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

	if (LaunchSound_)
	UGameplayStatics::PlaySoundAtLocation(this, LaunchSound_, GetActorLocation());
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* _HitCom, AActor* _Other, UPrimitiveComponent* _OtherCom, FVector _normalImpulse, const FHitResult& _Hit)
{

	// ABasePawn::Fire()에서 설정한 Owner를 취득
	auto MyOwner = GetOwner();
	if (MyOwner == nullptr) return;

	auto tmpOwnerInstigator = MyOwner->GetInstigatorController();
	auto DamageTypeClass = UDamageType::StaticClass();


	if (_Other != this && _Other != MyOwner && _Other != nullptr)
	{
		// damage가 0이면 데미지 콜백은 호출되지 않음
		UGameplayStatics::ApplyDamage(_Other, Damage_, tmpOwnerInstigator, this, DamageTypeClass);

		if (HitParticles_)
		{
			// Hit Particle을 생성
			UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles_, GetActorLocation(), GetActorRotation());
		}

		if (HitSound_)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound_, GetActorLocation());

		if (HitCameraShakeClass_)
			GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(HitCameraShakeClass_);

		Destroy();
	}

}

