// Included necessary headers for the LandPhone class
#include "LandPhone.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Sets default values for the LandPhone class
ALandPhone::ALandPhone()
{
 	// Sets this actor to call Tick() every frame. It can be turn off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a root component for the actor
	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	// Creates a static mesh component for the land phone and attach it to the root component
	LandPhoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Land Phone Mesh"));
	LandPhoneMesh->SetupAttachment(RootComponent);

	// Creates a widget component for interaction and attach it to the root component
	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Interaction widget."));
	InteractionWidget->SetupAttachment(RootComponent);

	// Creates a sound base component for the police siren
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
	// Calls the parent class's Tick() function
	Super::Tick(DeltaTime);

}

// Function to handle interaction with the land phone
void ALandPhone::InteractWithMe() {

	// Logs a warning message indicating that the player has interacted with the land phone
	UE_LOG(LogTemp, Warning, TEXT("You have interacted with me."));

	// Play the police siren sound in 2D space
	UGameplayStatics::PlaySound2D(GetWorld(), PoliceSiren, 1, 1, 0, NULL, false, true);

	// Sets up a timer to call the ChangeLevel function after a specified delay
	FTimerHandle TimerHandle;
	float DelayInSeconds = 5.0f;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALandPhone::ChangeLevel, DelayInSeconds, false);
}

// Function to show the interaction widget
void ALandPhone::ShowInteractionWidget() {
	// Sets the visibility of the interaction widget to true
	InteractionWidget->SetVisibility(true);
}

// Function to hide the interaction widget
void ALandPhone::HideInteractionWidget() {
	// Sets the visibility of the interaction widget to false
	InteractionWidget->SetVisibility(false);
}

// Function to change the level after a delay
void ALandPhone::ChangeLevel()
{
	// Opens a specified level named "ToBeContEndGameMap"
	UGameplayStatics::OpenLevel(GetWorld(), "ToBeContEndGameMap");
}