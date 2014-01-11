#include <iostream>
using namespace std;



// Oppgave 2a

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:" << endl;
	cout << 0 << ": " << b << endl;
	for (int x = 1; x<n; x++) {
		int temp = b;
		b += a;
		a = temp;
		cout << x << ": " << b << endl;
	}
	cout << endl;
	return b;
}


// Oppgave 2b

void triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	while (acc+num < n) {
		acc += num;
		num++;
		cout << acc << endl;
	}
	cout << endl;
}

bool isTriangleNumber(int number) {
	int acc = 1;
	cout << "Is " << number << " a triangle number? ";
	while (number > 0) {
		number -= acc;
		acc++;
	}
	if (number == 0) {
		cout << "yes" << endl;
		return true;
	}
	cout << "no" << endl;
	return false;
}


// oppgave 2c

int squareNumberSum(int n) {
	int totalSum = 0;
	cout << "Square numbers:" << endl;
	for (int i = 0; i < n; i++) {
		totalSum += i*i;
		i++;
		cout << i*i << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}


// oppgave 2d

int max(int a, int b) {
	if (a > b) {
		cout << a << " is greater than " << b << endl;
		return a;
	}
	cout << b << " is greater than or equal "<< a << endl;
	return b;
}


// oppgave 2e

int isPrime(int n) {
	cout << "Is " << n << " prime? ";
	for (int j = 2; j < n; j++) {
		if (n % j == 0) {
			cout << "no." << endl;
			return false;
		}
	}
	cout << "yes!" << endl;
	return true;
}

// oppgave 2f

void naivePrimeNumberSearch(int n) {
	for (int num = 2; num < n; num++) {
		isPrime(num);
	}
}

// oppgave 2g

int findGreatestDivisor(int n) {
	cout << "The greatest divisor for " << n << " is: ";
	for (int d = n-1; d > 0; d--) {
		if (n % d == 0) {
			cout << d << endl;
			return d;
		}
	}
}

// oppgave 2h

void compareListOfNumbers(int l[], int length) {
	cout << "Array: [";
	for (int j=0; j<length; j++) cout << l[j] << ", "; 
	cout << "]" << endl;

	int r[3];
	for (int j=0; j<3; j++) r[j] = 0;

	for (int i = 0; i < length; i++) {
		if (l[i] < 0) r[0]++;
		else if (l[i] == 0) r[1]++;
		else r[2]++;
	}
	cout << r[0] << " numbers were below zero" << endl;
	cout << r[1] << " numbers were zero" << endl;
	cout << r[2] << " numbers were greater than zero" << endl;
}





int main() {
	fibonacci(10);

	triangleNumbersBelow(20);

	isTriangleNumber(19);
	isTriangleNumber(10);

	cout << endl;

	max(1, 5);
	max(2, 2);
	max(1000, 2000);

	cout << endl;

	naivePrimeNumberSearch(10);

	cout << endl;

	findGreatestDivisor(10);
	findGreatestDivisor(50);
	findGreatestDivisor(87);

	cout << endl;

	int l[5] = {1, 2, 0, 0, -1};
	compareListOfNumbers(l, 5);

	return 0;
}