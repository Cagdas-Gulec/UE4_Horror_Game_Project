#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "Components/PointLightComponent.h"
#include "Components/WidgetComponent.h"
#include "LightSwitch.generated.h"


UCLASS()
class HORROR_GAME_API ALightSwitch : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	//Sets default values for this actor's properties.
	ALightSwitch();

protected:
	//Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void InteractWithMe() override;
	virtual void ShowInteractionWidget() override;
	virtual void HideInteractionWidget() override;

	UFUNCTION(BlueprintCallable)
		void UgaBuga();

private:

	//Creation of root components.
	UPROPERTY(EditAnywhere)
	USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* LightSwitchMesh;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light2;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light3;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light4;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light5;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light6;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light7;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light8;

	UPROPERTY(EditAnywhere)
		UPointLightComponent* Light9;

	UPROPERTY(EditAnywhere)
		class USoundBase* PowerUpSound;

	UPROPERTY(EditAnywhere)
		class USoundBase* PowerDownSound;

	UPROPERTY(EditAnywhere)
		UWidgetComponent* InteractionWidget;

	bool bIsOn = true; //Bool for tracking if the lights are on or off.
};
