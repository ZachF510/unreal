#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0; //close the game
}

void PrintIntro() {
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";
	cout << endl;
	return;
}

void PlayGame() {
	//iterate for the number of guesses
	for (int NumGuesses = 0; NumGuesses < 5; NumGuesses++) {
		string Guess = GetGuess();
		//repeats the player's guess back to them
		cout << "Your guess was: " << Guess << endl << endl;
	}
	return;
}

string GetGuess() {
	//get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	//check if the player wants to play again
	cout << "Do you want to play again?\n";
	string Response = "";
	getline(cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}
}