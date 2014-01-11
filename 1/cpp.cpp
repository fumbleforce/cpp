#include <iostream>
#include <math.h>
using namespace std;

double round(double num) {
	return floor(num * 100 + 0.5)/100;
}

// oppgave 1a og 1c

/* Returtype void returnerer ingen verdier.
Den kan ikke brukes som et argument i cout, 
for eksempel, eller plasseres i variabler.
Men funksjonen kan selv printe til skjermen. */
void getAndPrintInteger() {
	int a;
	cout << "Skriv inn et tall: ";
	cin >> a;
	cout << "Du skrev " << a << endl;
}

// oppgave 1b og 1c

/* Denne funksjonen returnerer et heltall. 
Dette kan brukes i andre funksjoner eller plasseres i variabler. */
int getAndReturnInteger() {
	int a;
	cout << "Skriv inn et heltall: ";
	cin >> a;
	return a;
}


// oppgave 1d

/* getAndReturnInteger() brukes fordi den returnerer en verdi
som jeg kan lagre, og addere med en annen verdi om jeg btuker
funksjonen om igjen. getAndPrintInteger() returnerer ikke en verdi,
og det ville vært betydelig mer involvert å hente ut inputverdien
fra konsollen manuelt. */
void getAndPrintSum() {
	int a = getAndReturnInteger();
	int b = getAndReturnInteger();
	cout << a+b << endl;
}





// oppgave 2a og 2b

/* Vi bruker en for-løkke når vi vet hvor mange ganger vi skal
repetere. En while-løkke hadde passet bedre til et udefinert antall
repetisjoner. */
void getAndPrintMoreSums() {
	int sum = 0;
	int num = 0;
	int in = 0;
	cout << "Hvor mange tall vil du summere?";
	cin >> num;
	for (int i = 0; i < num; i++) {
		cout << endl << "Skriv inn et tall: ";
		cin >> in;
		sum += in;
	}
	cout << sum << endl;
}


// oppgave 2c

double getAndReturnDouble() {
	double a = -1;
	cout << "Skriv inn et ikke-ngativt desimaltall: ";
	cin >> a;
	return a;
}


// oppgave 2d og 2e

/* Siden getAndReturnInteger bare tar inn heltall, 
og vi har lyst på et svar i desimaltall, blir vi 
nødt til å gjøre konverteringer før vi kan bruke 
verdien til noe. Vi begrenser oss også til å ikke
kunne ta 9.50 kr som input til konverteringen */
double convert() {
	cout << "Konverterer fra NOK til Euro" << endl;
	double nok = -1;
	while (nok < 0) {
		nok = getAndReturnDouble();
	}
	double eur = round(nok/7.84);
	cout << nok << "kr er "<< eur << " Euro" << endl;
	return eur;
}



// oppgave 2g

void table() {
	int width;
	int height;
	cout << "Gangetabell:" << endl;
	cout << "Skriv inn høyde: ";
	cin >> height;
	cout << "Skriv inn bredde: ";
	cin >> width;
	cout << endl;
	int spaces = log10(width*height);
	for (int y = 1; y<= height; y++) {
		for (int x=1; x<= width; x++) {
			cout << x*y;
			for (int s=log10(x*y); s <= spaces; s++) {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}


// oppgave 3a
void time() {
	int secs = getAndReturnInteger();
	int hour = secs/(60*60);
	int min = (secs/60)%60;
	int sec = secs % 60;
	cout << endl << hour << " time(r)" << endl;
	cout << min << " minutt(er)" << endl;
	cout << sec << " sekund(er)" << endl << endl;
	
}


// oppgave 3b

void restaurant() {
	double amount = getAndReturnDouble();
	double mva = round(amount*0.0875);
	double tips = round((amount+mva)*0.18);
	cout << "MVA er: $" << mva << endl;
	cout << "Tips er: $" << tips << endl << endl;
}


// oppgave 4a

void oddOrEven() {
	int num = getAndReturnInteger();
	if (num % 2 == 0){
		cout << "Tallet er et partall" << endl << endl;
	}
	else {
		cout << "Tallet er et oddetall" << endl << endl;
	}
}


// oppgave 4b og 4c

/* Denne funksjonen <tar inn> to desimaltall, altså kommer
tallene som parametere til funksjonen fra et annet sted i programmet, 
og ikke direkte fra brukeren. */
int max(double a, double b) {
	if (a > b) return a;
	return b;
}

/* Denne funksjonen <lar brukeren skrive inn(om noe indirekte 
gjennom getAndReturnInteger)> tallene ved bruk av cin. De kommer
altså ikke fra et annet sted i koden. */
void highest() {
	double a = getAndReturnInteger();
	double b = getAndReturnInteger();
	double biggest = max(a,b);
	cout << biggest << " er størt" << endl;
}


// oppgave 5a

double internalSum(double a, double b, double c) {
	return b*b - 4*a*c;
}

// oppgave 5b

double positiveSqrt(double x) {
	if (x == 0) return 0;
	if (x > 0) return sqrt(x);
	return -1;
}

// oppgave 5c

double polyRoot(double a, double b, double c) {
	return positiveSqrt(internalSum(a, b, c));
}

// oppgave 5d

void abcFormula(double a, double b, double c) {
	if (internalSum(a,b,c) < 0) {
		cout << "Ingen løsninger." << endl;
	}
	else {
		double poly = polyRoot(a, b, c);
		if (poly == 0) {
			cout << "Svaret er " << -b / (2*a) << endl;
		}
		else {
			double answer1 = (-b + poly) / (2*a);
			double answer2 = (-b - poly) / (2*a);
			cout << "Svarene er " << answer1 << " og " << answer2 << endl;
		}
	}
}

// oppgave 5e

void solveAndPrintRoots() {
	int a,b,c;
	cout << "Skriv inn a: ";
	cin >> a;
	cout << "Skriv inn b: ";
	cin >> b;
	cout << "Skriv inn c: ";
	cin >> c;
	abcFormula(a,b,c);
	cout << endl;
}



// oppgave 6a og 6b

void calculateLoanPayments() {
	double toPay, amount, interest, left;
	cout << "Lånebeløp: ";
	cin >> amount;
	cout << "Rente: ";
	cin >> interest;
	left = amount;
	cout <<  "År\t" << "Innbetaling\t" << "Gjenstående lån" << endl;
	for (int y = 1; y<= 10; y++) {
		toPay = amount/10 + interest/100 * left;
		cout << y << "\t" << toPay << "\t\t" << left << endl;
		left -= amount/10;
	}
	cout << endl;
}







// oppgave 2f
int main() {
	int cmd;
	while(true) {
		cout << "Velg en Funksjon:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) Summer to tall" << endl;
		cout << "2) Summer flere tall" << endl;
		cout << "3) Konverter NOK til EURO" << endl;
		cout << "4) Gangetabell" << endl;
		cout << "5) Tid" << endl;
		cout << "6) Restaurant" << endl;
		cout << "7) Odd eller partall" << endl;
		cout << "8) Høyeste tall" << endl;
		cout << "9) Andregradsfunksjon" << endl;
		cout << "10) Lån" << endl;
		cout << "Angi valg (0-10):";
		cin >> cmd;

		switch(cmd) {
			case 0:
				return 0;
			case 1:
				getAndPrintSum();
				break;
			case 2:
				getAndPrintMoreSums();
				break;
			case 3:
				convert();
				break;
			case 4:
				table();
				break;
			case 5:
				time();
				break;
			case 6:
				restaurant();
				break;
			case 7:
				oddOrEven();
				break;
			case 8:
				highest();
				break;
			case 9:
				solveAndPrintRoots();
				break;
			case 10:
				calculateLoanPayments();
				break;
		}
	}
	return 0;
}