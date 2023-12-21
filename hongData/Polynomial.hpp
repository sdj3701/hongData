#pragma once

class Polynomial
{
public:
    Polynomial(int max_degree = 100);

    Polynomial(const Polynomial& poly);

    ~Polynomial();

    int MaxDegree();

    void NewTerm(const float coef, const int exp);

    Polynomial Add(const Polynomial& poly);

    Polynomial Mult(const Polynomial& poly);

    float Eval(float x);

    void Print();

private:
    int capacity_ = 0; // «◊ªÛ ∏µÁ «◊(term)µÈ¿Ã ¥Ÿ ¬˜ ¿÷¥¬ ∞Õ¿∫ æ∆¥œ±‚ ∂ßπÆø° size ¥ÎΩ≈ capacity ªÁøÎ
    float* coeffs_ = nullptr;
};

