// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include <Kismet/GameplayStatics.h>
#include "Tank.h"
#include "Tower.h"
#include "ToonTankPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* _DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor Died called"));

	// �÷��̾� ��ũ�� �ı��Ǿ��� ���
	if (Tank_ == _DeadActor)
	{
		Tank_->HandleDestruction();
		if (ToonTanksPlayerController_)
		{
			ToonTanksPlayerController_->SetPlayerEnabledState(false);
		}
		GameOver(false);
	}
	// Ÿ���� �ı��Ǿ��� ���
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
		
		// ���� �� StartDelay�ð� �Ŀ� TimerDelegate�� �Լ��� ����
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, TimerDelegate, StartDelay, false);
	}
}

int AToonTanksGameMode::GetTargetTowerCount()
{
	TArray<AActor*> Towers;

	// ���忡 �����ϴ� ClassŸ���� Actor�� ��� ���
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);

	return Towers.Num();
}
