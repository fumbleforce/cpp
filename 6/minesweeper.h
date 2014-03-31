#pragma once
#include "matrix.h"





class Minesweeper
{
private:
	int width;
	int height;
	int mines;
	int open;

	Matrix board;
	Matrix mask;

public:
	Minesweeper();
	void getInput();
	void makeBoard();
	void placeMines();
	void setFlag(int x, int y);
	bool openSquare(int x, int y);
	void printBoard(bool showMines);
	void play();
};