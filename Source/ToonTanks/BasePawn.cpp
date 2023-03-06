// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Ä¸½¶ ÄÄÆ÷³ÍÆ®¸¦ »ý¼ºÈÄ, »ý¼ºµÈ Ä¸½¶ ÄÄÆ÷³ÍÆ®¸¦ Root·Î ¼³Á¤
	CapsuleCom_ = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsulCollider"));
	RootComponent = CapsuleCom_;

	// BaseMesh¸¦ Root¿¡ Attachment
	BaseMesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh_->SetupAttachment(CapsuleCom_);

	// TurretÀ» BaseMesh¿¡ Attachment
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

void ABasePawn::RotateTurret(FVector _LookAtTarget)
{
	FVector ToTarget = _LookAtTarget - TurretMesh_->GetComponentLocation();

	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurretMesh_->SetWorldRotation(
		FMath::RInterpTo(TurretMesh_->GetComponentRotation(), LookAtRotation, UGameplayStatics::GetWorldDeltaSeconds(this), 15.f));
}

void ABasePawn::Fire()
{
	DrawDebugSphere(this->GetWorld(), ProjectileSpawnPoint_->GetComponentLocation(), 10.f, 20, FColor::Green, false, 3.f);
}

