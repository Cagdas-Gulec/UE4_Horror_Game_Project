// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
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

	Light4 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb4"));
	Light4->SetupAttachment(RootComponent);

	Light5 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb5"));
	Light5->SetupAttachment(RootComponent);

	Light6 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb6"));
	Light6->SetupAttachment(RootComponent);

	Light7 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb7"));
	Light7->SetupAttachment(RootComponent);

	Light8 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb8"));
	Light8->SetupAttachment(RootComponent);

	Light9 = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightBulb9"));
	Light9->SetupAttachment(RootComponent);

	PowerUpSound = CreateDefaultSubobject<USoundBase>(TEXT("PowerUpSound"));

	PowerDownSound = CreateDefaultSubobject<USoundBase>(TEXT("PowerDownSound"));

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
	Light4->SetIntensity(1000);
	Light5->SetIntensity(1000);
	Light6->SetIntensity(1000);
	Light7->SetIntensity(1000);
	Light8->SetIntensity(1000);
	Light9->SetIntensity(1000);
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
		Light4->SetIntensity(0);
		Light5->SetIntensity(0);
		Light6->SetIntensity(0);
		Light7->SetIntensity(0);
		Light8->SetIntensity(0);
		Light9->SetIntensity(0);
		UGameplayStatics::PlaySound2D(GetWorld(), PowerDownSound, 1, 1, 0, NULL, false, true);
		bIsOn = false;

		// sanki buraya açýlma sesi gelecek.

	}
	else
	{
		Light->SetIntensity(1000);
		Light2->SetIntensity(1000);
		Light3->SetIntensity(1000);
		Light4->SetIntensity(1000);
		Light5->SetIntensity(1000);
		Light6->SetIntensity(1000);
		Light7->SetIntensity(1000);
		Light8->SetIntensity(1000);
		Light9->SetIntensity(1000);
		UGameplayStatics::PlaySound2D(GetWorld(), PowerUpSound, 1, 1, 0, NULL, false, true);
		bIsOn = true;

		// sanki buraya kapanma sesi gelecek.
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

