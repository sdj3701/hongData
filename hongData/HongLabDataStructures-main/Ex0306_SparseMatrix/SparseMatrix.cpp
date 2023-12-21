#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	// TODO: ���� �Ҵ� �� ���

	num_rows_ = num_rows;
	num_cols_ = num_cols;
	capacity_ = capacity;
	num_terms_ = 0;

	terms_ = new MatrixTerm[capacity];

}

// ���� ������ (b�� ����)
SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	// TODO:

	num_rows_ = b.num_rows_; 
	num_cols_ = b.num_cols_;
	capacity_ = b.capacity_;
	num_terms_ = b.num_terms_;

	memcpy(terms_, b.terms_, sizeof(MatrixTerm) * num_terms_);

}

SparseMatrix::~SparseMatrix()
{
	// TODO:
	delete[] terms_; 
	
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; // value�� 0�� �ƴ� term�� ����

	// TODO:
	int key = col + num_cols_ * row;
	for (int i = 0; i < num_terms_;i++)
	{
		terms_[row * num_cols_ + col].value = value;
	}
	
}

float SparseMatrix::GetValue(int row, int col) const // �� ���� const�� �Լ� �ȿ��� ��� ������ ���� �ٲ��� �ʰڴٴ� �ǹ�
{
	// TODO: key = col + num_cols * row;
	return terms_[row * num_cols_ + col].value;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ ���� ����

	// TODO:
	temp.num_cols_ = num_rows_;
	temp.num_rows_ = num_cols_;
	temp.capacity_ = capacity_;

	for (int i = 0; i < num_rows_;i++)//6
	{
		for (int j = 0;j < num_cols_;j++)//4
		{
			temp.terms_[i * num_cols_ + j].value = terms_[i * num_cols_ + j].value;
		}
	}
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
