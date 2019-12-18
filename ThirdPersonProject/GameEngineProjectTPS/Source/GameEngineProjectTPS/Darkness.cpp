// Fill out your copyright notice in the Description page of Project Settings.


#include "Darkness.h"
#include "Engine.h"
#include "GameEngineProjectTPSCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


// Sets default values
ADarkness::ADarkness()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxComponent->SetupAttachment(MeshComponent);

	PSComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PSComponent"));
	PSComponent->SetupAttachment(MeshComponent);

	CharacterMovementComponent = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("CharacterMovementComponent"));

}

// Called when the game starts or when spawned
void ADarkness::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADarkness::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HP <= 0)
	{
		Destroy();
	}


}

void ADarkness::SimpleMoveToActor(AController* Controller, const AActor* Goal)
{
}


//void UAIBlueprintHelperLibrary::SimpleMoveToActor(AController* Controller, const AActor* Goal)
//{
//	UNavigationSystemV1* NavSys = Controller ? FNavigationSystem::GetCurrent<UNavigationSystemV1>(Controller->GetWorld()) : nullptr;
//	if (NavSys == nullptr || Goal == nullptr || Controller == nullptr || Controller->GetPawn() == nullptr)
//	{
//		UE_LOG(LogNavigation, Warning, TEXT("UNavigationSystemV1::SimpleMoveToActor called for NavSys:%s Controller:%s controlling Pawn:%s with goal actor %s (if any of these is None then there's your problem"),
//			*GetNameSafe(NavSys), *GetNameSafe(Controller), Controller ? *GetNameSafe(Controller->GetPawn()) : TEXT("NULL"), *GetNameSafe(Goal));
//		return;
//	}
//
//	UPathFollowingComponent* PFollowComp = InitNavigationControl(*Controller);
//
//	if (PFollowComp == nullptr)
//	{
//		FMessageLog("PIE").Warning(FText::Format(
//			LOCTEXT("SimpleMoveErrorNoComp", "SimpleMove failed for {0}: missing components"),
//			FText::FromName(Controller->GetFName())
//		));
//		return;
//	}
//
//	if (!PFollowComp->IsPathFollowingAllowed())
//	{
//		FMessageLog("PIE").Warning(FText::Format(
//			LOCTEXT("SimpleMoveErrorMovement", "SimpleMove failed for {0}: movement not allowed"),
//			FText::FromName(Controller->GetFName())
//		));
//		return;
//	}
//
//	const bool bAlreadyAtGoal = PFollowComp->HasReached(*Goal, EPathFollowingReachMode::OverlapAgentAndGoal);
//
//	// script source, keep only one move request at time
//	if (PFollowComp->GetStatus() != EPathFollowingStatus::Idle)
//	{
//		PFollowComp->AbortMove(*NavSys, FPathFollowingResultFlags::ForcedScript | FPathFollowingResultFlags::NewRequest
//			, FAIRequestID::AnyRequest, bAlreadyAtGoal ? EPathFollowingVelocityMode::Reset : EPathFollowingVelocityMode::Keep);
//	}
//
//	if (bAlreadyAtGoal)
//	{
//		PFollowComp->RequestMoveWithImmediateFinish(EPathFollowingResult::Success);
//	}
//	else
//	{
//		const ANavigationData* NavData = NavSys->GetNavDataForProps(Controller->GetNavAgentPropertiesRef());
//		if (NavData)
//		{
//			FPathFindingQuery Query(Controller, *NavData, Controller->GetNavAgentLocation(), Goal->GetActorLocation());
//			FPathFindingResult Result = NavSys->FindPathSync(Query);
//			if (Result.IsSuccessful())
//			{
//				Result.Path->SetGoalActorObservation(*Goal, 100.0f);
//				PFollowComp->RequestMove(FAIMoveRequest(Goal), Result.Path);
//			}
//			else if (PFollowComp->GetStatus() != EPathFollowingStatus::Idle)
//			{
//				PFollowComp->RequestMoveWithImmediateFinish(EPathFollowingResult::Invalid);
//			}
//		}
//	}
//}
