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

using namespace std;

vector<int> generateAnswer(int maxDigits);
void getValidGuess(int maxDigits, vector<int>& guessVec);
void getGuesses(vector<int>& answerVec, int maxDigits);
bool hasOnlyDigits(const string s);
bool isUnique(const vector<int>& v);

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

vector<int> generateAnswer(int maxDigits) {
	srand(time(0));

	vector<int> answer;
	int randomNumber = 0;

	while (answer.size() < maxDigits) {
		randomNumber = rand() % 10;

		bool isDuplicate = false;
		for (int i = 0; i < answer.size(); i++) {
			if (randomNumber == answer[i]) {
				isDuplicate = true;
				break;
			}
		}

		if (!isDuplicate) {
			answer.push_back(randomNumber);
		}
	};

	return answer;
}

void getValidGuess(int maxDigits, vector<int>& guessVec) {
	bool isValid = false;

	while (!isValid) {

		string input;
		cout << "\tEnter Guess: ";
		cin >> input;

		isValid = true; // assume it is true until proven otherwise

		// check if inputted string is a digit
		if (!hasOnlyDigits(input)) {
			cout << "\t\tError: Guess can only contain digits -- try again!" << endl << endl;
			isValid = false;
			continue;
		}

		guessVec.clear();

		for (char c : input) {
			guessVec.push_back(c - '0');
		}

		// check if guess contains maxDigits
		if (guessVec.size() != maxDigits) {
			cout << "\t\tError: Guess must be " << maxDigits << " digits -- try again!" << endl << endl;
			isValid = false;
			continue;
		}

		// check if there are duplicates
		if (!isUnique(guessVec)) {
			cout << "\t\tError: Digits can not be repeated -- try again!" << endl << endl;
			isValid = false;
			continue;
		}
	}

	return 0;
}

void getGuesses(vector<int>& answerVec, int maxDigits) {
	vector<int> guessVec;

	bool won = false;
	int guessCount = 0;

	while (!won) {

		getValidGuess(maxDigits, guessVec);
		guessCount++;

		int bulls = 0, cows = 0;
		for (int i = 0; i < maxDigits; i++) {
			for (int j = 0; j < maxDigits; j++) {
				if (guessVec[i] == answerVec[j]) {
					if (i == j) {
						bulls++;
					}
					else {
						cows++;
					}
				}
			}
		}

		cout << "\t\tGuess #" << guessCount << ": Bulls " << bulls << " Cows " << cows << endl << endl;

		if (bulls == maxDigits) {
			cout << "\t*** YOU WIN! ***" << endl << endl;
			won = true;
		}
	}
}

bool hasOnlyDigits(const string s) {
	for (char c : s) {
		if (c < '0' || c > '9') {
			return false;
		}
	}

	return true;
}

bool isUnique(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				return false;
			}
		}
	}

	return true;
}

