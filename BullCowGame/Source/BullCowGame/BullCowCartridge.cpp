// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();//Setting Up Game

    PrintLine(TEXT("The hidden word is: %s."),*HiddenWord);// Debug line; We use the star is %s is a part of the c library we use ( to access it.)

    // Set Lives

    //Prompt Player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{


    if (bGameOver){
        ClearScreen();
        SetupGame();
    }
    else{
        ProcessGuess(Input);
    }


}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cows!"));
    HiddenWord=TEXT("halo");
    Lives=HiddenWord.Len();
    bGameOver=false;
    //Welcoming the layer
    PrintLine(TEXT("Welcome to bull cow game"));
    PrintLine(TEXT("You have %i lives"),Lives);
    PrintLine(TEXT("Guess the %i letter word."),HiddenWord.Len()); //Magic number remove
    PrintLine(TEXT("Press enter to continue."));

}

void UBullCowCartridge::EndGame(){


    PrintLine(TEXT("\nPress Enter to play again"));
    bGameOver=true;
}
void UBullCowCartridge::ProcessGuess(FString Guess){

    PrintLine(Guess);
    if(Guess==HiddenWord){
        PrintLine(TEXT("You win!"));
        EndGame();
        return;
    }
    //remove lives
    //Check if Isogram

int32 index;
int32 j;
    for(index=0;index<Guess.Len();index++){
        for (j = index+1; j <=Guess.Len() ; j++)
        {
            if(Guess[index]==Guess[j]){
                PrintLine(TEXT("It should be an isogram!"));
                return;
            }
        }
        
    }

    //Prompt to guess again
    //Check rigt number of characters
    if (HiddenWord.Len()!=Guess.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long"),HiddenWord.Len());
            return;
        }
    PrintLine(TEXT("You are wrong! You have lost a life.\n Lives remaining: %i"),--Lives);

    // Check if Lives are greater than 0

    //Show lives left
    //if No Show Gameover and HiddenWord
        if(Lives<0){
        ClearScreen();
        PrintLine(TEXT("You have no lives left"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
        }

    //Prompt to Play Again. Press Enter to play again
    //Check User input
/* 
    If game is ovet then do ClearScreen() and SetupGame() the game
    else Checking Player guess
 */
     //Move outside the function

}