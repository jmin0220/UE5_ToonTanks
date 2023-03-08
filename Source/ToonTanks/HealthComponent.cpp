// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include <Kismet/GameplayStatics.h>
#include "ToonTanksGameMode.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health_ = MaxHealth_;

	UE_LOG(LogTemp, Warning, TEXT("Health >> %f"), Health_);

	// DamageTaken 콜백 함수 세팅
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);

	ToonTanksGameMode_ = Cast<AToonTanksGameMode>(UGameplayStatics::GetGameMode(this));
}


void UHealthComponent::DamageTaken(AActor* _DamagedActor, float _Damage, const UDamageType* DamageType, AController* _Instigator, AActor* _DamageCauser)
{
	Health_ -= _Damage;

	if (Health_ <= 0.f)
	{
		ToonTanksGameMode_->ActorDied(_DamagedActor);
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Health : %f"), Health_);
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

