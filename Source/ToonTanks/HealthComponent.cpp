// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

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

	FString OwnerName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("HealthComponent Owern Name >> %s"), *OwnerName);
}


void UHealthComponent::DamageTaken(AActor* _DamagedActor, float _Damage, const UDamageType* DamageType, AController* _Instigator, AActor* _DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage Taken On"));

	//if (Health_ <= 0.f) return;

	Health_ -= _Damage;
	UE_LOG(LogTemp, Warning, TEXT("Health : %f"), Health_);
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

