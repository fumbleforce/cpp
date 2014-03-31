#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include "minesweeper.h"
using namespace std;





Minesweeper::Minesweeper()
{
	this-> open = 0;
}

void Minesweeper::getInput()
{	
	cout 	<< "||||||||||||||||||||||||||||||||" << endl
			<< "|||| WELCOME TO MINESWEEPER ||||" << endl
			<< "||||||||||||||||||||||||||||||||" << endl
			<< endl;

	int h = 0;
	int w = 0;
	int m = 0;

	do
	{
		cout << "Please enter height ( > 2 )" << endl;
		cin >> h;
	}
	while (h < 2);
	
	do
	{
		cout << "Please enter width ( > 2 )" << endl;
		cin >> w;
	}
	while (w < 2);

	do
	{
		cout << "Please enter number of mines ( > 1 )" << endl;
		cin >> m;
	}
	while (m < 1);

	this->height = h;
	this->width = w;
	this->mines = m;
}

void Minesweeper::makeBoard()
{	
	cout 	<< " ___________________________" << endl
			<< "|                           |" << endl
			<< "|       CREATING BOARD      |" << endl
			<< "|___________________________|" << endl;

	this->board = Matrix(this->height, this->width, 0);
	this->mask = Matrix(this->height, this->width, 0);
}

void Minesweeper::placeMines()
{	
	cout 	<< " ___________________________" << endl
			<< "|                           |" << endl
			<< "|       PLACING MINES       |" << endl
			<< "|___________________________|" << endl << endl;

	int posx = 0;
	int posy = 0;

	for (int m = 0; m < this->mines; m++)
	{
		posx = rand() % this->width;
		posy = rand() % this->height;

		this->board.set(posy, posx, -1);

		for (int y = posy - 1; y < posy + 2; y++)
		{
			for (int x = posx - 1; x < posx + 2; x++)
			{
				if (x > -1 && x < this->width &&
					y > -1 && y < this->height)
				{
					if (!(x == posx && y == posy) && 
						this->board.get(y, x) != -1)
					{
						this->board.set(y, x, this->board.get(y, x) + 1);
					}
				}
			}
		}
	}
}

void Minesweeper::printBoard(bool showMines)
{
	int r, c, m, offset;

	int maxOffset = (int)log10(this->width);
	cout << string(maxOffset*2+4, ' ');
	for (int i = 0; i < this->width; i++)
	{
		offset = log10(i);
		cout << i << "  ";
		if (maxOffset - offset > 0)
			cout << string(maxOffset - offset, ' ');
		else if (i == 0)
			cout << " ";
	}

	cout << endl << "   ";

	for (int i = 0; i < this->width; i++)
		cout << string(maxOffset*4, '_');

	cout << endl;
	for (r = 0; r < this->height; r++)
	{	
		offset = log10(r);
		cout << r;
		if (maxOffset - offset > 0)
			cout << string(maxOffset - offset, ' ');
		else if (r == 0)
			cout << " ";

		cout << "|";
		for (c = 0; c < this->width; c++)
		{
			cout << "  ";
			cout << string(maxOffset, ' ');

			m = mask.get(r, c);
			if (showMines)
			{
				if (board.get(r, c) == -1) cout << "x";
				else cout << board.get(r, c);
			}
			else
			{
				if (m == 0) cout << "\xB2";
				else if (m == 1)
				{
					if (board.get(r, c) == -1) cout << "x";
					else cout << board.get(r, c);
				}
				else if (m == 2) cout << "#";
			}
			
		}
		cout << " |" << endl;
	}
	cout << "   ";
	for (int i = 0; i < this->width; i++)
		cout << string(maxOffset*4, '_');
	cout << endl;	
}

void Minesweeper::setFlag(int x, int y)
{
	if (x >= 0 &&
		x < this->width &&
		y >= 0 &&
		y < this->height)
	{
		if (mask.get(y, x) == 0)
		{
			mask.set(y, x, 2);
		}
		else if (mask.get(y, x) == 2)
		{
			mask.set(y, x, 0);
		}
	}
}

bool Minesweeper::openSquare(int x, int y)
{
	if (x >= 0 &&
		x < width &&
		y >= 0 &&
		y < height)
	{
		if (mask.get(y, x) == 0 || mask.get(y, x) == 2)
		{
			mask.set(y, x, 1);
			open++;

			if (board.get(y, x) == -1) 
				return true;
			else if (board.get(y, x) == 0)
			{
				for (int y2 = y - 1; y2 < y + 2; y2++)
					for (int x2 = x - 1; x2 < x + 2; x2++)
						openSquare(x2, y2);
			}
		}
	}
	return false;
}

void Minesweeper::play()
{

	getInput();
	makeBoard();
	placeMines();
	printBoard(false);

	bool lost = false;
	int input, x, y;

	while (true)
	{
		cout << "1: Open, 2: Flag, ";
		cin >> input;
		if (input == 1)
		{
			cout << "Open, enter x: ";
			cin >> x;
			cout << " enter y: ";
			cin >> y;
			lost = openSquare(x, y);
			if (lost) break;
			
		}
		else if (input == 2)
		{
			cout << "Flag, enter x: ";
			cin >> x;
			cout << " enter y: ";
			cin >> y;
			setFlag(x, y);
		}

		printBoard(false);

		if (open >= width * height - mines ) break;
	}

	printBoard(true);

	if (lost) cout << "You lost :(" << endl;
	else cout << "You won! :D" << endl;

	

	
}