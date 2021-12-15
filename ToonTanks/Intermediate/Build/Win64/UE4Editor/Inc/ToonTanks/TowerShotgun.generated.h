// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOONTANKS_TowerShotgun_generated_h
#error "TowerShotgun.generated.h already included, missing '#pragma once' in TowerShotgun.h"
#endif
#define TOONTANKS_TowerShotgun_generated_h

#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_SPARSE_DATA
#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_RPC_WRAPPERS
#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATowerShotgun(); \
	friend struct Z_Construct_UClass_ATowerShotgun_Statics; \
public: \
	DECLARE_CLASS(ATowerShotgun, ABasePawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(ATowerShotgun)


#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATowerShotgun(); \
	friend struct Z_Construct_UClass_ATowerShotgun_Statics; \
public: \
	DECLARE_CLASS(ATowerShotgun, ABasePawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToonTanks"), NO_API) \
	DECLARE_SERIALIZER(ATowerShotgun)


#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATowerShotgun(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATowerShotgun) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATowerShotgun); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATowerShotgun); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATowerShotgun(ATowerShotgun&&); \
	NO_API ATowerShotgun(const ATowerShotgun&); \
public:


#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATowerShotgun(ATowerShotgun&&); \
	NO_API ATowerShotgun(const ATowerShotgun&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATowerShotgun); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATowerShotgun); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATowerShotgun)


#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SecondBarrel() { return STRUCT_OFFSET(ATowerShotgun, SecondBarrel); } \
	FORCEINLINE static uint32 __PPO__ThirdBarrel() { return STRUCT_OFFSET(ATowerShotgun, ThirdBarrel); } \
	FORCEINLINE static uint32 __PPO__ProjectileSpawnPoint2() { return STRUCT_OFFSET(ATowerShotgun, ProjectileSpawnPoint2); } \
	FORCEINLINE static uint32 __PPO__ProjectileSpawnPoint3() { return STRUCT_OFFSET(ATowerShotgun, ProjectileSpawnPoint3); } \
	FORCEINLINE static uint32 __PPO__FireRate() { return STRUCT_OFFSET(ATowerShotgun, FireRate); }


#define ToonTanks_Source_ToonTanks_TowerShotgun_h_12_PROLOG
#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_PRIVATE_PROPERTY_OFFSET \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_SPARSE_DATA \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_RPC_WRAPPERS \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_INCLASS \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ToonTanks_Source_ToonTanks_TowerShotgun_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_PRIVATE_PROPERTY_OFFSET \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_SPARSE_DATA \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_INCLASS_NO_PURE_DECLS \
	ToonTanks_Source_ToonTanks_TowerShotgun_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOONTANKS_API UClass* StaticClass<class ATowerShotgun>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ToonTanks_Source_ToonTanks_TowerShotgun_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
