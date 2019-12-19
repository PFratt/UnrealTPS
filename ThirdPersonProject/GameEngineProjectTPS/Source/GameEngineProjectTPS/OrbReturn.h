// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime\Engine\Classes\Components\SphereComponent.h"
#include "Runtime\Engine\Classes\GameFramework\ProjectileMovementComponent.h"
#include "OrbReturn.generated.h"


//class USphereComponent;

UCLASS()
class GAMEENGINEPROJECTTPS_API AOrbReturn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AOrbReturn();

	UPROPERTY(VisibleAnywhere)
		USphereComponent* CollisionComponent;
	/*UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;*/
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(EditAnywhere)
		AActor* Player;
	UPROPERTY(EditAnywhere)
		float Speed = 1000.0;

	/*UPROPERTY(EditAnywhere)
		USoundBase* Sound;

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere)
		class UParticleSystemComponent* PSComponent;*/

	//AGameEngineProjectTPSCharacter* Player;

	/*float HomingAccelerationMagnitude = 100.0f;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
