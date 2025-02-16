// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorDeactivator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERIMENTALAUDIO_API UActorDeactivator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorDeactivator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class AExperimentActor* Actor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APlayerCharacter* Player;

	UFUNCTION()
	void DeactivateActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Time{ 1.0f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Timer{ 0.0f };

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
