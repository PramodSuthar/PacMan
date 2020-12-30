// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food.generated.h"

class USoundCue;

UENUM(BlueprintType)
enum class EFoodType : uint8
{
	Regular,
	PowerUp
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoodEatenEvent, EFoodType, FoodType); //Delegate who will have one parameter which is FoodType which is connected to the Event FoodEaten.

UCLASS()
class PACMAN_API AFood : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Consume();

	UPROPERTY(EditAnywhere)
		EFoodType FoodType = EFoodType::Regular;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FFoodEatenEvent FoodEatenEvent; //Using both BlueAssignable and BlueprintCallable means that we can assign it and also call it from within a Blueprint

private:
	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;

};
