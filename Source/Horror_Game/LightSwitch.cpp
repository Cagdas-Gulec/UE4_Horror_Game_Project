#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creating main root component of light switch which will hold other components.
	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	//Creating mesh of light switch.
	LightSwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightSwitchMesh"));
	LightSwitchMesh->SetupAttachment(RootComponent);

	//Creating nine point lights for house's lightning.
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

	//Creating slots for power up and power down sounds.
	PowerUpSound = CreateDefaultSubobject<USoundBase>(TEXT("PowerUpSound"));
	PowerDownSound = CreateDefaultSubobject<USoundBase>(TEXT("PowerDownSound"));

	//Creating an interaction widget which is used to print "E" letter above the switch.
	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction widget."));
	InteractionWidget->SetupAttachment(RootComponent); 
}

void ALightSwitch::BeginPlay() //Called once when play button is activated.
{
	Super::BeginPlay();

	//Setting up lights' intensity at 1000 so house can be bright as default when the game starts.
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

void ALightSwitch::Tick(float DeltaTime) //Called every frame.
{
	Super::Tick(DeltaTime);
}

void ALightSwitch::InteractWithMe()
{
	if (bIsOn) {
		//Shut down all lights and play power down sound if lights are on and "E" is pressed.
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
	}
	else
	{
		//Power up all lights and play power up sound if lights are off and "E" is pressed.
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
	}
}

void ALightSwitch::ShowInteractionWidget() //Show "E" letter.
{
	InteractionWidget->SetVisibility(true);
}

void ALightSwitch::HideInteractionWidget() //Hide "E" letter.
{
	InteractionWidget->SetVisibility(false);
}

void ALightSwitch::UgaBuga() //Call InteractWithMe function to control lights.
{
	InteractWithMe();
}