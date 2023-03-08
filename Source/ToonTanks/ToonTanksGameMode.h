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

	// C++�� �ƴ� �������Ʈ���� ������ �� �ֵ��� �ϴ� �ɼ�
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool _WonGame);

private:
	class ATank* Tank_;
	class AToonTankPlayerController* ToonTanksPlayerController_;

	float StartDelay = 3.f;

	void HandleGameStart();

	// ��� Ÿ���� ����
	int TargetTowers_ = 0;
	// Ÿ���� ������ ���
	int GetTargetTowerCount();
};
