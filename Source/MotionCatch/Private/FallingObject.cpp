// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingObject.h"

// Sets default values
AFallingObject::AFallingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

}

// Called when the game starts or when spawned
void AFallingObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFallingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Adding motion component
	FVector NewLocation = GetActorLocation();
	NewLocation.X += 100.f * DeltaTime;
	SetActorLocation(NewLocation);

}

