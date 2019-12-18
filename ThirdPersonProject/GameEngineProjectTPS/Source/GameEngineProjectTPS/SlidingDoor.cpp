// Fill out your copyright notice in the Description page of Project Settings.


#include "SlidingDoor.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"


// Sets default values
ASlidingDoor::ASlidingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("Root"));
	StaticMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Trigger = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ASlidingDoor::OnTriggerOverlap);

	Trigger->OnComponentEndOverlap.AddDynamic(this, &ASlidingDoor::OnTriggerEndOverlap);
}

// Called when the game starts or when spawned
void ASlidingDoor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ASlidingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DoorMovement(DeltaTime);

}

void ASlidingDoor::CloseDoor()
{
	IsMoving = true;
	DoorIsOpen = false;
	UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
}

void ASlidingDoor::OpenDoor()
{
	IsMoving = true;
	DoorIsOpen = true;
	UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());
	
}

void ASlidingDoor::DoorMovement(float DeltaTime)
{
	if (IsMoving) {

		if (StaticMesh != nullptr) {

			if (DoorIsOpen)
			{
				if (FMath::IsNearlyEqual(StaticMesh->RelativeLocation.Y, Distance, 1.5f)) {

					StaticMesh->SetRelativeLocation(FVector(0.f, Distance, 0.f));
					IsMoving = false;
				}
				else {

					float YPosUpdate = FMath::FInterpConstantTo(StaticMesh->RelativeLocation.Y, Distance, DeltaTime, 50.f);
					StaticMesh->SetRelativeLocation(FVector(0.f, YPosUpdate, 0.f));
				}
				
			}
			else {

				if (FMath::IsNearlyEqual(StaticMesh->RelativeLocation.Y, 0.f, 1.5f)) {

					StaticMesh->SetRelativeLocation(FVector::ZeroVector);
					IsMoving = false;
				}
				else {

					float YPosUpdate = FMath::FInterpConstantTo(StaticMesh->RelativeLocation.Y, 0.f, DeltaTime, 50.f);
					StaticMesh->SetRelativeLocation(FVector(0.f, YPosUpdate, 0.f));
				}

			}
		}
	}
}

void ASlidingDoor::OnTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	OpenDoor();
}

void ASlidingDoor::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CloseDoor();
}



