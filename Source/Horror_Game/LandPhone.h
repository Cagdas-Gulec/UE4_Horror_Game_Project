#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "Components/WidgetComponent.h"
#include "LandPhone.generated.h"

// Declares the LandPhone class, derived from AActor and implementing the IInteractionInterface
UCLASS()
class HORROR_GAME_API ALandPhone : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALandPhone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Functions required by the InteractionInterface
	virtual void InteractWithMe() override;
	virtual void ShowInteractionWidget() override;
	virtual void HideInteractionWidget() override;


private:
	// Components and properties of the LandPhone class

	UPROPERTY(EditAnywhere)
		USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* LandPhoneMesh;

	UPROPERTY(EditAnywhere)
		UWidgetComponent* InteractionWidget;

	UPROPERTY(EditAnywhere)
		class USoundBase* PoliceSiren;

	// Private function to change the level after a delay
	UFUNCTION()
		void ChangeLevel();
};
