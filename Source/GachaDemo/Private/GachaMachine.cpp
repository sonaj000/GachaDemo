// Fill out your copyright notice in the Description page of Project Settings.


#include "GachaMachine.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AGachaMachine::AGachaMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGachaMachine::BeginPlay()
{
	Super::BeginPlay();
	FivestarR = 0.05f;
	FourstarR = 0.15f;
	ThreestarR = 0.80f;
	
}

TArray<int> AGachaMachine::Roll(int nRolls)
{
	GachaRoll.Empty();
	for (int i{ 0 }; i < nRolls; i++)
	{
		float Rolls = UKismetMathLibrary::RandomFloat();
		if (Rolls < FivestarR)
		{
			GachaRoll.Add(5);
		}
		else if (Rolls < FourstarR)
		{
			GachaRoll.Add(4);
		}
		else
		{
			GachaRoll.Add(3);
		}
	}
	return GachaRoll;
}

// Called every frame
void AGachaMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AGachaMachine::convertRolls()
{
	FString A = "";
	for (int i : GachaRoll)
	{
		A.AppendInt(i);
		A.AppendChar(',');
	}
		
	return A;
}

