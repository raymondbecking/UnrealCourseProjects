// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOONTANKS_TowerSniper_generated_h
#error "TowerSniper.generated.h already included, missing '#pragma once' in TowerSniper.h"
#endif
#define TOONTANKS_TowerSniper_generated_h

#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_SPARSE_DATA
#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_RPC_WRAPPERS
#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATowerSniper(); \
	friend struct Z_Construct_UClass_ATowerSniper_Statics; \
public: \
	DECLARE_CLASS(ATowerSniper, ABasePawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(ATowerSniper)


#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATowerSniper(); \
	friend struct Z_Construct_UClass_ATowerSniper_Statics; \
public: \
	DECLARE_CLASS(ATowerSniper, ABasePawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(ATowerSniper)


#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATowerSniper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATowerSniper) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATowerSniper); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATowerSniper); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATowerSniper(ATowerSniper&&); \
	NO_API ATowerSniper(const ATowerSniper&); \
public:


#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATowerSniper() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATowerSniper(ATowerSniper&&); \
	NO_API ATowerSniper(const ATowerSniper&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATowerSniper); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATowerSniper); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATowerSniper)


#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__FireRange() { return STRUCT_OFFSET(ATowerSniper, FireRange); } \
	FORCEINLINE static uint32 __PPO__FireRate() { return STRUCT_OFFSET(ATowerSniper, FireRate); }


#define ToonTanks_Source_ToonTanks_TowerSniper_h_12_PROLOG
#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_PRIVATE_PROPERTY_OFFSET \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_SPARSE_DATA \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_RPC_WRAPPERS \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_INCLASS \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ToonTanks_Source_ToonTanks_TowerSniper_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_PRIVATE_PROPERTY_OFFSET \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_SPARSE_DATA \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_INCLASS_NO_PURE_DECLS \
	ToonTanks_Source_ToonTanks_TowerSniper_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOONTANKS_API UClass* StaticClass<class ATowerSniper>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ToonTanks_Source_ToonTanks_TowerSniper_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
