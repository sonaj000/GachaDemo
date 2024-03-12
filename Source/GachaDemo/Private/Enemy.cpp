// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "HealthComponent.h"
#include "GachaDemoCharacter.generated.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UAnimMontage>TestMontageObject(TEXT("/Script/Engine.AnimMontage'/Game/BP/Animations/EnemyAttackAnim_Warrior_Attack_5_Montage.EnemyAttackAnim_Warrior_Attack_5_Montage'"));
	if (TestMontageObject.Succeeded())
	{
		TestMontage = TestMontageObject.Object;
		UE_LOG(LogTemp, Warning, TEXT("Montage Succeeded"));
	}
	
	static ConstructorHelpers::FObjectFinder<UAnimMontage>HitMontageObject(TEXT("	/ Script / Engine.AnimMontage'/Game/BP/Animations/EnemyHit.EnemyHit'"));
	if (HitMontageObject.Succeeded())
	{
		HitMontage = HitMontageObject.Object;
		UE_LOG(LogTemp, Warning, TEXT("Hit Montage Succeeded"));
	}

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle AttackTimer;
	GetWorldTimerManager().SetTimer(AttackTimer, this, &AEnemy::Attack, 3.0f, true);
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::Attack()
{

	//look at player, and move towards them. 
	if (TestMontage)
	{
		PlayAnimMontage(TestMontage, 2.0f);
		//UE_LOG(LogTemp, Warning, TEXT("this is happening"));
	}

}

void AEnemy::OnHealthChanged(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (HitMontage)
	{
		PlayAnimMontage(TestMontage, 2.0f);
		//UE_LOG(LogTemp, Warning, TEXT("this is happening"));
	}
}

