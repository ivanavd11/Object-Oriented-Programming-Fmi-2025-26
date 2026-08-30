#include "Matrix.h"
#include <iostream>

void Matrix::free()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[]data;

	data = nullptr;
	rows = cols = 0;
}
void Matrix::copyFrom(const Matrix& other)
{
	this->rows = other.rows;
	this->cols = other.cols;

	if (rows == 0 || cols == 0)
	{
		data = nullptr;
		return;
	}

	data = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new int[cols];

		for (int j = 0; j < cols; j++)
		{
			data[i][j] = other.data[i][j];
		}
	}
}

Matrix::Matrix()
{
	data = nullptr;
	rows = cols = 0;
}

Matrix::Matrix(const Matrix& other)
{
	copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	free();
}

Matrix::Matrix(int newRows, int newCols)
{
	if (newRows == 0 || newCols == 0)
	{
		std::cout << "Invalid matrix size!" << std::endl;

		this->rows = 0;
		this->cols = 0;
		data = nullptr;

		return;
	}

	this->rows = newRows;
	this->cols = newCols;

	data = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new int[cols];

		for (int j = 0; j < cols; j++)
		{
			data[i][j] = 0;
		}
	}
}

void Matrix::setValue(int row, int col, int val)
{
	if (row<0 || col<0 || this->rows<=row || this->cols<=col)
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	data[row][col] = val;
}

void Matrix::printMatrix() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << data[i][j] << " ";
		}

		std::cout << std::endl;
	}
}