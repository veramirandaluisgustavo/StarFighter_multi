// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilE.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AProyectilE::AProyectilE()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");

	TriggerZone->SetBoxExtent(FVector(50, 50, 50));



	My_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = My_Mesh;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));
	if (MeshAsset.Object != nullptr)
	{
		My_Mesh->SetStaticMesh(MeshAsset.Object);
	}
	My_Mesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
}

// Called when the game starts or when spawned
void AProyectilE::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProyectilE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProyectilE::NotifyActorBeginOverlap(AActor* OtherActor)
{

	Recarga.ExecuteIfBound();
}

