// Copyright (c) Yevhenii Selivanov.

#include "FunctionPickerData/FunctionPicker.h"
//---
#include UE_INLINE_GENERATED_CPP_BY_NAME(FunctionPicker)

// Empty settings function
const FFunctionPicker FFunctionPicker::Empty = FFunctionPicker();

// Custom constructor to set all members values
FFunctionPicker::FFunctionPicker(UClass* InFunctionClass, FName InFunctionName)
	: FunctionClass(InFunctionClass)
	  , FunctionName(InFunctionName) {}

// Returns the function pointer based on set data to this structure
UFunction* FFunctionPicker::GetFunction() const
{
	if (CachedFunctionInternal.IsValid())
	{
		return CachedFunctionInternal.Get();
	}

	if (FunctionClass
		&& !FunctionName.IsNone())
	{
		UFunction* FoundFunction = FunctionClass->FindFunctionByName(FunctionName, EIncludeSuperFlag::ExcludeSuper);
		CachedFunctionInternal = FoundFunction;
		return FoundFunction;
	}

	return nullptr;
}

// Returns string in text format: Class::Function
FString FFunctionPicker::ToDisplayString() const
{
	return IsValid() ? FString::Printf(TEXT("%s::%s"), *FunctionClass->GetName(), *FunctionName.ToString()) : FString();
}

// Creates a hash value
uint32 GetTypeHash(const FFunctionPicker& Other)
{
	const uint32 FunctionClassHash = GetTypeHash(Other.FunctionClass);
	const uint32 FunctionNameHash = GetTypeHash(Other.FunctionName);
	return HashCombine(FunctionClassHash, FunctionNameHash);
}
