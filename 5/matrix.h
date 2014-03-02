#pragma once
#include <string>



class Matrix2x2
{
private:
	double matrix[2][2];

public:
	Matrix2x2();
	Matrix2x2(double first, double second, double third, double fourth);
	
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

	
	
};

std::ostream& operator<<(std::ostream &os, const Matrix2x2 &m);