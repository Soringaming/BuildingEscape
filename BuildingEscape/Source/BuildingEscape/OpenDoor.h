//Copyright (C) 2017 Olirexen Games, Ltd

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

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

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;

private:

	UPROPERTY(EditAnywhere)
	float OpenAngle = 180.f;

	UPROPERTY(EditAnywhere)
	float CloseAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr; // this triggered me, mai dude. ALL THE PUNS

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.1f; // The default delay to wait before closing the door, this is editable in the editor.

	float LastDoorOpenTime; // Float that is set to a value when the door is opened

	UPROPERTY(VisibleAnywhere)
	AActor* Owner = nullptr; // The owning door

	// Returns the weight in kg
	float GetTotalMassOfActorsOnPlate();

	UPROPERTY(EditAnywhere)
	float MinimumWieghtToTrigger = 5.f;
	
};
