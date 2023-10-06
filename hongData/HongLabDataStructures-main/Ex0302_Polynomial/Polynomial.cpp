#include "Polynomial.h"

#include <cassert>
#include <iostream>
#include <math.h> // std::powf()

using namespace std;

Polynomial::Polynomial(int max_degree) // ���ǻ� �⺻�� ���
{
	assert(max_degree > 0);

	// - ����� ����
	// - ��: max_degree�� 2�̸� c0*x^0 + c1*x^1 + c2*x^2 �� 3���� �׵�
	capacity_ = max_degree + 1;

	// ���� �޸� �Ҵ�
	coeffs_ = new float[capacity_];

	// 0���� �ʱ�ȭ
	for (int i = 0; i < capacity_; i++)
		coeffs_[i] = 0.0f;
}

Polynomial::Polynomial(const Polynomial& poly)
{
	this->capacity_ = poly.capacity_;
	coeffs_ = new float[capacity_];
	for (int i = 0; i < capacity_; i++)
		coeffs_[i] = poly.coeffs_[i];
}

Polynomial::~Polynomial()
{
	if (coeffs_) delete[] coeffs_;
}

int Polynomial::MaxDegree()
{
	return this->capacity_ - 1;
}

void Polynomial::NewTerm(const float coef, const int exp)
{
	assert(exp < capacity_); // exp�� �ʹ� ũ�� resize �ϵ��� ������ ���� ����

	// TODO: ������
	coeffs_[exp] = coef;

}

Polynomial Polynomial::Add(const Polynomial& poly)
{
	assert(poly.capacity_ == this->capacity_); // ������ �ܼ�ȭ�ϱ� ���� ����

	Polynomial temp(this->MaxDegree());

	// TODO:

	return temp;
}

Polynomial Polynomial::Mult(const Polynomial& poly)
{
	assert(poly.capacity_ == this->capacity_); // ������ �ܼ�ȭ�ϱ� ���� ����

	// coeff_[i]�� 0.0f�� �ƴ� ��쿡 ���ؼ��� ��� (���ϸ� 0�� �Ǳ� ����)

	Polynomial temp(this->MaxDegree());

	// TODO: �׻� �ε��� ���� ����

	return temp;
}

float Polynomial::Eval(float x)
{
	float temp = 0.0f;

	// TODO:
	// ��Ʈ std::powf(2.0f, float(3)); // 2.0f^3.0f = 8.0f (2.0f�� 3.0f ����)

	for (int i = 1; i < capacity_; i++)
	{
		temp += (coeffs_[i] * pow(i, x));
	}
	temp += coeffs_[0];

	return temp;
}

void Polynomial::Print()
{
	bool is_first = true; // ���ϱ� ��½� Ȯ�ο�

	for (int i = 0; i < capacity_; i++)
	{
		if (coeffs_[i] != 0.0f) // ����: 0�� �ƴ� �׵鸸 ���
		{
			if (!is_first)
				cout << " + "; // ù ���� �ƴ϶�� ���̻��̿� ���ϱ� ���

			cout << coeffs_[i];

			if (i != 0) cout << "*" << "x^" << i;

			is_first = false;
		}
	}

	cout << endl;
}