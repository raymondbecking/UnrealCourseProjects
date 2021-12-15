// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOONTANKS_ToonTanksHUD_generated_h
#error "ToonTanksHUD.generated.h already included, missing '#pragma once' in ToonTanksHUD.h"
#endif
#define TOONTANKS_ToonTanksHUD_generated_h

#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_SPARSE_DATA
#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_RPC_WRAPPERS
#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_EVENT_PARMS \
	struct ToonTanksHUD_eventUpdateHealthHUD_Parms \
	{ \
		float CurrentHealth; \
	};


#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_CALLBACK_WRAPPERS
#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAToonTanksHUD(); \
	friend struct Z_Construct_UClass_AToonTanksHUD_Statics; \
public: \
	DECLARE_CLASS(AToonTanksHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(AToonTanksHUD)


#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAToonTanksHUD(); \
	friend struct Z_Construct_UClass_AToonTanksHUD_Statics; \
public: \
	DECLARE_CLASS(AToonTanksHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(AToonTanksHUD)


#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AToonTanksHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AToonTanksHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AToonTanksHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AToonTanksHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AToonTanksHUD(AToonTanksHUD&&); \
	NO_API AToonTanksHUD(const AToonTanksHUD&); \
public:


#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AToonTanksHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AToonTanksHUD(AToonTanksHUD&&); \
	NO_API AToonTanksHUD(const AToonTanksHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AToonTanksHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AToonTanksHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AToonTanksHUD)


#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_PRIVATE_PROPERTY_OFFSET
#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_12_PROLOG \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_EVENT_PARMS


#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_SPARSE_DATA \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_RPC_WRAPPERS \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_CALLBACK_WRAPPERS \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_INCLASS \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_SPARSE_DATA \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_CALLBACK_WRAPPERS \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_INCLASS_NO_PURE_DECLS \
	ToonTanks_Source_ToonTanks_ToonTanksHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOONTANKS_API UClass* StaticClass<class AToonTanksHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ToonTanks_Source_ToonTanks_ToonTanksHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
