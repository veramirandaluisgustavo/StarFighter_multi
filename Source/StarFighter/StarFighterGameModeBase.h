// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarFighterGameModeBase.generated.h"

/**
 * 
 */

DECLARE_DELEGATE(FDelegateDestructor)
DECLARE_DELEGATE_TwoParams(FDelegateInventory, FString, int)

UCLASS()
class STARFIGHTER_API AStarFighterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	AStarFighterGameModeBase();

	template<typename T>
	T SpawnNave();

	FDelegateInventory MyInventoryDelegate;

	FDelegateDestructor MyDestructorDelegate;
};

template<typename T>
T AStarFighterGameModeBase::SpawnNave() {
	
	return GetWorld()->SpawnActor<T>(FVector::ZeroVector, FRotator::ZeroRotator);
}
