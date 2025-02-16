// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorActivator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENTALAUDIO_API UActorActivator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorActivator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AExperimentActor* Actor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APlayerCharacter* Player;

	UFUNCTION()
	void ActivateActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Threshold{ 0.1f };

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
