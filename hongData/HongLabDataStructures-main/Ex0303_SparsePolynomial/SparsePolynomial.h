#pragma once

struct Term
{
	float coef;
	int exp;
};

class SparsePolynomial
{
public:
	SparsePolynomial()
	{
		// �ƹ��͵� ���� ���� (�����Ҵ� �޸� ���� ����)
	}

	~SparsePolynomial()
	{
		if (terms_) delete[] terms_;
	}

	// ���ο� ���� �߰��� �� �ڱ� ��ġ�� ã�Ƽ� �־���� ��
	void NewTerm(float coef, int exp);

	float Eval(float x);

	SparsePolynomial Add(const SparsePolynomial& poly);

	void Print();

private:
	Term* terms_ = nullptr;
	int capacity_ = 0;
	int num_terms_ = 0;
};