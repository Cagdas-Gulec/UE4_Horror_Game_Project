// Fill out your copyright notice in the Description page of Project Settings.


#include "LandPhone.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Sets default values
ALandPhone::ALandPhone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	LandPhoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Land Phone Mesh"));
	LandPhoneMesh->SetupAttachment(RootComponent);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction widget."));
	InteractionWidget->SetupAttachment(RootComponent);

	PoliceSiren = CreateDefaultSubobject<USoundBase>(TEXT("PoliceSiren"));
}

// Called when the game starts or when spawned
void ALandPhone::BeginPlay()
{
	Super::BeginPlay();
	InteractionWidget->SetVisibility(false);
	
}

// Called every frame
void ALandPhone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALandPhone::InteractWithMe() {

	UE_LOG(LogTemp, Warning, TEXT("You have interacted with me."));

	UGameplayStatics::PlaySound2D(GetWorld(), PoliceSiren, 1, 1, 0, NULL, false, true);

	FTimerHandle TimerHandle;
	float DelayInSeconds = 5.0f;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALandPhone::ChangeLevel, DelayInSeconds, false);
}

void ALandPhone::ShowInteractionWidget() {
	InteractionWidget->SetVisibility(true);
}

void ALandPhone::HideInteractionWidget() {
	InteractionWidget->SetVisibility(false);
}

void ALandPhone::ChangeLevel()
{
	// Open level after delay
	UGameplayStatics::OpenLevel(GetWorld(), "ToBeContEndGameMap");
}