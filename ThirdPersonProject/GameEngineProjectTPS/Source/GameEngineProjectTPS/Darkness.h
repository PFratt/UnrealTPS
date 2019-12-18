// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Darkness.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class UCharacterMovementComponent;

UCLASS()
class GAMEENGINEPROJECTTPS_API ADarkness : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADarkness();

	UPROPERTY(EditAnywhere)
		USoundBase* Sound;


	UPROPERTY(VisibleAnywhere)
		UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere)
		 UStaticMeshComponent* MeshComponent;
	
	
	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* PSComponent;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		UCharacterMovementComponent* CharacterMovementComponent;

	UPROPERTY(VisibleAnywhere)
		float HP = 1.5f;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	static void SimpleMoveToActor(AController* Controller, const AActor* Goal);

	/*void UAIBlueprintHelperLibrary::SimpleMoveToActor(AController* Controller, const AActor* Goal) override;*/
	
};
