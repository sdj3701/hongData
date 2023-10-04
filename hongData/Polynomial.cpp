#include "Polynomial.hpp"

#include <cassert>
#include <iostream>
#include <math.h> // std::powf()

using namespace std;

Polynomial::Polynomial(int max_degree) // ∆Ì¿«ªÛ ±‚∫ª∞™ ªÁøÎ
{
    assert(max_degree > 0);

    // - ªÛºˆ«◊ ∆˜«‘
    // - øπ: max_degree∞° 2¿Ã∏È c0*x^0 + c1*x^1 + c2*x^2 √— 3∞≥¿« «◊µÈ
    capacity_ = max_degree + 1;

    // µø¿˚ ∏ﬁ∏∏Æ «“¥Á
    coeffs_ = new float[capacity_];

    // 0¿∏∑Œ √ ±‚»≠
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
    assert(exp < capacity_); // exp∞° ≥ π´ ≈©∏È resize «œµµ∑œ ±∏«ˆ«“ ºˆµµ ¿÷¿Ω

    // TODO: exp는 제곱 coef는 상수
    
    coeffs_[exp] = coef;
    
    
}

Polynomial Polynomial::Add(const Polynomial& poly)
{
    assert(poly.capacity_ == this->capacity_); // πÆ¡¶∏¶ ¥‹º¯»≠«œ±‚ ¿ß«— ∞°¡§

    Polynomial temp(this->MaxDegree());

    // TODO: 들고 있는 값과 poly값을 더해주는 함수
    
    //0부터 끝가지 확인
    for(int i = 0;i < capacity_;i++)
    {
        //만약 둘중 하나도 0이 아니면 그자리에 값을 넣어주자
        if(coeffs_[i] != '0' || '0' != poly.coeffs_[i])
        {
            //실제로 값을 더해주는 
            temp.coeffs_[i] = coeffs_[i] + poly.coeffs_[i];
        }
    }
    return temp;
}

Polynomial Polynomial::Mult(const Polynomial& poly)
{
    assert(poly.capacity_ == this->capacity_); // πÆ¡¶∏¶ ¥‹º¯»≠«œ±‚ ¿ß«— ∞°¡§

    // coeff_[i]∞° 0.0f∞° æ∆¥— ∞ÊøÏø° ¥Î«ÿº≠∏∏ ∞ËªÍ (∞ˆ«œ∏È 0¿Ã µ«±‚ ∂ßπÆ)

    Polynomial temp(this->MaxDegree());

    // TODO: 곱하면 자리를 맞는 숫자에 곱해야함
    
    
    for(int i=0;i<capacity_; i++)
    {
        //0이 아니면 
        if(poly.coeffs_[i] != '0')
        {
            for(int j =0;j<capacity_;j++)
            {
                if(coeffs_[j] != '0')
                {
                    temp.coeffs_[i+j]= coeffs_[j] * poly.coeffs_[i];
                }
            }
        }
    }
    

    return temp;
}

float Polynomial::Eval(float x)
{
    float temp = 0.0f;

    // TODO:상수 인것은 제외하고 제곱인 경우만 값을 곱하고 더해서 반환
    // »˘∆Æ std::powf(2.0f, float(3)); // 2.0f^3.0f = 8.0f (2.0f¿« 3.0f ¡¶∞ˆ)
    temp += coeffs_[0];
    
    for(int i =1; i<capacity_;i++)
    {
        if(coeffs_[i] != '0')
            temp += (coeffs_[i] * x);
    }

    return temp;
}

void Polynomial::Print()
{
    bool is_first = true; // ¥ı«œ±‚ √‚∑¬Ω√ »Æ¿ŒøÎ

    for (int i = 0; i < capacity_; i++)
    {
        if (coeffs_[i] != 0.0f) // ¡÷¿«: 0¿Ã æ∆¥— «◊µÈ∏∏ √‚∑¬
        {
            if (!is_first)
                cout << " + "; // √π «◊¿Ã æ∆¥œ∂Û∏È ªÁ¿ÃªÁ¿Ãø° ¥ı«œ±‚ √‚∑¬

            cout << coeffs_[i];

            if (i != 0) cout << "*" << "x^" << i;

            is_first = false;
        }
    }

    cout << endl;
}

