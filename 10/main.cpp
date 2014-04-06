#include "fancySafeArray.h"
#include "safeArray.h"
#include "sudoku.cpp"
#include "sudoku.h"
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int main()
{
    srand(time(0));
    Sudoku sud = Sudoku();

    int boardNr;
    cout << "Choose board: (1 - 2): ";
    cin >> boardNr;

    switch(boardNr)
    {
        case 1:
            sud.importFile("sudoku1.txt");
        case 2:
            sud.importFile("sudoku2.txt");
    }

    int mode;
    cout << "Choose mode (0 = user, 1 = assisted, 2 = dumb brute, " << endl;
    cout << "3 = random, 4 = random brute):";
    cin >> mode;

    int delay;
    cout << "Time delay: ";
    cin >> delay;

    int printIn;
    cout << "Print boards as solving progresses? (1 = true, 0 = false)";
    cin >> printIn;

    bool print = true;
    if (printIn == 0)
    {
        cout << "Not printing" << endl;
        print = false;
    }
        

    switch(mode)
    {
        case 0:
            sud.solveSelf(delay, print);
        case 1:
            sud.solveAssisted(delay, print);
        case 2:
            sud.solveBrute(delay, print);
        case 3:
            sud.solveRandom(delay, print);
        case 4:
            sud.solveRandBrute(delay, print);
    }

/*
    SafeArray<int> sArr = SafeArray<int>(10);

    int i;

    cout << "Expect n*n array of 10 elements" << endl;
    for (i = 0; i < sArr.size(); i++)
    {
        sArr[i] = i * i;
        cout << sArr[i] << " ";
    }
    cout << endl << endl;

    SafeArray<int> copyArr = sArr;
    copyArr.resize(5);

    for (int i = 0; i < copyArr.size(); i++)
    {
        copyArr[i] = copyArr[i] + 5;
    }

    copyArr.resize(10);

    cout << "Expect n*n+5 array of 5 elements, current size: " << copyArr.size() << endl;
    for (i = 0; i < copyArr.size(); i++)
        cout << i << ": " << copyArr[i] << "  ";
    cout << endl << endl;
    
    cout << "Expect the first array unaltered" << endl;
    for (i = 0; i < sArr.size(); i++)
        cout << sArr[i] << " ";
    cout << endl;

    try
    {
        cout << "Throwing exception.." << endl;
        cout << sArr[1111] << endl;
    }
    catch (std::out_of_range& e)
    {
        cout << "Got Exception" << endl;
        cout << e.what() << endl;
    }
*/
    return 0;
}