// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ProyectilE.generated.h"


DECLARE_DELEGATE(FProyectileE)
UCLASS()
class STARFIGHTER_API AProyectilE : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectilE();

	UPROPERTY()
		UStaticMeshComponent* My_Mesh;
	
		FProyectileE Recarga;

		UBoxComponent* TriggerZone;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
