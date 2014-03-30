#include "templates.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void swapEl(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

template<typename T>
void shuffle(T arr, int length)
{
    for (int i = 0; i < length; i ++)
    {
        int random = rand() % length;
        swapEl(arr[i], arr[random]);
    }
}

template<typename T>
T maximum(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

void printVector(vector<string> strings)
{
    vector<string>::iterator stringIter;
    for (stringIter = strings.begin();
        stringIter != strings.end();
        stringIter++)
    {
        cout << *stringIter << " ";
    }
    cout << endl;
}

void printVectorRev(vector<string> strings)
{
    vector<string>::reverse_iterator rstringIter;
    for (rstringIter = strings.rbegin();
        rstringIter != strings.rend();
        rstringIter++)
    {
        cout << *rstringIter << " ";
    }
    cout << endl;
}


void replaceString(vector<string> &strings, string old, string rep)
{
    vector<string>::iterator i;
    for (i = strings.begin(); i != strings.end(); i++)
    {
        if (*i == old)
        {
            strings.erase(i);
            strings.insert(i, rep);
        }
    }
}







