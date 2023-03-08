// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include <Kismet/GameplayStatics.h>
#include <TimerManager.h>

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank_ = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle_, this, &ATower::CheckFireCondition, FireRate_, true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CheckRangeToTank())
	{
		RotateTurret(Tank_->GetActorLocation());
	}

}

void ATower::HandleDestruction()
{
	// BasePawn의 함수 호출
	Super::HandleDestruction();
	
	Destroy();
}

void ATower::CheckFireCondition()
{
	if (Tank_ == nullptr)
	{
		return;
	}

	float Distance = FVector::Dist(GetActorLocation(), Tank_->GetActorLocation());

	if (Tank_->Alive_ && CheckRangeToTank())
	{
		Fire();
	}
}

bool ATower::CheckRangeToTank()
{
	float Distance = FVector::Dist(GetActorLocation(), Tank_->GetActorLocation());

	if (Tank_)
	{
		if (Distance < FireRange)
		{
			return true;
		}
	}

	return false;
}
