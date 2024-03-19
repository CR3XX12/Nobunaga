// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Team8_FinalCOMP217 : ModuleRules
{
	public Team8_FinalCOMP217(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
