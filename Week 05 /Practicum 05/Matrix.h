#pragma once

class Matrix
{
private: 
	int** data;
	int rows;
	int cols;

	void free();
	void copyFrom(const Matrix& other);

public:
	Matrix();
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix(int newRows, int newCols);

	void setValue(int row, int col, int val);

	void printMatrix() const;
};
