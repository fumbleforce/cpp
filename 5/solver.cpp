#include <iostream>
#include <string>
#include "solver.h"
#include "vector.h"
#include "matrix.h"
using namespace std;


void solve()
{
	cout << endl << endl << "Du kan nå løse en likning på formen:" << endl
		<< "ax + by = p" << endl
		<< "cx + dy = q" << endl
		<< "Skriv inn variablene:" << endl;

	double a, b, c, d, p, q;

	cout << "a:" << endl;
	cin >> a;

	cout << "b:" << endl;
	cin >> b;

	cout << "c:" << endl;
	cin >> c;

	cout << "d:" << endl;
	cin >> d;

	cout << "p:" << endl;
	cin >> p;

	cout << "q:" << endl;
	cin >> q;

	Vector2 v = Vector2(p, q);
	Vector2 result;

	Matrix2x2 m = Matrix2x2(a, b, c, d);

	if (m.det() == 0) {
		cout << "Determinanten er 0, så ingen løsning finnes" << endl;
		return;
	}

	m = m.inverse();

	result = v * m;

	cout << "Resultatet er: x = " << result.getX() << ", y = " << result.getY() << endl;
	
}