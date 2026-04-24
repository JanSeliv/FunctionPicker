// Copyright (c) Yevhenii Selivanov

using UnrealBuildTool;

public class FunctionPickerEditor : ModuleRules
{
    public FunctionPickerEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        CppCompileWarningSettings.NonInlinedGenCppWarningLevel = WarningLevel.Error;
        
        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new[]
            {
                "CoreUObject", "Engine", "Slate", "SlateCore" // Core
                , "ToolWidgets" // SSearchableComboBox
                // My modules
                , "FunctionPicker" // FFunctionPicker
            }
        );
    }
}