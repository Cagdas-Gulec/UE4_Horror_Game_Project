#include "MyCharacter.h"
#include "InteractionInterface.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	

	CameraBoom = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	
	CameraBoom->SetupAttachment(RootComponent);


	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bDead = false;

	InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Interaction box"));
	InteractionBox->SetupAttachment(RootComponent);



	
}





// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AActor*>OverlappingActors;

	InteractionBox->GetOverlappingActors(OverlappingActors);

	if (OverlappingActors.Num() == 0)
	{
		if (Interface)
		{
			Interface->HideInteractionWidget();
			Interface=nullptr;
		}
		return;
	}

	AActor* ClosestActor = OverlappingActors[0];

	for (auto CurrentActor : OverlappingActors)
	{
		if(GetDistanceTo(CurrentActor)<GetDistanceTo(ClosestActor))
		{
			ClosestActor = CurrentActor;
		}
	}

	if (Interface) {
		Interface->HideInteractionWidget();
	}

	Interface = Cast<IInteractionInterface>(ClosestActor);

	if (Interface) {
		Interface->ShowInteractionWidget();
	}

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);


	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);


	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMyCharacter::OnInteract);

}



void AMyCharacter::MoveForward(float Axis)
{
	if (!bDead) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);

	}



}

void AMyCharacter::MoveRight(float Axis)
{
	if (!bDead) {

		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);

	}




}



void AMyCharacter::OnInteract() {


	if (Interface) {
		Interface->InteractWithMe();
	}
}