// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include <Kismet/GameplayStatics.h>
#include "Tank.h"
#include "Tower.h"
#include "ToonTankPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* _DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor Died called"));

	// 플레이어 탱크가 파괴되었을 경우
	if (Tank_ == _DeadActor)
	{
		Tank_->HandleDestruction();
		if (ToonTanksPlayerController_)
		{
			ToonTanksPlayerController_->SetPlayerEnabledState(false);
		}
		GameOver(false);
	}
	// 타워가 파괴되었을 경우
	else if(ATower* DestroyedTower = Cast<ATower>(_DeadActor))
	{
		DestroyedTower->HandleDestruction();

		if (GetTargetTowerCount() == 0)
		{
			GameOver(true);
		}
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void AToonTanksGameMode::HandleGameStart()
{
	Tank_ = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController_ = Cast<AToonTankPlayerController>(UGameplayStatics::GetPlayerController(Tank_, 0));

	StartGame();

	if (ToonTanksPlayerController_)
	{
		ToonTanksPlayerController_->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(ToonTanksPlayerController_, &AToonTankPlayerController::SetPlayerEnabledState, true);
		
		// 시작 후 StartDelay시간 후에 TimerDelegate의 함수를 실행
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, TimerDelegate, StartDelay, false);
	}
}

int AToonTanksGameMode::GetTargetTowerCount()
{
	TArray<AActor*> Towers;

	// 월드에 존재하는 Class타입의 Actor를 모두 취득
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);

	return Towers.Num();
}
