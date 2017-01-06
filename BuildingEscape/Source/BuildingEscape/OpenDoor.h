//Copyright (C) 2017 Olirexen Games, Ltd

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	
	void OpenDoor();
	void CloseDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:

	UPROPERTY(EditAnywhere)
	float OpenAngle = 180.f;

	UPROPERTY(EditAnywhere)
	float CloseAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.6f; // The default delay to wait before closing the door, this is editable in the editor.

	float LastDoorOpenTime; // Float that is set to a value when the door is opened

	UPROPERTY(VisibleAnywhere)
	AActor* ActorThatOpens; // Remeber pawn inherits from Actor
	AActor* Owner; // The owning door
	
};
