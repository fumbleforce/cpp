#include "vector.h"
#include "matrix.h"
#include "solver.h"
#include "matrix.cpp"
#include "vector.cpp"
#include "solver.cpp"
#include <iostream>
using namespace std;


int main()
{
	Matrix2x2 A = Matrix2x2(1, 2, 3, 4);
	Matrix2x2 B = Matrix2x2(4, 3, 2, 1);
	Matrix2x2 C = Matrix2x2(1.0, 3.0, 1.5, 2.0);

	A += B;
	A -= B;

	cout << A << endl;
	cout << B << endl;

	cout << A+B << endl;

	cout << A << endl;
	cout << B << endl;

	cout << A * B << endl;

	Matrix2x2 D = A + B;
	D = D * B - A + C;

	cout << D << endl;

	A *= B;

	cout << "A: " << endl << A << endl;

	Vector2 v = Vector2(2,2);

	cout << "v: " << endl << v << endl;

	Vector2 prod = v * A;

	cout << "product: " << endl << prod << endl;

	solve();

	return 0;
}