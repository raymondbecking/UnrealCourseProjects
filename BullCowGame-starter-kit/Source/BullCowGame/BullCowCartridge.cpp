// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);

    Isograms = GetValidWords(Words);
    
    //Set up game
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{    
    if(bGameOver){
        ClearScreen();
        SetupGame();
    }
    else //Checking player guess
    {
        ProcessGuess(PlayerInput);        
    }
}

void UBullCowCartridge::SetupGame() //When the game starts or restarts
{        
    PrintLine(TEXT("Welcome to the bull cow game\n"));
    
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() -1)];
    Lives = HiddenWord.Len() * 2;  
    bGameOver = false;
    PrintLine(TEXT("You have %i total lives"), Lives);
    PrintLine(TEXT("Please press tab and type to guess \nthe %i letter hidden word: "), HiddenWord.Len());
    //PrintLine(TEXT("The hidden word is: %s"), *HiddenWord); // Debug line  
}

void UBullCowCartridge::EndGame() //When the game ends
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again..."));    
}

void UBullCowCartridge::ProcessGuess(const FString& Guess) //When a guess is made
{
    if (Guess == HiddenWord)
    {
        PrintLine(Guess + TEXT(" is the correct word! You win!"));
        EndGame();
        return;
    }

    if (HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("The word \"%s\" is not a %i letter word!"), *Guess, HiddenWord.Len());
        return;
    }

    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, try again")); 
        return;  
    } 

    --Lives;
    PrintLine(TEXT("\nYou have lost 1 life! %i lives left"), Lives);

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("\nThe hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
        
    }

    //Show player bulls and cows
    Count = GetBullCows(Guess);

    PrintLine(TEXT("You have %i Bulls and %i Cows"), Count.Bulls, Count.Cows);

    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}

//Check if the word is an isogram (no repeating letters) by comparing each letter to the rest of the word
bool UBullCowCartridge::IsIsogram(const FString& Word) const 
{
    for(int32 Index = 0; Index < Word.Len() -1; Index++)
    {
        for(int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }    
    return true;
}

//Creates a new array with valid words
TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;
    
    for(FString Word : WordList)
    {
        if(Word.Len() >= 4 && Word.Len() <= 8)
        {
            if(IsIsogram(Word))
            {
            ValidWords.Emplace(Word);
            }
        }
    }    
    return ValidWords;
}

//Counts the amount of bulls and cows in the Guess
FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount TCount;
    for(int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if(Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            TCount.Bulls++;
            continue;
        }
        
        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if(Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                TCount.Cows++;
                break;
            }
        }
        
    }
    
    
    return TCount;
}