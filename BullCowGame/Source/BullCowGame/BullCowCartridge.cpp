// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();//Setting Up Game

    PrintLine(TEXT("The number of possible words is %i"),Words.Num());
    
    // int32 i;
    // for(i=0;i<10;i++){
    //     if(Words[i].Len()>=4 && Words[i].Len()<=8){
    //         PrintLine(TEXT("%s"),*Words[i]);
    //     }else{
    //         continue;
    //     }
    // }
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
    HiddenWord=Words[FMath::RandRange(0, 577)];
    Lives=HiddenWord.Len();
    bGameOver=false;
    //Welcoming the layer
    PrintLine(TEXT("Welcome to bull cow game"));
    PrintLine(TEXT("You have %i lives"),Lives);
    PrintLine(TEXT("Guess the %i letter word."),HiddenWord.Len()); //Magic number remove
    // PrintLine(TEXT("The hidden word is: %s."),*HiddenWord);// Debug line; We use the star is %s is a part of the c library we use ( to access it.)
    PrintLine(TEXT("Press enter to continue."));

}

void UBullCowCartridge::EndGame(){


    PrintLine(TEXT("\nPress Enter to play again"));
    bGameOver=true;
}
void UBullCowCartridge::ProcessGuess(const FString& Guess){

    PrintLine(Guess);
    if(Guess==HiddenWord){
        PrintLine(TEXT("You win!"));
        EndGame();
        return;
    }


int32 index;
int32 j;
    for(index=0;index<Guess.Len();index++){
        for (j = index+1; j < Guess.Len() ; j++)
        {
            if(Guess[index]==Guess[j]){
                PrintLine(TEXT("It should be an isogram!"));
                return;
            }
        }
        
    }


    if (HiddenWord.Len()!=Guess.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long"),HiddenWord.Len());
            return;
        }

    FBullCowCount Bulls_Cows= GetBullCows( Guess );

    PrintLine(TEXT("You have %i Bulls and %i Cows"),Bulls_Cows.Bulls,Bulls_Cows.Cows);
    PrintLine(TEXT("You are wrong! You have lost a life.\n Lives remaining: %i"),--Lives);


        if(Lives<0){
        ClearScreen();
        PrintLine(TEXT("You have no lives left"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
        }


}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess ) const{
    
    FBullCowCount Count;

    //for every index Guess is same as index Hidden, BullCount++
    //if not a bull was it a cow? if yes, CowCount++

    for(int32 GuessIndex = 0; GuessIndex < Guess.Len() ;GuessIndex++){
        if (Guess[GuessIndex]==HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if(Guess[GuessIndex]==HiddenWord[HiddenIndex]){
                Count.Cows++;
                break;
            }
        }
        
        
    }
    return Count;
}