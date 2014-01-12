#include "cannonball.h"
#include "cannonball.cpp"

int main() {
	int cmd;
	double v = 0.0;
	while (true) {
		cout << "Velg et program:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) Manuell simulering" << endl;
		cout << "2) Optimal vinkel" << endl;
		cout << "3) Skyt på blink" << endl;
		cout << "Valg: ";
		cin >> cmd;
		cout << endl;
		switch(cmd) {
			case 0:
				return 0;
				break;
			case 1:
				simulate();
				break;
			case 2:
				cout << "Optimal vinkel" << endl << "Hastighet: ";
				cin >> v;
				optimalAngleForMaxDistance(v);
				break;
			case 3:
				playTargetPractice();
				break;
		}

	}
	return 0;
}