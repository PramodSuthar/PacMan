// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanController.h"

#include "PacmanPawn.h"

APacmanPawn* APacmanController::GetPacmanPawn() const
{
	return Cast<APacmanPawn>(GetPawn()); //Get the Pawn Controller by casting it APacmanPawn

}


void APacmanController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Binding the movements of Pacman Pawn
	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacmanController::MoveUp);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacmanController::MoveDown);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacmanController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacmanController::MoveRight);

}


//Functions to move Pacman Pawn

void APacmanController::MoveUp()
{

	if(GetPacmanPawn() != nullptr)
	{
		GetPacmanPawn()->SetDirection(FVector::UpVector);
	}
}

void APacmanController::MoveDown()
{
	if (GetPacmanPawn() != nullptr)
	{
		GetPacmanPawn()->SetDirection(FVector::DownVector);
	}

}

void APacmanController::MoveLeft()
{
	if (GetPacmanPawn() != nullptr) {
		GetPacmanPawn()->SetDirection(FVector::LeftVector);
	}
}

void APacmanController::MoveRight()
{
	if (GetPacmanPawn() != nullptr) {
		GetPacmanPawn()->SetDirection(FVector::RightVector);
	}
}
