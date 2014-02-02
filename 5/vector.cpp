#include <iostream>
#include <string>
#include <cmath>
#include "vector.h"
using namespace std;




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

ostream& Vector2::operator<<(ostream &os)
{
	os << "[ " << getX() << ", " << getY() << " ]";
	return os;
}