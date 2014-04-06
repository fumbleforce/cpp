#pragma once
#include "matrix.h"


class Vector : public Matrix
{
private:


public:
	Vector();
	explicit Vector(unsigned int nRows);
	Vector(const Matrix & other);

	double dot(const Vector &rhs) const;
	double lengthSquared() const;
	double length() const;

	double get(unsigned int row) const { return matrix[row]; };
	void set(unsigned int row, double val) { matrix[row] = val; };
};