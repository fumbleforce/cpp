#pragma once





class Matrix
{
private:
	double *matrix;
	int rows;
	int cols;

public:
	Matrix();
	Matrix(const Matrix &other);
	Matrix(unsigned int nRows, unsigned int nColumns);
	Matrix(unsigned int nRows, unsigned int nColumns, double val);
	explicit Matrix(unsigned int nRows);
	~Matrix() { delete [] matrix; };

	bool isValid() const;

	int getWidth() const { return cols; };
	int getHeight() const { return rows; };
	double get(int pos) const { return matrix[pos]; };
	double get(int row, int col) const { return matrix[col + this->cols * row]; };
	double set(int row, int col, double val) { matrix[col + this->cols * row] = val; };
	double set(int pos, double val) { matrix[pos] = val; };
	double* getArray() const { return matrix; };

	Matrix operator=(const Matrix &rhs);
	Matrix operator+=(const Matrix &rhs);
	Matrix operator-=(const Matrix &rhs);
	Matrix operator*(const Matrix &rhs);
	Matrix operator*=(const Matrix &rhs);
	Matrix operator+(const Matrix &rhs);
	Matrix operator-(const Matrix &rhs);
};

std::ostream& operator<<(std::ostream &os, const Matrix &m);