// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"

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

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

