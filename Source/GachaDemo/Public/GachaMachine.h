// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "GachaMachine.generated.h"

class UDataTable;

USTRUCT(BlueprintType)
struct FRollTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RollNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BannerNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Time;

};

UCLASS()
class GACHADEMO_API AGachaMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGachaMachine();

	UPROPERTY(BlueprintReadWrite)
	TArray<int>GachaRoll;

	UPROPERTY(VisibleAnywhere)
	int Counter; //counter for the gachapon machine. 

	UFUNCTION(BlueprintCallable)
	FString convertRolls();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Analysis")
	UDataTable*	TableRolls;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	TArray<int> Roll(int nRolls);

	UPROPERTY(EditAnywhere)
	float FivestarR;

	UPROPERTY(EditAnywhere)
	float FourstarR;

	UPROPERTY(EditAnywhere)
	float ThreestarR;

	UPROPERTY(EditAnywhere)
	float FivestarNP;

	UPROPERTY(EditAnywhere)
	float FourstarNP;

	UPROPERTY(EditAnywhere)
	float ThreestarNP;

	UPROPERTY(EditAnywhere)
	int PityNumber;

	UPROPERTY(VisibleAnywhere)
	int pitycounter;

	UFUNCTION(BlueprintCallable)
	TArray<int> RollPity(int nRolls);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
