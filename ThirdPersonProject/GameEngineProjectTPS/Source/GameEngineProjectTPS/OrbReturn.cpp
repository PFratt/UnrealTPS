// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbReturn.h"
#include "Engine.h"

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
	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = CollisionComponent;
	//MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//MeshComponent->SetupAttachment(CollisionComponent);
	/*ProjectileMovement->InitialSpeed = 2000;
	ProjectileMovement->ProjectileGravityScale = 0.0;
	ProjectileMovement->HomingTargetComponent->Activate();
	ProjectileMovement->HomingAccelerationMagnitude = 10000;*/
}

// Called when the game starts or when spawned
void AOrbReturn::BeginPlay()
{
	Super::BeginPlay();

	/*auto Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);*/
	//ProjectileMovement->HomingTargetComponent = TWeakObjectPtr<>

	//ProjectileMovement->SetVelocityInLocalSpace(FVector(0, 0, 100));
	

	//ProjectileMovementComponent->
	/*TWeakObjectPtr< USceneComponent > HomingTargetComponent;

	HomingTargetComponent = Player->GetRootComponent;*/



}

// Called every frame
void AOrbReturn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FMath::VInterpTo(GetActorLocation(), UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation(), DeltaTime, Speed);
	SetActorLocation(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation());
}

void AOrbReturn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Gotcha"));
	Destroy();
	/*if (OtherActor)//How do I cast to a BP?
	{

	}*/
}

// Called to bind functionality to input
//void AOrbReturn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

