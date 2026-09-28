#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSCServer.h"
#include "OSCMessage.h"
#include "OSCReceiver.generated.h"

UCLASS()
class MOTIONCATCH_API AOSCReceiver : public AActor
{
	GENERATED_BODY()

public:
	AOSCReceiver();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UOSCServer* OSCServer;

	UPROPERTY()
	float ReceivedX;

	UFUNCTION()
	void OnOSCMessageReceived(const FOSCMessage& Message, const FString& IPAddress, int32 Port);
};