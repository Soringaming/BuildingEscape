

#pragma once

#include "Components/ActorComponent.h"
#include "DisplayVersion.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDisplayVersion : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDisplayVersion();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
private:

	// Text for the version number
	UPROPERTY(EditAnywhere)
	FString VersionNumber = "Version: Pre-Alpha v1.0.3";

	FLinearColor FontColor = FLinearColor(1.0f, 1.0f, 1.0f);
};
