#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> generateAnswer(int maxDigits);
void getValidGuess(int maxDigits, vector<int>& guessVec);
void getGuesses(vector<int>& answerVec, int maxDigits);
bool hasOnlyDigits(const string s);
bool isUnique(const vector<int>& v);

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
