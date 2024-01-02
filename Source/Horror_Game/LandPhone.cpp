// Fill out your copyright notice in the Description page of Project Settings.


#include "LandPhone.h"
#include "Kismet/GameplayStatics.h"

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

	// sanki buraya ses gelecek.

	UGameplayStatics::OpenLevel(GetWorld(), "ToBeContEndGameMap");
}

void ALandPhone::ShowInteractionWidget() {
	InteractionWidget->SetVisibility(true);
}

void ALandPhone::HideInteractionWidget() {
	InteractionWidget->SetVisibility(false);
}


