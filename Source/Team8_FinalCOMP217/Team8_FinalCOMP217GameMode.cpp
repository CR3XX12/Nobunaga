// Copyright Epic Games, Inc. All Rights Reserved.

#include "Team8_FinalCOMP217GameMode.h"
#include "Team8_FinalCOMP217Character.h"
#include "UObject/ConstructorHelpers.h"

ATeam8_FinalCOMP217GameMode::ATeam8_FinalCOMP217GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
