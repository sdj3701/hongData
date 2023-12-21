//
//  SparsePolynomial.cpp
//  hongData
//
//  Created by 신동주 on 2023/09/29.
//

#include "SparsePolynomial.hpp"
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

// 새로운 항을 추가할 때 자기 위치를 찾아서 넣어줘야 함

// exp항이 이미 존재하면 거기에 coef를 더해준다.
// 존재하지 않는다면 exp 오름 차순으로 정렬된 상태로 새로 추가한다.
void SparsePolynomial::NewTerm(float coef, int exp)
{
    if (coef == 0.0f) return; // 0이면 추가하지 않음

    if (num_terms_ >= capacity_)
    {
        // capacity 증가 (num_terms는 일단 고정)
        capacity_ = capacity_ > 0 ? capacity_ * 2 : 1; // 2배씩 증가
        Term* new_term = new Term[capacity_];

        // 원래 가지고 있던 데이터 복사
        memcpy(new_term, terms_, sizeof(Term) * num_terms_);

        // 메모리 교체
        if (terms_) delete[] terms_;
        terms_ = new_term;
    }

    terms_[num_terms_].coef = coef;
    terms_[num_terms_].exp = exp;

    num_terms_++;
}

float SparsePolynomial::Eval(float x)
{
    float temp = 0.0f;

    // TODO:상수는 그냥 출력하고 제곱은 x를 곱해서 상수 출력
    temp += terms_[0].coef;
    for(int i=1;i<capacity_;i++)
    {
        temp += terms_[i].coef * x;
    }

    return temp;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
    // this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
    // 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

    // 간단한 방법 (메모리를 더 사용하는 방법)
    // - 1. 최대 exp를 찾는다.
    // - 2. 필요한 크기의 Polynomial을 만든다. (Sparse 아님)
    // - 3. 더하면서 Polynomial에 업데이트 한다. 구조가 고정되어 있어서 쉽다.
    // - 4. Polynomial을 SparsePolynomial로 변환한다.

    SparsePolynomial temp;

    // TODO: 처음에는 서로 하나씩 비교를 하면서 같이 증가 서로 다른 숫자가 나오면 작은 숫자는 출력 큰숫자는 있는지 확인

    int count=0,check =-1;
    if(this->capacity_>poly.capacity_)
    {
        for(int i=0;i<capacity_;i++)
        {
            //제곱근이 같으면 둘이 더해서 출력하고
            if(terms_[i].exp == poly.terms_[i].exp)
            {
                temp.terms_[i].coef = terms_[i].coef + poly.terms_[i].coef;
            }
            //this가 크면 poly를 만 출력
            else if(terms_[i-count].exp > poly.terms_[i].exp)
            {
                //여기서 count를 생각해서 값을 바꿔도 좋은데 한번더 바뀌면 답이 없는데
                if(check ==0)
                    count--;
                temp.terms_[i].coef = poly.terms_[i].coef;
                if(terms_[i+1].exp < poly.terms_[i-count-1].exp &&check != 0)
                {
                    check = 0;
                }
                count++;
            }
            //poly가 크면 this만 출력
            else if(terms_[i].exp < poly.terms_[i-count].exp)
            {
                if(check ==1)
                    count--;
                temp.terms_[i].coef = terms_[i].coef;
                if(terms_[i-count-1].exp > poly.terms_[i+1].exp &&check != 1)
                {
                    check = 1;
                }
                count++;
            }
        }
    }
    else
    {
        
    }
    
    return temp;
}

void SparsePolynomial::Print()
{
    bool is_first = true; // 더하기 출력시 확인용

    for (int i = 0; i < num_terms_; i++)
    {
        // 0이 아닌 항들만 골라서 출력할 필요가 없음

        if (!is_first)
            cout << " + "; // 첫 항이 아니라면 사이사이에 더하기 출력

        cout << terms_[i].coef;

        if (terms_[i].exp != 0) cout << "*" << "x^" << terms_[i].exp;

        is_first = false;
    }

    cout << endl;
}
