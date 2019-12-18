// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbReturn.h"


// Sets default values
AOrbReturn::AOrbReturn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	
	CollisionComponent->InitSphereRadius(32.0f);
	
	RootComponent = CollisionComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	
	PSComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PSComponent"));*/
	
	

}

// Called when the game starts or when spawned
void AOrbReturn::BeginPlay()
{
	Super::BeginPlay();

	//ProjectileMovementComponent->
	/*TWeakObjectPtr< USceneComponent > HomingTargetComponent;

	HomingTargetComponent = Player->GetRootComponent;*/

}

// Called every frame
void AOrbReturn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//void AOrbReturn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

