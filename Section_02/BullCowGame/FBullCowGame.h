#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); //constructor
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	void Reset();
	bool CheckValidGuess(std::string);

private:
	int MyMaxTries;
	int MyCurrentTry;
};