// Fill out your copyright notice in the Description page of Project Settings.


#include "ExperimentActor.h"
//#include "Components/MeshComponent.h"

// Sets default values
AExperimentActor::AExperimentActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AExperimentActor::BeginPlay()
{
	Super::BeginPlay();
	
	Deactivate();
}

void AExperimentActor::SetMaterial(UMaterialInterface* NewMaterial)
{
	Mesh->SetMaterial(0, NewMaterial);
}

// Called every frame
void AExperimentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExperimentActor::Activate()
{
	if (ActivatedMaterial)
	{
		SetMaterial(ActivatedMaterial);
	}
}

void AExperimentActor::Deactivate()
{
	if (DeactivatedMaterial != nullptr)
	{
		SetMaterial(DeactivatedMaterial);
	}
}

bool AExperimentActor::IsActive()
{
	return Mesh->GetMaterial(0) == ActivatedMaterial;
}
