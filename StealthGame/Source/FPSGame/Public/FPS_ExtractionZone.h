// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPS_ExtractionZone.generated.h"

class UBoxComponent;

UCLASS()
class FPSGAME_API AFPS_ExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPS_ExtractionZone();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Component")
	UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UDecalComponent* DecalComp;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* ObjectiveMissingSound;
	
};
