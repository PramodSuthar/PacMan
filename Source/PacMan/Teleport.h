// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleport.generated.h"


class USoundCue;
UCLASS()
class PACMAN_API ATeleport : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleport();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TeleportToTarget(AActor* Actor);

	UPROPERTY(EditAnywhere)
		ATeleport* Target = nullptr;

	UPROPERTY(EditAnywhere)
		USoundCue* TeleportSound;
	
	UFUNCTION() void OnOverlapBegin(AActor* , AActor* OtherActor);
};