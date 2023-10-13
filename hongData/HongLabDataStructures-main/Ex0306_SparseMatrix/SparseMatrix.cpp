#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	// TODO: 동적 할당 및 등등

	num_rows_ = num_rows;
	num_cols_ = num_cols;
	capacity_ = capacity;

	terms_ = new MatrixTerm[num_rows * num_cols];
	for (int i = 0;i < num_rows ;i++)
	{
		terms_[i].row = i;
		for (int j = 0;j < num_cols;j++)
		{
			terms_[j].col = j;
			terms_[i * num_rows + j].value = 0.0f;
		}
	}
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix& b)
{
	// TODO:

	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;
	capacity_ = b.capacity_;
	num_terms_ = b.num_terms_;

	for (int i = 0;i < num_rows_ * num_cols_;i++)
	{
		terms_[i] = b.terms_[i];
	}

}

SparseMatrix::~SparseMatrix()
{
	// TODO:
	delete[] terms_;
	
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f) return; // value가 0이 아닌 term만 저장

	// TODO:
	terms_[row * num_rows_ + col].value = value;
}

float SparseMatrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	// TODO: key = col + num_cols * row;
	return terms_[row * num_cols_ + col].value;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의

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
