// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	LightSwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightSwitchMesh"));
	LightSwitchMesh->SetupAttachment(RootComponent);

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb"));
	Light->SetupAttachment(RootComponent);

	Light2 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb2"));
	Light2->SetupAttachment(RootComponent);

	Light3 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb3"));
	Light3->SetupAttachment(RootComponent);

	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction widget."));
	InteractionWidget->SetupAttachment(RootComponent); 
	

}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	Light->SetIntensity(1000);
	Light2->SetIntensity(1000);
	Light3->SetIntensity(1000);
	InteractionWidget->SetVisibility(false);
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitch::InteractWithMe()
{
	UE_LOG(LogTemp, Warning, TEXT("You have interacted with me."));
	if (bIsOn) {
		Light->SetIntensity(0);
		Light2->SetIntensity(0);
		Light3->SetIntensity(0);
		bIsOn = false;
	}
	else
	{
		Light->SetIntensity(1000);
		Light2->SetIntensity(1000);
		Light3->SetIntensity(1000);
		bIsOn = true;
	}

}

void ALightSwitch::ShowInteractionWidget()
{
	InteractionWidget->SetVisibility(true);
}

void ALightSwitch::HideInteractionWidget()
{
	InteractionWidget->SetVisibility(false);
}

