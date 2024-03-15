// Fill out your copyright notice in the Description page of Project Settings.


#include "GachaMachine.h"
#include "Kismet/KismetMathLibrary.h"
#include "Misc/DateTime.h"


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
	FivestarR = 0.005f;
	FourstarR = 0.15f;
	ThreestarR = 0.80f;

	FivestarNP = 0.02;
	FourstarNP = 0.145;
	ThreestarNP = 0.835;
	
	PityNumber = 50;
	pitycounter = 0;
	
}

TArray<int> AGachaMachine::Roll(int nRolls)
{
	GachaRoll.Empty();
	for (int i{ 0 }; i < nRolls; i++)
	{
		float Rolls = UKismetMathLibrary::RandomFloat();
		if (Rolls < FivestarNP)
		{
			GachaRoll.Add(5);
		}
		else if (Rolls < FourstarNP)
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

TArray<int> AGachaMachine::RollPity(int nRolls)
{
	GachaRoll.Empty();
	FRollTable RollResults;

	for (int i{ 0 }; i < nRolls; i++)
	{
		pitycounter++;
		FString NewNumber = FString::FromInt(pitycounter);

		if (pitycounter >= PityNumber)
		{
			GachaRoll.Add(5);
			RollResults.RollNumber = 5;
			RollResults.BannerNumber = 1;
			RollResults.Time = FDateTime::FDateTime().GetSecond();
			TableRolls->AddRow(FName(*NewNumber), RollResults);
			pitycounter = 0;
		}
		else
		{
			float Rolls = UKismetMathLibrary::RandomFloat();
			if (Rolls < FivestarR)
			{
				GachaRoll.Add(5);
				RollResults.RollNumber = 5;
				RollResults.BannerNumber = 1;
				RollResults.Time = FDateTime::FDateTime().GetSecond();
				TableRolls->AddRow(FName(*NewNumber), RollResults);
			}
			else if (Rolls < FourstarR)
			{
				GachaRoll.Add(4);
				RollResults.RollNumber = 4;
				RollResults.BannerNumber = 1;
				RollResults.Time = FDateTime::FDateTime().GetSecond();
				TableRolls->AddRow(FName(*NewNumber), RollResults);
			}
			else
			{
				GachaRoll.Add(3);
				RollResults.RollNumber = 3;
				RollResults.BannerNumber = 1;
				RollResults.Time = FDateTime::FDateTime().GetSecond();
				TableRolls->AddRow(FName(*NewNumber), RollResults);
			}
		}
	}
	//add gacharoll to the table
	//for i in gacharoll, add new row in table so. 
	//CurrentGameMode->PlayerTable->AddRow(FName(*NewNumber), PlayerStats);//add row to the datatable
	//UE_LOG(LogTemp, Warning, TEXT("///data is logged, %d"), key[0]);
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

