// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorDeactivator.h"
#include "ExperimentActor.h"
#include "PlayerCharacter.h"

// Sets default values for this component's properties
UActorDeactivator::UActorDeactivator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorDeactivator::BeginPlay()
{
	Super::BeginPlay();

	Actor = Cast<AExperimentActor>(GetOwner());
	Player = Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


void UActorDeactivator::DeactivateActor()
{
	Actor->Deactivate();
}

// Called every frame
void UActorDeactivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!Actor->IsActive()) return;

	Timer += DeltaTime;

	if (Timer >= Time)
	{
		DeactivateActor();
		Timer = 0.0f;
	}
}

