// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Components/InputComponent.h>
#include <Kismet/GameplayStatics.h>

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
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 프로젝트 세팅에서 설정한 입력 값을 Move함수와 바인딩
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::Move(float _value)
{
	UE_LOG(LogTemp, Display, TEXT("Move Value >> %f"), _value);

	FVector DeltaLocation(0.f);
	DeltaLocation.X = MoveSpeed_ * _value * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddActorLocalOffset(DeltaLocation);
}
