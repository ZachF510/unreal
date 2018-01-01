#pragma once

#include <string>

//make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid,
	OK,
	Wrong_Length,
	Not_Alphabetic,
	Not_Lowercase,
	Not_Isogram,
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);


private:
	//see constructor for initialisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameWon;

	bool IsAlphabetic(FString) const;
	bool IsLowercase(FString) const;
	bool IsIsogram(FString) const;
};
