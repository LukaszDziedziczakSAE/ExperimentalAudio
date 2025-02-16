// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExperimentActor.generated.h"

UCLASS()
class EXPERIMENTALAUDIO_API AExperimentActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExperimentActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UMaterialInterface* DeactivatedMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UMaterialInterface* ActivatedMaterial;

	UFUNCTION(BlueprintCallable)
	void SetMaterial(UMaterialInterface* NewMaterial);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Activate();

	UFUNCTION(BlueprintCallable)
	void Deactivate();

	UFUNCTION(BlueprintCallable)
	bool IsActive();
};
