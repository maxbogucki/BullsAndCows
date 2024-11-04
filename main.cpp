// Max Bogucki, CS318, P02
// A Bulls and Cows game where you try to guess a four number digit. 
// If you have a digit in the right place you get a bull,
// if you have a correct digit but in the wrong place you get a cow.
// You play until you get 4 bulls and win the game.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>

#include "BullsAndCows.h"

using namespace std;

int main() {
	char playAgain = 'Y';
	int maxDigits = 4;

	cout << "*** P02 Bulls and Cows ***" << endl << endl;

	while (playAgain == 'Y' || playAgain == 'y') {
		vector<int> answerVec = generateAnswer(maxDigits);

		cout << "************* New Game *************" << endl << endl;

		cout << "Number to Guess: ";
		for(int num : answerVec) {
			cout << num;
		}
		cout << endl << endl;

		cout << "\tGuesses entered must be digits 0-9, 4 digits long, no repetition" << endl << endl;

		getGuesses(answerVec, maxDigits);

		cout << "Enter Y to play again (anything else to end): ";
		cin >> playAgain;
		cout << endl;
	}
}



