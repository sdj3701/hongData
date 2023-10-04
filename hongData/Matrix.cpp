#include "Matrix.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
    // TODO: 몇바이 몇인지 확인
    values_ = new float[num_rows * num_cols];
    
    this->num_rows_ = num_rows;
    this->num_cols_ = num_cols;
    
    //**
    for(int i =0; i < num_rows_ * num_cols_ ; i++)
    {
        values_[i] = 0.0f;
    }
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix& b)
{
    values_ = new float[b.num_cols_*b.num_rows_];
    // TODO: 복사 생성자
    num_cols_ = b.num_cols_;
    num_rows_ = b.num_rows_;
    
    for(int i=0;i<num_cols_*num_rows_;i++)
        values_[i] = b.values_[i];
}

Matrix::~Matrix()
{
    delete[] values_;
    // TODO: 파괴자 인데 뭘 생성 했어?
}

void Matrix::SetValue(int row, int col, float value)
{
    // values_[TODO] = value;
    values_[col+(row*4)] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    return values_[col+(row*4)];
}

Matrix Matrix::Transpose()
{
    Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

    // TODO: 순서를 바꿔서 구현
    
    temp.num_cols_ = num_rows_;
    temp.num_rows_ = num_cols_;

    temp.values_[num_rows_ + (num_cols_ * 4)] = values_[num_cols_*4 + num_rows_];
    
    return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Matrix temp(num_rows_, num_cols_);

    // TODO:자기 자신 더하기

    temp.values_[num_cols_+(num_rows_*4)] = values_[num_cols_ + (num_rows_*4)] + b.values_[num_cols_ + (num_rows_*4)];
    
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
