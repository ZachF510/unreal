// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"

void ASProjectileWeapon::Fire()
{
	//spawn projectile
	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		// spawn the projectile at the muzzle
		//GetWorld()->SpawnActor<AActor>(ProjectileClass, EyeLocation, EyeRotation, ActorSpawnParams);
	}
}
