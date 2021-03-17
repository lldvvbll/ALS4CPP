

using UnrealBuildTool;
using System.Collections.Generic;

public class ALS4CPPEditorTarget : TargetRules
{
	public ALS4CPPEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ALS4CPP" } );
	}
}
