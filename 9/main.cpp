#include "templates.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    srand(time(0));
    int i;

    /* 1a */

    int a[] = {1, 2, 3, 4, 5, 6, 7};
    shuffle(a, 7); // Resultat, rekkefolgen i a er endret.

    for (i = 0; i < 7; i++) cout << a[i] << " ";
    cout << endl;

    double b[] = {1.2, 2.2, 3.2, 4.2};
    shuffle(b, 4);

    string c[] = {"one", "two", "three", "four"};
    shuffle(c, 4);

    for (int i = 0; i < 4; i++) cout << c[i] << " ";
    cout << endl;

    /* 1b */

    cout << maximum(1, 80) << endl;

    cout << maximum(8.8, 6.3) << endl;

    cout << maximum("no", "yes") << endl;


    /* 1c
    
    Maximum krever at > operatoren er definert på 
    objekter som Person og Circle for å virke.

    */

    /* 2a og 3a */

    SimpleSet<int> s = SimpleSet<int>();

    s.insert(1);
    s.insert(2);
    s.insert(3);

    bool hastwo = s.exists(2);
    cout << "Set has 2: " << hastwo << endl;
    bool hasTwenty = s.exists(20);
    cout << "Set has 20: " << hasTwenty << endl;

    SimpleSet<string> x = SimpleSet<string>();

    x.insert("one");
    x.insert("two");
    x.insert("three");
    x.insert("three");

    bool hastwo2 = x.exists("two");
    cout << "Set has 'two': " << hastwo2 << endl;
    bool hasTwenty2 = x.exists("twenty");
    cout << "Set has 'twenty': " << hasTwenty2 << endl;

    /* 3b 
    
        Kan være at ikke alle klasser har 
        operatoren == som brukes i find.

    */

    /* 4a */

    vector<string> strings;
    strings.push_back("Lorem");
    strings.push_back("Ipsum");
    strings.push_back("Dolor");
    strings.push_back("Sit");
    strings.push_back("Amet");
    strings.push_back("Consecteur");

    printVector(strings);

    /* 4b */

    printVectorRev(strings);

    /* 4b */

    strings.push_back("Lorem");
    replaceString(strings, "Lorem", "Latin");
    printVector(strings);

    return 0;
}