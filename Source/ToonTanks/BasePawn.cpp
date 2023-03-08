// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 캡슐 컴포넌트를 생성후, 생성된 캡슐 컴포넌트를 Root로 설정
	CapsuleCom_ = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsulCollider"));
	RootComponent = CapsuleCom_;

	// BaseMesh를 Root에 Attachment
	BaseMesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh_->SetupAttachment(CapsuleCom_);

	// Turret을 BaseMesh에 Attachment
	TurretMesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh_->SetupAttachment(BaseMesh_);

	ProjectileSpawnPoint_ = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint_->SetupAttachment(TurretMesh_);
}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasePawn::HandleDestruction()
{
	// 이펙트 및 사운드효과 발생
}

void ABasePawn::RotateTurret(FVector _LookAtTarget)
{
	FVector ToTarget = _LookAtTarget - TurretMesh_->GetComponentLocation();

	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurretMesh_->SetWorldRotation(
		FMath::RInterpTo(TurretMesh_->GetComponentRotation(), LookAtRotation, UGameplayStatics::GetWorldDeltaSeconds(this), 15.f));
}

void ABasePawn::Fire()
{
	auto tmpProjectile = GetWorld()->SpawnActor<AProjectile>(Projectile_, ProjectileSpawnPoint_->GetComponentLocation(), ProjectileSpawnPoint_->GetComponentRotation());
	tmpProjectile->SetOwner(this);
}

