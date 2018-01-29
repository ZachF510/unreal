// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerupActor.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"


// Sets default values
ASPowerupActor::ASPowerupActor()
{
	PowerupInterval = 0.0f;
	TotalNrOfTicks = 0;

	bIsPowerupActive = false;

	SetReplicates(true);
}

void ASPowerupActor::ActivatePowerup()
{
	OnActivated();

	bIsPowerupActive = true;
	OnRep_PowerupActive();

	if (PowerupInterval > 0.0f)
	{
		GetWorldTimerManager().SetTimer(TimerHandle_PowerupTick, this, &ASPowerupActor::OnTickPowerUp, PowerupInterval, true);
	}
	else
	{
		OnTickPowerUp();
	}
}

void ASPowerupActor::OnTickPowerUp()
{
	TicksProcessed++;

	OnPowerUpTicked();

	if (TicksProcessed >= TotalNrOfTicks)
	{
		OnExpired();

		bIsPowerupActive = true;
		OnRep_PowerupActive();

		GetWorldTimerManager().ClearTimer(TimerHandle_PowerupTick);
	}
}

void ASPowerupActor::OnRep_PowerupActive()
{
	OnPowerUpStateChanged(bIsPowerupActive);
}

void ASPowerupActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASPowerupActor, bIsPowerupActive);
}
