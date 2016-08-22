// Fill out your copyright notice in the Description page of Project Settings.

#include "QuickStart.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TotalDamage = 200;
	DamageTimeInSeconds = 1.f;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFloatingActor::PostInitProperties()
{
	Super::PostInitProperties();

	CalculateValues();
}

void AFloatingActor::CalculateValues()
{
	this -> DamagePerSecond = (this -> TotalDamage) / (this -> DamageTimeInSeconds);
}

#if	WITH_EDITOR
void AFloatingActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalculateValues();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime * 0.8) - FMath::Sin(RunningTime));
	float DeltaMovementY = (FMath::Cos(RunningTime + DeltaTime * 0.8) - FMath::Cos(RunningTime));
	NewLocation.Z += DeltaHeight * (this -> Height);	//Scale our height by a factor of 20
	NewLocation.Y += DeltaMovementY * (this -> Height);
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);


}

