#pragma once

#include "matrix.h"


class Vector2
{
private:
	double v[2];

public:
	Vector2();
	Vector2(double first, double second);
	double dot(const Vector2 &rhs) const;
	double lengthSquared() const;
	double length() const;

	double get(int i) const { return v[i]; }
	double set(int i, double val) { v[i] = val; }
	double getX() const { return v[0]; }
	double getY() const { return v[1]; }
	double setX(double val) { v[0] = val; }
	double setY(double val) { v[1] = val; }
	
};

std::ostream& operator<<(std::ostream &os, const Vector2 &rhs);
Vector2 operator*(const Vector2 &lhs, const Matrix2x2 &rhs);