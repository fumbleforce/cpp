#include <iostream>
#include <string>
#include "matrix.h"
#include "vector.cpp"
using namespace std;

void Matrix2x2::print()
{
	cout << endl;
	cout << "| " << get(0,0) << " " << get(0,1) << " |" << endl;
	cout << "| " << get(1,0) << " " << get(1,1) << " |" << endl;
	cout << endl;
}

Matrix2x2::Matrix2x2()
{
	set(0,0,1);
	set(0,1,0);
	set(1,0,0);
	set(1,1,1);
}

Matrix2x2::Matrix2x2(int first, int second, int third, int fourth)
{
	set(0,0,first);
	set(0,1,second);
	set(1,0,third);
	set(1,1,fourth);
}

double Matrix2x2::det() const
{
	return get(0,0)*get(1,1) - get(0,1)*get(1,0);
}

Matrix2x2 Matrix2x2::inverse() const
{
	double determinant = this->det();

	if (determinant == 0)
		return Matrix2x2(0,0,0,0);

	double x = 1 / determinant;

	Matrix2x2 inversed = Matrix2x2(
		x * get(1, 1), x * -get(0, 1), x * -get(1, 0), x * get(0, 0));

	return inversed;

}






Matrix2x2 Matrix2x2::operator+=(const Matrix2x2 &rhs)
{
	double sum = get(0, 0) + rhs.get(0, 0);
	set( 0, 0, sum);
	sum = get(0, 1) + rhs.get(0, 1);
	set( 0, 1, sum );
	sum = get(1, 0) + rhs.get(1, 0);
	set( 1, 0, sum );
	sum = get(1, 1) + rhs.get(1, 1);
	set( 1, 1, sum );

	return *this;
}

Matrix2x2 Matrix2x2::operator-=(const Matrix2x2 &rhs)
{
	double sum = get(0, 0) - rhs.get(0, 0);
	set( 0, 0, sum);
	sum = get(0, 1) - rhs.get(0, 1);
	set( 0, 1, sum );
	sum = get(1, 0) - rhs.get(1, 0);
	set( 1, 0, sum );
	sum = get(1, 1) - rhs.get(1, 1);
	set( 1, 1, sum );

	return *this;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2 &rhs)
{
	Matrix2x2 m = *this;
	m += rhs;
	return m;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2 &rhs)
{
	Matrix2x2 m = *this;
	m -= rhs;
	return m;
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2 &rhs)
{
	Matrix2x2 m = *this;
	Matrix2x2 product = Matrix2x2(0,0,0,0);
	double sum;

	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < 2; j++)
			{
				sum = product.get(i, j) + m.get(i, k) * rhs.get(k, j);
              	product.set(i, j, sum);
			}
		}
	}

	return product;
}

Matrix2x2 Matrix2x2::operator*=(const Matrix2x2 &rhs)
{
	*this = (*this) * rhs;
	return *this;
}


Vector2 Matrix2x2::operator*(const Matrix2x2 &rhs)
{
	Vector2 product;
	Matrix m = *this;
	double sum;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum = product.get(j) + m.get(i, j) * rhs.get(j);
          	product.set(j, sum);
		}
	}
}











ostream& operator<<(ostream& os, const Matrix2x2& m)
{
	os << "| " << m.get(0,0) << " " << m.get(0,1) << " |" << endl;
	os << "| " << m.get(1,0) << " " << m.get(1,1) << " |" << endl;

	return os;
}