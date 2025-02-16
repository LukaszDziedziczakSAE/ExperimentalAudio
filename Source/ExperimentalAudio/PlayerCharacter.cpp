// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "AudioCaptureComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AudioCapture = CreateDefaultSubobject<UAudioCaptureComponent>(TEXT("Audio Capture"));
	AudioCapture->bAutoActivate = true;
	AudioCapture->bEnableBaseSubmix = false;
	AudioCapture->OnAudioEnvelopeValue.AddDynamic(this, &APlayerCharacter::OnAudioEnvelopeValue);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::OnAudioEnvelopeValue(float EnvelopeValue)
{
	AudioEnvelope = EnvelopeValue;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

