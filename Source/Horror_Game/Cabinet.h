// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionInterface.h"
#include "Components/WidgetComponent.h"
#include "Cabinet.generated.h"

UCLASS()
class HORROR_GAME_API ACabinet : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACabinet();

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
		UStaticMeshComponent* CabinetMesh;

	UPROPERTY(EditAnywhere)
		UWidgetComponent* InteractionWidget;

};
