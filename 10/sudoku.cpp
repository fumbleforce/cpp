#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>
#include "sudoku.h"
#include <unistd.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
using namespace std;


Sudoku::Sudoku()
{
    int i, j;

    for (i = 0; i < 81; i++)
        board[i] = 0;

    for (i = 0; i < 9; i++)
    {
        for (j = 1; j < 10; j++)
        {
            rowSet[i].insert(j);
            colSet[i].insert(j);
            boxSet[i].insert(j);
        }
    }

    v1 = {1, 2, 3, 4, 5, 6, 7, 8};
    v2 = {1, 2, 3, 4, 5, 6, 7, 8};
    v3 = {1, 2, 3, 4, 5, 6, 7, 8};
}

void Sudoku::importFile(string path)
{
    ifstream sudokuFile (path.c_str());
    string line;
    int c = 0;
    int r = 0;
    int num;

    if (sudokuFile.is_open())
    {
        while( getline(sudokuFile, line) )
        {
            c = 0;
            
            for (string::size_type i = 0; i < line.size(); ++i)
            {
                if (line[i] != ' ')
                {
                    num = line[i] - '0';
                    setCell(r, c, num);
                    c++;
                }
            }
            r++;
        }
        sudokuFile.close();
    }
}

bool Sudoku::validInsert(int row, int col, int val) const
{
    bool inAllSets = inRow(row, val) && inCol(col, val) && inBox(getBox(row, col), val);
    bool empty = getCell(row, col) == 0;
    return inAllSets && empty;
}

bool Sudoku::onlyValidNumber(int row, int col, int val) const
{
    if (!validInsert(row, col, val)) return false;

    for (int i = 1; i < 10; i++)
    {
        if (i != val)
        {
            if (validInsert(row, col, i))
                return false;
        }
    }
    return true;
}

bool Sudoku::findSolvable(int &row, int &col, int &val)
{
    bool ovn;

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            for (int v = 1; v < 10; v++)
            {   
                ovn = onlyValidNumber(r, c, v);
                if (ovn)
                {
                    row = r;
                    col = c;
                    val = v;
                    logInsert(row, col, val, 0);
                    return true;
                }
            }
        }
    }
    return false;
}

void Sudoku::makeRandomMove()
{
    bool inserted = false;
    int val, row, col, tries;


    while(!inserted && tries < 1000)
    {
        val = rand() % 9 + 1;
        row = rand() % 9;
        col = rand() % 9;
        //cout << "Random: "<< row << " " << col << " " << val << endl;
        inserted = setCell(row, col, val);
        tries++;
    }

    if (inserted)
    {
        printBoard(row, col, val, "Random");
        logInsert(row, col, val, 1);
    }
    else
    {
        regretMoves();
    }
}

void Sudoku::logInsert(int row, int col, int val, int random)
{
    vector<int> logEntry = vector<int>();
    logEntry.push_back(row);
    logEntry.push_back(col);
    logEntry.push_back(val);
    logEntry.push_back(random);
    log.push_back(logEntry);
}

void Sudoku::printBoard(int row, int col, int val, string source)
{
    if (this->print)
    {
        cout << source <<" Row: " << row << " Col: " << col << " Val: " << val << endl;
        cout << *this << endl;
        usleep(delay);
    }
    else
        cout << "Not printing";
    
}

void Sudoku::printLog()
{
    vector< vector<int> >::iterator i;
    for (i = log.begin(); i != log.end(); i++)
        cout << " [" << (*i)[0] << "|" << (*i)[1] << "|" << (*i)[2] << "|" << (*i)[3] << "] ";
    cout << endl;
}

void Sudoku::bruteForceMove()
{
    bool inserted = false;
    int val, row, col;

    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (getCell(row, col) == 0)
            {
                for (val = 1; val < 10; val++)
                {
                    inserted = setCell(row, col, val);
                    if (inserted)
                    {
                        printBoard(row, col, val, "Brute");
                        logInsert(row, col, val, 1);
                        printLog();
                        return;
                    }
                }
            }
        }
    }
    regretMoves();
}

void Sudoku::randBruteForceMove()
{
    bool inserted = false;
    int val, row, col;
    int v, r, c;

    
    random_device rd;
    mt19937 g(rd());
    shuffle(v1.begin(), v1.end(), g);
    shuffle(v2.begin(), v2.end(), g);
    shuffle(v3.begin(), v3.end(), g);

    for (r = 0; r < 9; r++)
    {
        row = v1[r];

        for (c = 0; c < 9; c++)
        {
            col = v2[c];

            if (getCell(row, col) == 0)
            {
                for (v = 1; v < 10; v++)
                {
                    val = v3[v];

                    inserted = setCell(row, col, val);
                    if (inserted)
                    {
                        printBoard(row, col, val, "BruteRandom");
                        logInsert(row, col, val, 1);
                        return;
                    }
                }
            }
        }
    }
    regretMoves();
}

void Sudoku::regretMoves()
{
    int foundBrutes = 0;
    int targetBrutes = 10;
    int r, c, v, b;

    while(true)
    {
        if (log.size() == 0)
        {
            return;
        }
        r = log.back()[0];
        c = log.back()[1];
        v = log.back()[2];
        b = log.back()[3];

        if (b == 1)
            foundBrutes++;
 
        setCellNoval(r, c, 0);
        rowSet[r].insert(v);
        colSet[c].insert(v);
        boxSet[getBox(r, c)].insert(v);

        log.pop_back();

        printBoard(r, c, v, "Regret");
    }
}

void Sudoku::solveOne()
{
    int row, col, val;

    bool solved = findSolvable(row, col, val);
    if (solved)
    {
        cout << "Inserted into " << row << " : " << col << endl;
    }
    else
        cout << "Found no solvable cells" << endl;
}

void Sudoku::trySolve()
{
    int row, col, val;

    cout << "Trying to find auto-solvable.." << endl;
    while (findSolvable(row, col, val))
    {
        setCell(row, col, val);
        printBoard(row, col, val, "Solvable");
    }
    cout << "No more auto-solvable" << endl;
}

bool Sudoku::isSolved()
{
    for (int i = 0; i < 81; i++)
    {
        if (board[i] == 0)
            return false;
    }
    return true;
}


void Sudoku::solveAssisted(int delay, bool print)
{
    cout << "Solving assisted" << endl;
    this->print = true;
    this->delay = delay;
    printBoard(0,0,0, "Begin");
    int i = 0;
    
    this->print = print;

    trySolve();

    while (!isSolved())
    {
        cout << "HELP! I am stuck :(" << endl;
        bool inserted = false;
        int inputRow;
        int inputCol;
        int inputVal;

        while (!inserted)
        {
            cout << "row: ";
            cin >> inputRow;
            cout << "col: ";
            cin >> inputCol;
            cout << "val: ";
            cin >> inputVal;
            cout << endl;
            inserted = setCell(inputRow, inputCol, inputVal);

            if (!inserted)
                cout << "Invalid insert" << endl;
            else
                cout << *this;
        }
        trySolve();
    }
    this->print = true;
    printBoard(0,0,0, "Solved");
    cout << "Solved" << endl;
}

void Sudoku::solveSelf(int delay, bool print)
{
    cout << "Solving self" << endl;
    this->print = true;
    this->delay = delay;
    printBoard(0,0,0, "Begin");
    int i = 0;
    this->print = print;

    while (!isSolved())
    {
        bool inserted = false;
        int inputRow;
        int inputCol;
        int inputVal;

        while (!inserted)
        {
            cout << "row: ";
            cin >> inputRow;
            cout << "col: ";
            cin >> inputCol;
            cout << "val: ";
            cin >> inputVal;
            cout << endl;
            inserted = setCell(inputRow, inputCol, inputVal);

            if (!inserted)
                cout << "Invalid insert" << endl;
            else
                cout << *this;
        }
    }
    this->print = true;
    printBoard(0,0,0, "Solved");
    cout << "Solved" << endl;
}

void Sudoku::solveBrute(int delay, bool print)
{
    cout << "Solving brute" << endl;
    this->print = true;
    this->delay = delay;
    printBoard(0,0,0, "Begin");
    int i = 0;
    this->print = print;

    trySolve();

    while (!isSolved())
    {
        bruteForceMove();
        trySolve();
    }
    this->print = true;
    printBoard(0,0,0, "Solved");
    cout << "Solved" << endl;
}

void Sudoku::solveRandom(int delay, bool print)
{
    cout << "Solving random" << endl;
    this->print = true;
    this->delay = delay;
    printBoard(0,0,0, "Begin");
    int i = 0;
    this->print = print;

    trySolve();

    while (!isSolved())
    {
        makeRandomMove();
        trySolve();
    }
    this->print = true;
    printBoard(0,0,0, "Solved");
    cout << "Solved" << endl;
}
void Sudoku::solveRandBrute(int delay, bool print)
{
    cout << "Solving random brute" << endl;
    this->print = true;
    this->delay = delay;
    printBoard(0,0,0, "Begin");
    int i = 0;
    this->print = print;

    trySolve();

    while (!isSolved())
    {
        randBruteForceMove();
        trySolve();
    }
    this->print = true;
    printBoard(0,0,0, "Solved");
    cout << "Solved" << endl;
}

bool Sudoku::setCell(int row, int col, int val)
{
    if (!validInsert(row, col, val))
        return false;

    board[9 * row + col] = val;
    rowSet[row].erase(val);
    colSet[col].erase(val);
    boxSet[getBox(row, col)].erase(val);
    return true;
}

ostream& operator<<(ostream& os, const Sudoku& su)
{
    for (int i = 0; i < 25; i++)
                os << "-";
            os << "\n";

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (c % 3 == 0)
                os << "| ";

            if (su.getCell(r, c) < 1)
                os << " " << " ";
            else
                os << su.getCell(r, c) << " ";
        }
        os << "|\n";

        if ((r+1) % 3 == 0) 
        {
            for (int i = 0; i < 25; i++)
                os << "-";
            os << "\n";
        }
    }
    os << endl;
    /* Print set status
    set<int>::iterator x;

    os << "Row sets:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (x = su.rowSet[i].begin(); x != su.rowSet[i].end(); x++)
            os << *x << " ";
        os << endl;
    }

    os << "Col sets:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (x = su.colSet[i].begin(); x != su.colSet[i].end(); x++)
            os << *x << " ";
        os << endl;
    }

    os << "Box sets:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (x = su.boxSet[i].begin(); x != su.boxSet[i].end(); x++)
            os << *x << " ";
        os << endl;
    }
    */

    return os;
}