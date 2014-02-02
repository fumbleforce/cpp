#include "matrix.h"
#include "matrix.cpp"
#include "vector.h"
#include "vector.cpp"


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

	cout << A << endl;

	return 0;
}