#include "fancySafeArray.h"
#include "safeArray.h"
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int main()
{

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

    return 0;
}