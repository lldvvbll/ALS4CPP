

#pragma once

#include "EngineMinimal.h"
#include "UObject/UObjectGlobals.h"

DECLARE_LOG_CATEGORY_EXTERN(ALS4CPP, Log, All);

#define LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define LOG_S(Verbosity) UE_LOG(ALS4CPP, Verbosity, TEXT("%s"), *LOG_CALLINFO)
#define LOG(Verbosity, Format, ...) UE_LOG(ALS4CPP, Verbosity, TEXT("%s %s"), *LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
#define return_if(Expr, ...) { if (Expr) { LOG(Error, TEXT("ASSERTION: %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; } }
