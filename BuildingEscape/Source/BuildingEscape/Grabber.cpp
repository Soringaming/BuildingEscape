

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// Temp log
	// TODO Remove logging message.
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"))
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Grab the players veiw point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	OUT PlayerViewPointLocation,
	OUT PlayerViewPointRotation
	);

	// TODO, remove this silly log sometime when you know you wont need it.
	// Might need it for later, so keep it for now.
	/*UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"),
		*PlayerViewPointLocation.ToString(),
		*PlayerViewPointRotation.ToString()
	)*/

	FVector TraceLineEndPoint = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * Reach);

	// Draw a debug line 

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		TraceLineEndPoint,
		FColor(255, 0, 0),
		false,
		0.f,
		0,
		10.f
	);

	// Setup query paramaters
	FCollisionQueryParams TraceParamaters(FName(TEXT("")), false, GetOwner());

	// LineTrace (AKA Ray-cast) out to reach distance

	FHitResult Hit;

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		TraceLineEndPoint,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParamaters
	);

	AActor* HitActor = Hit.GetActor();

	if(HitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor hit: %s"), *HitActor->GetName())
	}
	
	// See if we have hit anything, and if we have what is it?
}

