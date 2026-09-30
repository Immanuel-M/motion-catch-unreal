// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingObject.h"
#include "OSCReceiver.h"
#include "Kismet/GameplayStatics.h"

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
	
	OSCReceiverRef = Cast<AOSCReceiver>(
		UGameplayStatics::GetActorOfClass(GetWorld(), AOSCReceiver::StaticClass())
	);
}

// Called every frame
void AFallingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (OSCReceiverRef)
	{
		float HandX = OSCReceiverRef->ReceivedX;
		float NewY = (HandX - 0.5f) * 1000.0f;

		FVector NewLocation = GetActorLocation();
		NewLocation.Y = NewY;
		SetActorLocation(NewLocation);
	}

}

