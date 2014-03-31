
#include <iostream>
#include <cmath>
#include "vector.h"
using namespace std;



Vector::Vector()
{
	this->matrix = NULL;
}

Vector::Vector(unsigned int nRows) : Matrix(nRows, 1, 0)
{
}

Vector::Vector(const Matrix &other)
{
	if (other.isValid() &&
		other.getWidth() == 1 &&
		other.getHeight() > 0)
	{
		*this = Matrix(other);
	}
	else
	{
		*this = Vector();
	}
}

double Vector::dot(const Vector &rhs) const
{
	if (this->getHeight() != rhs.getHeight())
	{
		return nan("");
	}
	double sum = 0;

	for (int i = 0; i < rhs.getHeight(); i++)
	{
		sum += this->get(i) * rhs.get(i);
	}
	return sum;
}

double Vector::lengthSquared() const
{
	return dot(*this);
}

double Vector::length() const
{
	return sqrt(lengthSquared());
}