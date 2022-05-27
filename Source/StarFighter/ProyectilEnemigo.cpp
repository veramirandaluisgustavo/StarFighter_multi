// Fill out your copyright notice in the Description page of Project Settings.


#include "ProyectilEnemigo.h"
#include "NaveAereaJugador.h"
//#include "DianaO.h"
#include "Kismet/GamePlayStatics.h"

// Sets default values
AProyectilEnemigo::AProyectilEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	My_mesh = CreateDefaultSubobject<UStaticMeshComponent>("MYMESH");
	SpawnLocation = CreateDefaultSubobject<USceneComponent>("SpawnLocation");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Meshes/SM_Pixel_Enemy_1.SM_Pixel_Enemy_1'"));

	if (MeshAsset.Object != nullptr)
	{
		My_mesh->SetStaticMesh(MeshAsset.Object);
	}


	
	RootComponent = SpawnLocation;
	My_mesh->AttachTo(SpawnLocation);

	//My_mesh->SetRelativeTransform(FTransform(FRotator(0, 90, -90)));
	My_mesh->SetRelativeTransform(FTransform(FRotator(0, 90, -90),FVector(-100,0,0)));
	DireccionGrados = 0;
	Direccionx = 0;
	Direcciony = 0;

	
}


// Called when the game starts or when spawned
void AProyectilEnemigo::BeginPlay()
{
	Super::BeginPlay();

	SpawnP_E();
	MiPosi = GetOwner();

	TArray<AActor*>Apuntadores;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANaveAereaJugador::StaticClass(), Apuntadores);
	if (Apuntadores.Num() != 0) {

		auto apuntador = Cast<ANaveAereaJugador>(Apuntadores[0]);
		MyObjetivo = apuntador->Objetivo.AddUObject(this, &AProyectilEnemigo::ApuntarEnemigo);

	};

	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADianaO::StaticClass(), Apuntadores);
	//if (Apuntadores.Num() != 0) {

	//	auto apuntador = Cast<ADianaO>(Apuntadores[0]);
	//	//MyObjetivo = apuntador->Objetivo.AddUObject(this, &AProyectilEnemigo::ApuntarEnemigo);

	//};
	
}

// Called every frame
void AProyectilEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*DireccionGrados += 90;

	if (DireccionGrados > 360) {

		DireccionGrados -= 360;
	}
	
	My_mesh->SetRelativeTransform(FTransform(FRotator(0, DireccionGrados, -90), FVector(-100, 0, 0)));*/
}

void AProyectilEnemigo::P_ECollected()
{

	GetWorld()->GetTimerManager().SetTimer(MyTimer, this, &AProyectilEnemigo::SpawnP_E, 2, false);
	
	
	CurrentP_E->Recarga.Unbind();
	CurrentP_E->Destroy();

}




void AProyectilEnemigo::SpawnP_E()
{
	UWorld* MyWorld = GetWorld();
	if (MyWorld != nullptr)
	{
		CurrentP_E = MyWorld->SpawnActor<AProyectilE>(AProyectilE::StaticClass(), GetTransform());
		//CurrentP_E = MyWorld->SpawnActor<APickup>(APickup::StaticClass(), GetTransform());
		//CurrentP_E->OnPickedUp.BindUObject(this, &AProyectilEnemigo::P_ECollected);
		CurrentP_E->Recarga.BindUObject(this, &AProyectilEnemigo::P_ECollected);
	}
}

void AProyectilEnemigo::ApuntarEnemigo(int a, int b)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 4, FColor::Red, FString::Printf(TEXT("%i = %i"), a, b));
	
	//int Cx, Cy,direc;
	//float magnitud;
	//direc = FMath::Atan((a - MiPosi->GetActorLocation().X)/(b- MiPosi->GetActorLocation().Y));
	//DireccionGrados = direc;
	//magnitud = FMath::Sqrt(FMath::Pow((MiPosi->GetActorLocation().X - a) ,2) + FMath::Pow( (MiPosi->GetActorLocation().Y - b) ,2));
	//Cx = magnitud * FMath::Cos(DireccionGrados);
	//Cy= magnitud * FMath::Sin(DireccionGrados);
	//Direccionx = Cx;
	//Direcciony = Cy;

	
}





