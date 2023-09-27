#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	// TODO:
}

// ���� ������ (b�� ����)
SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	// TODO:
}

SparseMatrix::~SparseMatrix()
{
	// TODO:
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; // value�� 0�� �ƴ� term�� ����

	// TODO:
}

float SparseMatrix::GetValue(int row, int col) const // �� ���� const�� �Լ� �ȿ��� ��� ������ ���� �ٲ��� �ʰڴٴ� �ǹ�
{
	// TODO: key = col + num_cols * row;

	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ ���� ����

	// TODO:

	return temp;
}

void SparseMatrix::PrintTerms()
{
	for (int i = 0; i < num_terms_; i++)
		cout << "(" << terms_[i].row
		<< ", " << terms_[i].col
		<< ", " << terms_[i].value
		<< ")" << endl;
}

void SparseMatrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}
