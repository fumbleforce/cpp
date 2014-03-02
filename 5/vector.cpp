#include <iostream>
#include <string>
#include <cmath>
#include "vector.h"
using namespace std;


Vector2::Vector2()
{
	setX(0.0);
	setY(0.0);
}
Vector2::Vector2(double first, double second)
{
	setX(first);
	setY(second);
}

double Vector2::dot(const Vector2 &rhs) const
{
	double x = this->getX();
	double y = getY();
	return x * rhs.getX() + y * rhs.getY();
}

double Vector2::lengthSquared() const
{
	return dot(*this);
}

double Vector2::length() const
{
	return sqrt(lengthSquared());
}

ostream& operator<<(ostream &os, const Vector2 &rhs)
{
	os << "[ " << rhs.getX() << ", " << rhs.getY() << " ]";
	return os;
}


Vector2 operator*(const Vector2 &lhs, const Matrix2x2 &rhs)
{
	Vector2 product = Vector2();
	double sum;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum = product.get(i) + rhs.get(i, j) * lhs.get(j);
          	product.set(i, sum);
		}
	}
	return product;
}
