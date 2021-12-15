// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToonTanks/ToonTanksHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeToonTanksHUD() {}
// Cross Module References
	TOONTANKS_API UClass* Z_Construct_UClass_AToonTanksHUD_NoRegister();
	TOONTANKS_API UClass* Z_Construct_UClass_AToonTanksHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_ToonTanks();
// End Cross Module References
	static FName NAME_AToonTanksHUD_UpdateHealthHUD = FName(TEXT("UpdateHealthHUD"));
	void AToonTanksHUD::UpdateHealthHUD(float CurrentHealth)
	{
		ToonTanksHUD_eventUpdateHealthHUD_Parms Parms;
		Parms.CurrentHealth=CurrentHealth;
		ProcessEvent(FindFunctionChecked(NAME_AToonTanksHUD_UpdateHealthHUD),&Parms);
	}
	void AToonTanksHUD::StaticRegisterNativesAToonTanksHUD()
	{
	}
	struct Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ToonTanksHUD_eventUpdateHealthHUD_Parms, CurrentHealth), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::NewProp_CurrentHealth,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ToonTanksHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AToonTanksHUD, nullptr, "UpdateHealthHUD", nullptr, nullptr, sizeof(ToonTanksHUD_eventUpdateHealthHUD_Parms), Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AToonTanksHUD_NoRegister()
	{
		return AToonTanksHUD::StaticClass();
	}
	struct Z_Construct_UClass_AToonTanksHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AToonTanksHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_ToonTanks,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AToonTanksHUD_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AToonTanksHUD_UpdateHealthHUD, "UpdateHealthHUD" }, // 212834091
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AToonTanksHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "ToonTanksHUD.h" },
		{ "ModuleRelativePath", "ToonTanksHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AToonTanksHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AToonTanksHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AToonTanksHUD_Statics::ClassParams = {
		&AToonTanksHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AToonTanksHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AToonTanksHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AToonTanksHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AToonTanksHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AToonTanksHUD, 4086933625);
	template<> TOONTANKS_API UClass* StaticClass<AToonTanksHUD>()
	{
		return AToonTanksHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AToonTanksHUD(Z_Construct_UClass_AToonTanksHUD, &AToonTanksHUD::StaticClass, TEXT("/Script/ToonTanks"), TEXT("AToonTanksHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AToonTanksHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
