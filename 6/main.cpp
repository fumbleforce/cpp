#include "matrix.cpp"
#include <iostream>
using namespace std;


int main()
{
	int i;

	Matrix m = Matrix(5);
	cout << "Expect identity 5x5" << endl;
	cout << m << endl;
	Matrix invalid = Matrix();
	cout << "Expect invalid" << endl;
	cout << invalid << endl;
	Matrix allZero = Matrix(3,4);
	cout << "Expect value 0 3x4" << endl;
	cout << allZero << endl;
	Matrix three = Matrix(3,4, 3.3);
	cout << "Expect value 3.3 3x4" << endl;
	cout << three << endl;
	Matrix six = three + three;
	cout << "Expect value 6.6 3x4" << endl;
	cout << six << endl;
	cout << "Expect value 3.3 3x4" << endl;
	six = three;
	cout << six << endl;
	Matrix twoInv = Matrix(4,3, 2.2);
	cout << "Expect value ? 3x4" << endl;
	cout << three * twoInv << endl;

	Matrix first = Matrix(2,3);
	Matrix second = Matrix(3, 2);
	for (i = 0; i < 6; i++)
	{
		first.set(i, i+1);
		second.set(i, i+7);
	}
	cout << "first:" << endl << first << endl;
	cout << "second:" << endl << second << endl;
	cout << "Expect value sum 2x3" << endl;

	cout << first * second << endl;

	Matrix a = Matrix(2, 2);
	Matrix b = Matrix(2,2);
	Matrix c = Matrix(2,2);
	for (i = 0; i < 4; i++)
	{
		a.set(i, i+1);
		b.set(i, 4-i);
	}
	c.set(0, 1.0);
	c.set(1, 3.0);
	c.set(2, 1.5);
	c.set(3, 2.0);

	Matrix d = a + b;
	d = d * b - a + c;
	cout << d << endl;


	cout << "end" << endl;
	return 0;
}