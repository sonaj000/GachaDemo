// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GachaMachine.generated.h"

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual TArray<int> Roll(int nRolls);

	UPROPERTY(EditAnywhere)
	float FivestarR;

	UPROPERTY(EditAnywhere)
	float FourstarR;

	UPROPERTY(EditAnywhere)
	float ThreestarR;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
