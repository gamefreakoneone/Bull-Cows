// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    //Welcoming the layer
    PrintLine(TEXT("Welcome to bull cow game"));
    PrintLine(TEXT("Guess the four letter word.")); //Magic number remove
    PrintLine(TEXT("Press enter to continue."));
    
    //Setting Up Game
    HiddenWord=TEXT("halo"); // Set the HiddenWord

    //Set Lives

    //Prompt Player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    //Checking Player guess

     //Move outside the function
    PrintLine(Input);
    if(Input==HiddenWord){
        PrintLine(TEXT("You win!"));
    }else{
        PrintLine(TEXT("You Lose!"));
    }
    //remove lives
    //Check if Isogram
    //Prompt to guess again
    //Check rigt number of characters
    //Prompt again
    // Check if Lives are reater than 0
    //if Yes GuessAgain
    //Show lives left
    //if No Show Gameover and HiddenWord
    //Prompt to Play Again. Press Enter to play again
    //Check User input
}