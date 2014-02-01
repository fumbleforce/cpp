#include <iostream>
#include <cstdlib>
#include "utilities.h"
using namespace std;


int checkCharactersAndPosition(char guess[], char code[], int length) {
	int numCorrect = 0;
	for (int i = 0; i < length; i++) {
		if (guess[i] == code[i]) numCorrect++;
	}
	return numCorrect;
}

int checkCharacters(char guess[], char code[], int length, int letters) {
	int numCorrect = 0;
	int numGuess;
	int numCode;
	for (int i = 0; i < letters; i++) {
		numCode = countOccurencesOfCharacter(code, length, 'A'+i);
		numGuess = countOccurencesOfCharacter(guess, length, 'A'+i);
		if (numGuess <= numCode) {
			numCorrect += numGuess;
		}
		else {
			numCorrect += numCode;
		}
	}
	return numCorrect;
}


void playMastermind() {
	const int SIZE = 4;
	const int LETTERS = 6;
	const int TRIES = 10;

	char guess[SIZE+1];
	char code[SIZE+1];

	int correctPos, correctNum, tryCount;

	randomizeCString(code, SIZE+1, 'A', 'A'+LETTERS);
	cout << "Kode: " << code << endl;
	cout << "Prøv å gjett riktig kode på størrelse " << SIZE << endl;

	tryCount = 0;
	while (tryCount < TRIES) {
		readInputToCString(guess, SIZE, 'A', 'A'+LETTERS);
		correctPos = checkCharactersAndPosition(guess, code, SIZE);
		correctNum = checkCharacters(guess, code, SIZE, LETTERS);

		cout << "Du har " << correctPos << " bokstaver i riktig posisjon" << endl;
		cout << "Du har " << correctNum << " riktige bokstaver" << endl;

		if (correctPos == SIZE) {
			cout << "Du gjettet riktig! Du vant." << endl;
			return;
		}
		tryCount += 1;
	}
	cout << "Du tapte :( Du er elendig i dette spillet, beklager." << endl;
	
}

