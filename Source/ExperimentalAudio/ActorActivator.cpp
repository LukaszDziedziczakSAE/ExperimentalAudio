// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorActivator.h"
#include "ExperimentActor.h"
#include "PlayerCharacter.h"

// Sets default values for this component's properties
UActorActivator::UActorActivator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorActivator::BeginPlay()
{
	Super::BeginPlay();

	Actor = Cast<AExperimentActor>(GetOwner());
	Player = Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


void UActorActivator::ActivateActor()
{
	Actor->Activate();
}

// Called every frame
void UActorActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Actor->IsActive()) return;

	if (Player->AudioEnvelope >= Threshold)
	{
		ActivateActor();
	}
}

