#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
	// TODO:
}

// ���� ������ (b�� ����)
Matrix::Matrix(const Matrix& b)
{
	// TODO:
}

Matrix::~Matrix()
{
	// TODO:
}

void Matrix::SetValue(int row, int col, float value)
{
	// values_[TODO] = value;
}

float Matrix::GetValue(int row, int col) const // �� ���� const�� �Լ� �ȿ��� ��� ������ ���� �ٲ��� �ʰڴٴ� �ǹ�
{
	return 0.0f;
}

Matrix Matrix::Transpose()
{
	Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ ���� ����

	// TODO:

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);

	// TODO:

	return temp;
}

void Matrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}
