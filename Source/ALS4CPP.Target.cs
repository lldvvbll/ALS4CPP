

using UnrealBuildTool;
using System.Collections.Generic;

public class ALS4CPPTarget : TargetRules
{
	public ALS4CPPTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ALS4CPP" } );
	}
}
