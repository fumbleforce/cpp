#include <iostream>
#include "matrix.h"
using namespace std;




Matrix::Matrix()
{
	this->matrix = NULL;
}

Matrix::Matrix(const Matrix &other)
{
	this->matrix = new double[other.getWidth() *other.getHeight()];

	for (int i = 0; i < (other.getWidth() * other.getHeight()); i++)
	{
		this->matrix[i] = other.get(i);
	}

	this->rows = other.getHeight();
	this->cols = other.getWidth();
}

Matrix::Matrix(unsigned int nRows, unsigned int nColumns)
{
	this->matrix = new double[nRows * nColumns];
	this->rows = nRows;
	this->cols = nColumns;
}

Matrix::Matrix(unsigned int nRows, unsigned int nColumns, double val) : Matrix(nRows, nColumns)
{
	for (int i = 0; i < (nRows * nColumns); i++)
		this->matrix[i] = val;
}

Matrix::Matrix(unsigned int nRows) : Matrix(nRows, nRows)
{
	for (int i = 0; i < nRows; i++)
	{
		this->matrix[i + nRows * i] = 1;
	}
}

bool Matrix::isValid() const
{
	return this->matrix != NULL;
}






Matrix Matrix::operator+=(const Matrix &rhs)
{
	if (this->getWidth() != rhs.getWidth() ||
		this->getHeight() != rhs.getHeight())
	{
		return Matrix();
	}

	double sum;

	for (int i = 0; i < this->getHeight(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			sum = this->get(i, j) + rhs.get(i, j);
			this->set(i, j, sum);
		}
	}
	return *this;
}

Matrix Matrix::operator-=(const Matrix &rhs)
{
	if (this->getWidth() != rhs.getWidth() ||
		this->getHeight() != rhs.getHeight())
	{
		return Matrix();
	}

	double sum;

	for (int i = 0; i < this->getHeight(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			sum = this->get(i, j) - rhs.get(i, j);
			this->set(i, j, sum);
		}
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix &rhs)
{
	Matrix m = *this;
	m += rhs;
	return m;
}

Matrix Matrix::operator-(const Matrix &rhs)
{
	Matrix m = *this;
	m -= rhs;
	cout << m << endl;
	return m;
}

Matrix Matrix::operator*(const Matrix &rhs)
{
	if (this->getWidth() != rhs.getHeight() ||
		this->getHeight() != rhs.getWidth())
	{
		return Matrix();
	}

	Matrix m = *this;
	double sum;
	int width = rhs.getWidth();
	int height = m.getHeight();
	Matrix product = Matrix(height, width);

	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < m.getWidth(); k++)
		{
			for (int j = 0; j < width; j++)
			{
				sum = product.get(i, j) + m.get(i, k) * rhs.get(k, j);
              	product.set(i, j, sum);
			}
		}
	}

	return product;
}

Matrix Matrix::operator*=(const Matrix &rhs)
{
	*this = (*this) * rhs;
	return *this;
}


Matrix Matrix::operator=(const Matrix &other) {
	this->matrix = new double[other.getWidth() *other.getHeight()];

	for (int i = 0; i < (other.getWidth() * other.getHeight()); i++)
	{
		this->matrix[i] = other.get(i);
	}

	this->rows = other.getHeight();
	this->cols = other.getWidth();
	return *this;
}


ostream& operator<<(ostream& os, const Matrix& m)
{
	if (!m.isValid())
	{
		os << "Invalid Matrix" << endl;
		return os;
	}

	for (int i = 0; i < m.getHeight(); i++)
	{
		os << "|";
		for (int j = 0; j < m.getWidth(); j++)
		{
			os << " " << m.get(i, j) << " ";
		}
		os << "|" << endl;
	}

	return os;
}