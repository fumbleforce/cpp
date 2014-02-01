#pragma once

int randomWithLimits(int lower, int upper);

char randomCharWithLimits(int lower, int upper);

void incrementByValueNumTimes(int *startValue, int increment, int numTimes);

void swapNumbers(int *a, int *b);

void printArray(int l[], int length);

void printCharArray(char l[], int length);

void randomizeArray(int *l, int length);

void sortArray(int *l, int length);

int medianOfArray(int l[], int length);

void randomizeCString(char s[], int num, char min, char max);

void readInputToCString(char s[], int num,  char min, char max);

int countOccurencesOfCharacter(char s[], int length, char character);

double averageGrade(int l[], int numGrades);