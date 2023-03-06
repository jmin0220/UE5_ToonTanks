// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include <Kismet/GameplayStatics.h>

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank_ = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank_)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank_->GetActorLocation());

		if (Distance < FireRange)
		{
			RotateTurret(Tank_->GetActorLocation());
		}
	}
}
