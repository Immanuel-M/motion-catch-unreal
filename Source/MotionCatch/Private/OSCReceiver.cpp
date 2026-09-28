#include "OSCReceiver.h"
#include "OSCManager.h"

AOSCReceiver::AOSCReceiver()
{
	PrimaryActorTick.bCanEverTick = true;
	ReceivedX = 0.5f;
}

void AOSCReceiver::BeginPlay()
{
	Super::BeginPlay();

	// Create an OSC server listening on this machine, port 8000
	OSCServer = UOSCManager::CreateOSCServer(TEXT("127.0.0.1"), 8000, false, true, TEXT("MotionCatchServer"), this);

	if (OSCServer)
	{
		// Tell the server to call our function when a message arrives
		OSCServer->OnOscMessageReceived.AddDynamic(this, &AOSCReceiver::OnOSCMessageReceived);
		UE_LOG(LogTemp, Warning, TEXT("OSC Server started on port 8000"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to start OSC Server"));
	}
}

void AOSCReceiver::OnOSCMessageReceived(const FOSCMessage& Message, const FString& IPAddress, int32 Port)
{
	// Pull the first float out of the message
	TArray<float> Floats;
	UOSCManager::GetAllFloats(Message, Floats);

	if (Floats.Num() > 0)
	{
		ReceivedX = Floats[0];
		UE_LOG(LogTemp, Warning, TEXT("Received X: %f"), ReceivedX);
	}
}

void AOSCReceiver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}