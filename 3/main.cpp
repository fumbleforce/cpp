#include "utilities.h"
#include "utilities.cpp"
#include "tests.cpp"
#include "tests.h"
#include "mastermind.cpp"
#include "mastermind.h"


int main() {
	srand(time(0));
	int choice;
	cout << "skriv 1 for mastermind, alt annet for tester";
	cin >> choice;
	if (choice == 1) {
		playMastermind();
	}
	else {

		cout << "Noen tilfeldige tall fra 1 til 100:"<< endl;
		for (int i=0;i<10;i++) cout << randomWithLimits(1, 100) << " ";

		cout << endl << endl << "Noen tilfeldige bokstaver fra A til Z:" << endl;
		for (int i=0;i<10;i++) cout << randomCharWithLimits('A', 'Z') << " ";

		/* 2a
		v0 vil være 5, siden inkrementfunksjonen bare kopierer v0 ved kjøring.
		*/

		cout << endl << endl;
		testPart2();
		cout << endl << endl;
		testPart3();
		cout << endl << endl;
		testPart4();
	}

	return 0;
}