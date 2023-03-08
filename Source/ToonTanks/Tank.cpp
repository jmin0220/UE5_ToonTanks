// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Components/InputComponent.h>
#include <Kismet/GameplayStatics.h>
#include <DrawDebugHelpers.h>

ATank::ATank()
{
	SpringArmCom_ = CreateDefaultSubobject<USpringArmComponent>("SpringArmCom");
	SpringArmCom_->SetupAttachment(RootComponent);

	CameraCom_ = CreateDefaultSubobject<UCameraComponent>("CameraCom");
	CameraCom_->SetupAttachment(SpringArmCom_);

}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	PlayerController_ = Cast<APlayerController>(GetController());
}


void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerController_)
	{
		FHitResult HitResult;
		PlayerController_->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);

		//DrawDebugSphere(this->GetWorld(), HitResult.ImpactPoint, 50.f, 20, FColor::Red, false, -1.f);

		RotateTurret(HitResult.ImpactPoint);
	}
}

void ATank::HandleDestruction()
{
	Super::HandleDestruction();

	// �÷��̾��̹Ƿ� Destroy���� �ʰ� ����
	// Destroy();

	// ���ӿ��� ���͸� ����
	SetActorHiddenInGame(true);
	// Tick�Լ� ��ȿȭ
	SetActorTickEnabled(false);
	Alive_ = false;
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// ������Ʈ ���ÿ��� ������ �Է� ���� Move�Լ��� ���ε�
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire);
}

void ATank::Move(float _value)
{
	FVector DeltaLocation(0.f);
	DeltaLocation.X = MoveSpeed_ * _value * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalOffset(DeltaLocation, true);	
}

void ATank::Turn(float _value)
{
	FVector DeltaLocation(0.f);
	DeltaLocation.X = TurnSpeed_ * _value * UGameplayStatics::GetWorldDeltaSeconds(this);

	FRotator DeltaRotator(0.f);
	DeltaRotator.Yaw = TurnSpeed_ * _value * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalRotation(DeltaRotator, true);
}
