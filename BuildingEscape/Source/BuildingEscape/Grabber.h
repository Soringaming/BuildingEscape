

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:

	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// The member function that allows us to grab things
	void Grab();

	// Called when the grab is released
	void Release();

	// Used to make sure we have a Physics Handle Component
	void UGrabber::FindPhysicsHandleComponenet();

	// Setup (assumed) attached input component
	void SetUpInputComponent();

	// Returns hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Return the start of the trace line
	FVector GetTraceLineStartPoint();

	// Return the end of the trace line
	FVector GetTraceLineEndPoint();

};
