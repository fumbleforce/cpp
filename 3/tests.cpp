#include <iostream>
using namespace std;




void testPart2() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimes(&v0, increment, iterations);
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations << endl << endl;

	int a = 1;
	int b = 20;
	cout << "a was "<< a <<", b was "<< b << endl;
	swapNumbers(&a, &b);
	cout << "a is now "<< a
		<< " and b is now " << b << endl;
}


void testPart3() {
	int percentages[20];
	cout << "Randomized array" << endl;
	randomizeArray(percentages, 20);
	printArray(percentages, 20);

	int median = medianOfArray(percentages, 20);
	cout << "Median: " << median << endl;
	
	swapNumbers(&percentages[0], &percentages[1]);
	cout << endl;
	cout << "Swapped first elements" << endl;
	printArray(percentages, 20);

	
	sortArray(percentages, 20);
	cout << endl;
	cout << "Sorted array" << endl;
	printArray(percentages, 20);

	median = medianOfArray(percentages, 20);
	cout << "Median: " << median << endl;
}

void testPart4() {
	char grades[9];

	randomizeCString(grades, 9, 'A', 'F');

	cout << "Some random grades:" << endl;
	cout << grades << endl << endl;

	int gradeCount[6];
	for (int i = 0; i < 6; i++) {
		gradeCount[i] = countOccurencesOfCharacter(grades, 8, i+65);
	}
	cout << "Karakterer:" << endl;
	printArray(gradeCount, 6);
	cout << "Gjennomsnitt:" << endl;
	cout << averageGrade(gradeCount, 8) << endl << endl;

	char gradesFiveYears[41];
	randomizeCString(gradesFiveYears, 41, 'A', 'F');
	cout << "Karakterer for 5 år:" << endl;
	cout << gradesFiveYears << endl << endl;
	int gradeCountFive[6];
	for (int i = 0; i < 6; i++) {
		gradeCountFive[i] = countOccurencesOfCharacter(gradesFiveYears, 40, i+65);
	}
	printArray(gradeCountFive, 6);
	cout << "Gjennomsnitt:" << endl;
	cout << averageGrade(gradeCountFive, 40) << endl << endl;


	char gradesInput[9];
	readInputToCString(gradesInput, 8, 'A', 'F');
	int gradeCountInput[6];
	for (int i = 0; i < 6; i++) {
		gradeCountInput[i] = countOccurencesOfCharacter(gradesInput, 8, i+65);
	}
	printArray(gradeCountInput, 6);
	cout << "Gjennomsnitt:" << endl;
	cout << averageGrade(gradeCountInput, 8) << endl << endl;
	
}