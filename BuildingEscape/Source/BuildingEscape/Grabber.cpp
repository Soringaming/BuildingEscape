

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponenet();
	SetUpInputComponent();

}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RayCast();

}


// Setup (assumed) attached Physics Handle Component
void UGrabber::FindPhysicsHandleComponenet()
{
	/// Look for attached Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		// PhysicsHandle was found
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to find the Physics Handle Component for: %s"), *GetOwner()->GetName());
	}
}

// Setup (assumed) attached input component
void UGrabber::SetUpInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("The input component for %s has been found."), *GetOwner()->GetName());
		/// Bind the input action
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("The input component for %s is missing!"), *GetOwner()->GetName());
	}
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed"));
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grab released"));
}

// Raycasting for Actors in the game with Physics bodys
void UGrabber::RayCast()
{
	// Grab the players veiw point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector TraceLineEndPoint = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * Reach);

	// Draw a debug line 
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, TraceLineEndPoint, FColor(255, 0, 0), false, 0.f, 0, 10.f);

	// Setup query paramaters
	FCollisionQueryParams TraceParamaters(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(OUT Hit, PlayerViewPointLocation, TraceLineEndPoint, 
	FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParamaters);

	AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor hit: %s"), *HitActor->GetName())
	}
}

