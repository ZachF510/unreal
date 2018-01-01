#include "FBullCowGame.h"
#include <map>

#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

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

// receives a VALID guess, incriments try, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length(); //assume words are the same length

	// loop through all letters in the hidden word
	for (int32 HiddenChar = 0; HiddenChar < WordLength; HiddenChar++) {
		// compare letters against the guess word
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++) {
			// if they match then
			if (Guess[GuessChar] == MyHiddenWord[HiddenChar]) {
				if (HiddenChar == GuessChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				}
				else {
					BullCowCount.Cows++; // must be a cow
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
		if (!isalpha(Letter)) { //if letter is not lower case return false
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
