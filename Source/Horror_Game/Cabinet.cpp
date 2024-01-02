// Fill out your copyright notice in the Description page of Project Settings.


#include "Cabinet.h"

// Sets default values
ACabinet::ACabinet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	CabinetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cabinet Mesh"));
	CabinetMesh->SetupAttachment(RootComponent);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction widget."));
	InteractionWidget->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACabinet::BeginPlay()
{
	Super::BeginPlay();
	InteractionWidget->SetVisibility(false);
}

// Called every frame
void ACabinet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACabinet::InteractWithMe() {
	UE_LOG(LogTemp, Warning, TEXT("You have interacted with me."));

	UGameplayStatics::PlaySound2D(GetWorld(), ClothChangeSound, 1, 1, 0, NULL, false, true);


}

void ACabinet::ShowInteractionWidget() {
	InteractionWidget->SetVisibility(true);
}

void ACabinet::HideInteractionWidget() {
	InteractionWidget->SetVisibility(false);
}

