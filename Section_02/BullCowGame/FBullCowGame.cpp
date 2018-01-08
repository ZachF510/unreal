#pragma once

#include "FBullCowGame.h"
#include <string>
#include <map>

//make syntax Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; //assumes 3 to 6 letter word
}

void FBullCowGame::Reset() {
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	bGameWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsAlphabetic(Guess)) {
		return EGuessStatus::Not_Alphabetic;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else {
		return EGuessStatus::OK;
	}
}

//receives a valid guess, incriments try, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length(); //assume words are the same length

	//loop through all letters in the hidden word
	for (int32 HiddenChar = 0; HiddenChar < WordLength; HiddenChar++) {
		//compare letters against the guess word
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++) {
			if (Guess[GuessChar] == MyHiddenWord[HiddenChar]) {
				if (HiddenChar == GuessChar) { //if they're in the same place
					BullCowCount.Bulls++; //incriment bulls
				}
				else {
					BullCowCount.Cows++; //must be a cow
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameWon = true;
	}
	else {
		bGameWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsAlphabetic(FString Guess) const {
	//loop through each letter of guess
	for (auto Letter : Guess) {
		if (!isalpha(Letter)) { //if letter is not alphabetic return false
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const {
	//loop through each letter of guess
	for (auto Letter : Guess) {
		if (!islower(Letter)) { //if letter is not lower case return false
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsIsogram(FString Guess) const {
	//create map
	TMap <char, bool> LetterSeen;
	//loop through each letter of guess
	for (auto Letter : Guess) {
		Letter = tolower(Letter); //change to lowercase to remove implicit dependencies
		if (LetterSeen[Letter]) { //if letter already exists return false
			return false;
		}
		else { //add true to map to show letter has appeared
			LetterSeen[Letter] = true;
		}
	}
	return true;
}
