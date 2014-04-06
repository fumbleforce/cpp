#pragma once
#include <iostream>
#include <set>
#include <string>
#include <vector>


class Sudoku
{
public:
    Sudoku();

    void importFile(std::string path);

    bool validInsert(int row, int col, int val) const;
    bool onlyValidNumber(int row, int col, int val) const;
    bool findSolvable(int &row, int &col, int &val);
    void solveOne();
    void solveSelf(int delay, bool print);
    void solveAssisted(int delay, bool print);
    void solveBrute(int delay, bool print);
    void solveRandom(int delay, bool print);
    void solveRandBrute(int delay, bool print);
    void trySolve();
    bool isSolved();
    void makeRandomMove();
    void bruteForceMove();
    void randBruteForceMove();
    void regretMoves();
    void printLog();
    void printBoard(int row, int col, int val, std::string source);
    void logInsert(int row, int col, int val, int random);


    void setRaw(int i, int val) { board[i] = val; }
    int getRaw(int i) const { return board[i]; }
    bool setCell(int row, int col, int val);
    void setCellNoval(int row, int col, int val) { board[9 * row + col] = val; }
    int getCell(int row, int col) const { return board[9 * row + col]; }

    int getBox(int row, int col) const { return (int)(row/3)*3 + (int)(col/3); }

    int getCoordRow(int pos) const { return (int)(pos / 9); }
    int getCoordCol(int pos) const { return (int)(pos % 9); }

    bool inRow(int row, int val) const { return rowSet[row].find(val) != rowSet[row].end(); }
    bool inCol(int col, int val) const { return colSet[col].find(val) != colSet[col].end(); }
    bool inBox(int box, int val) const { return boxSet[box].find(val) != boxSet[box].end(); }

    friend std::ostream& operator<<(std::ostream& os, const Sudoku &su);
private:
    int board[81];
    int delay;
    bool print;

    std::set<int> rowSet[9];
    std::set<int> colSet[9];
    std::set<int> boxSet[9];

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;

    std::vector< std::vector<int> > log;
};