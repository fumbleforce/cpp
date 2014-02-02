#pragma once
#include <string>
#include "vector.h"


class Matrix2x2
{
private:
	double matrix[2][2];

public:
	Matrix2x2();
	Matrix2x2(int first, int second, int third, int fourth);
	
	std::string toString();
	void print();
	double det() const;
	Matrix2x2 inverse() const;

	double get(int x, int y) const { return matrix[x][y]; }
	double set(int x, int y, double value) { matrix[x][y] = value; }

	Matrix2x2 operator+=(const Matrix2x2 &rhs);
	Matrix2x2 operator-=(const Matrix2x2 &rhs);
	Matrix2x2 operator*(const Matrix2x2 &rhs);
	Matrix2x2 operator*=(const Matrix2x2 &rhs);
	Matrix2x2 operator+(const Matrix2x2 &rhs);
	Matrix2x2 operator-(const Matrix2x2 &rhs);

	Vector2 operator*(const Matrix2x2 &rhs);
	
};

std::ostream& operator<<(std::ostream &os, const Matrix2x2 &m);