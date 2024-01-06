// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "Components/WidgetComponent.h"
#include "LandPhone.generated.h"

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
	virtual void InteractWithMe() override;
	virtual void ShowInteractionWidget() override;
	virtual void HideInteractionWidget() override;


private:

	UPROPERTY(EditAnywhere)
		USceneComponent* _RootComponent;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* LandPhoneMesh;

	UPROPERTY(EditAnywhere)
		UWidgetComponent* InteractionWidget;

	UPROPERTY(EditAnywhere)
		class USoundBase* PoliceSiren;

	UFUNCTION()
		void ChangeLevel();
};
