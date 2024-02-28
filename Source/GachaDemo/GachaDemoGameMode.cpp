// Copyright Epic Games, Inc. All Rights Reserved.

#include "GachaDemoGameMode.h"
#include "GachaDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGachaDemoGameMode::AGachaDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
