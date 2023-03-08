// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void ActorDied(AActor* _DeadActor);

protected:
	virtual void BeginPlay() override;

	// C++가 아닌 블루프린트에서 정의할 수 있도록 하는 옵션
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool _WonGame);

private:
	class ATank* Tank_;
	class AToonTankPlayerController* ToonTanksPlayerController_;

	float StartDelay = 3.f;

	void HandleGameStart();

	// 상대 타워의 갯수
	int TargetTowers_ = 0;
	// 타워의 갯수를 취득
	int GetTargetTowerCount();
};
