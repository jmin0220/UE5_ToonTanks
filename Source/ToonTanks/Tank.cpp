// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>

ATank::ATank()
{
	SpringArmCom_ = CreateDefaultSubobject<USpringArmComponent>("SpringArmCom");
	SpringArmCom_->SetupAttachment(RootComponent);

	CameraCom_ = CreateDefaultSubobject<UCameraComponent>("CameraCom");
	CameraCom_->SetupAttachment(SpringArmCom_);

}

void ATank::BeginPlay()
{
}

void ATank::Tick(float DeltaTime)
{
}
