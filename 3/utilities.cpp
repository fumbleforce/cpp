#include <iostream>
#include <cstdlib>
#include "utilities.h"
using namespace std;




int randomWithLimits(int lower, int upper) {
	return (rand() % (upper-lower +1)) + lower;
}

char randomCharWithLimits(char lower, char upper) {
	return randomWithLimits(static_cast<int>(lower), static_cast<int>(upper));
}

void incrementByValueNumTimes(int *startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}

void swapNumbers(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int l[], int length) {
	cout << "[";
	for (int j=0; j < length; j++) {
		cout << l[j];
		if (j < length-1) cout << ", ";
	}
	cout << "]" << endl;
}

void printCharArray(char l[], int length) {
	cout << "Array: [";
	for (int j=0; j < length; j++) {
		if (l[j] == 0) break;
		cout << l[j] << ", "; 
	}
	cout << "]" << endl;
}

void randomizeArray(int *l, int length) {
	for (int i=0; i<length; i++) {
		l[i] = randomWithLimits(1, 100);
	}
}

void sortArray(int *l, int length) {
	for (int i=0; i<length; i++) {
		int j = i;
		while (l[j] < l[j-1] && j-1 >= 0) {
			swapNumbers(&l[j], &l[j-1]);
			j -= 1;
		}
	}
}

int medianOfArray(int l[], int length) {
	int newlist[length];
	for (int i=0; i<length; i++) newlist[i] = l[i];
		
	sortArray(newlist, length);
	if (length % 2 == 0) {
		return (newlist[(length)/2] + newlist[(length-1)/2]) / 2;
	}
	return newlist[(length-1)/2];
}

void randomizeCString(char s[], int num, char min, char max) {

	for (int i = 0; i < num; i++) {
		s[i] = randomCharWithLimits(min, max);
	}
	s[num-1] = 0;
}

void readInputToCString(char s[], int numInput, char min, char max) {

	cout << "Skriv inn " << numInput << " bokstaver mellom " << min << " og " << max << endl;
	for (int i = 0; i < numInput; i++) {
		cin >> s[i];
		s[i] = toupper(s[i]);
	}
}

int countOccurencesOfCharacter(char s[], int length, char character) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (s[i] == character) count++;
	}
	return count;
}

double averageGrade(int l[], int numGrades) {
	int total = 0;
	for (int i = 0; i < 6; i++) {
		total += l[i] * (i+1);
	}
	double average = (double)total / (double)numGrades;
	return average;
}