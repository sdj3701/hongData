//
//  Array.cpp
//  hongData
//
//  Created by 신동주 on 2023/09/28.
//

#include "Array.hpp"

using namespace std;

// ∫ÒæÓ ¿÷¥¬ MyString() ª˝º∫
MyString::MyString()
{
    str_ = nullptr;
    size_ = 0;
}

// ∏« µ⁄ø° ≥Œ ƒ≥∏Ø≈Õ'\0'∞° µÈæÓ ¿÷¥¬ πÆ¿⁄ø≠∑Œ∫Œ≈Õ √ ±‚»≠
MyString::MyString(const char* init)
{
    // ≈©±‚(size_) ∞·¡§
    while(init[size_] != '\0')
    {
        size_++;
    }
        
    str_ = new char[size_];

    // µ•¿Ã≈Õ ∫πªÁ
    for(int i =0;i<size_;i++)
        str_[i] = init[i];
}

// MyString¿« ¥Ÿ∏• instance∑Œ∫Œ≈Õ √ ±‚»≠
MyString::MyString(const MyString& str)
{
    // ±‚∫ª ∫πªÁ ª˝º∫¿⁄¥¬ ∆˜¿Œ≈Õ ¡÷º“∏∏ ∫πªÁ«œ±‚ ∂ßπÆø°
    // º“∏ÍΩ√ ø¿∑˘ πﬂª˝
    // ø©±‚º≠¥¬ ªı∑Œ ∏ﬁ∏∏Æ∏¶ «“¥Á πﬁæ∆º≠ ∫πªÁ
    size_ = str.size_;
    str_ = new char[size_];
    strcpy(str_,str.str_);

}

MyString::~MyString()
{
    // ∏ﬁ∏∏Æ «ÿ¡¶
    
    delete[] str_;
}

bool MyString::IsEmpty()
{
    return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // ∆Ì¿«ªÛ ¬¸¡∂& ªÁøÎ
{
    // »˘∆Æ: str.str_, str.size_ ∞°¥…
    
    //길이가 먼저 같은지 확인해서 같은면 돌리고 아니면 바로 false로 돌림
    if(size_ == str.size_)
    {
        for(int i =0; i<size_;i++)
        {
            if(str_[i] != str.str_[i])
                return false;
        }
    }
    else
        return false;
    
    return true;
}

int MyString::Length()
{
    return size_;
}

void MyString::Resize(int new_size)
{
    // ∏ﬁ∏∏Æ ¿Á«“¥Á∞˙ ø¯∑° ∞Æ∞Ì ¿÷¥¯ ≥ªøÎ ∫πªÁ
    
}

// ¿Œµ¶Ω∫ start¿ßƒ°¿« ±€¿⁄∫Œ≈Õ num∞≥¿« ±€¿⁄∑Œ ªı∑ŒøÓ πÆ¿⁄ø≠ ∏∏µÈ±‚
MyString MyString::Substr(int start, int num)
{
    // ∫πªÁ«“ ¿Œµ¶Ω∫: start, start + 1, ... , start + num - 1
    // assert(start + num - 1 < this->size_); // πÆ¡¶∏¶ ¥‹º¯«œ∞‘ ∏∏µÈ±‚ ¿ß«ÿ ∞°¡§

    MyString temp;

    // TODO:

    for(int i =0;i<num;i++)
    {
        temp.str_[i] = str_[start+i];
    }
    
    
    return temp;
}

MyString MyString::Concat(MyString app_str)
{
    MyString temp;

    // TODO:

    for(int i=0;i<size_;i++)
    {
        temp.str_[i] = str_[i];
    }
    for(int i = size_;i<size_+app_str.size_;i++)
    {
        temp.str_[i] = app_str.str_[i -size_];
    }
    
    return temp;
}

MyString MyString::Insert(MyString t, int start)
{
    assert(start >= 0);
    assert(start <= this->size_);

    MyString temp;

    // TODO: temp에 값 넣기
    
    //1. 앞에 str가 가지고 있는 값 넣기
    for(int i = 0;i<start;i++)
    {
        temp.str_[i] = str_[i];
    }
    
    //2. t값 다 넣기
    for(int i = 0; i<t.size_;i++)
    {
        temp.str_[start + i] = t.str_[i];
    }
    
    //3. start시작 위치에서 t.size 만큼 위치를 옮기고 나머지 str을 복사해야함
    for(int i =start;i<size_;i++)
    {
        temp.str_[i + t.size_] = str_[i];
    }
    
    return temp;
}

int MyString::Find(MyString pat)
{
    //TODO:
    
    for(int i =0; i<size_;i++)
    {
        if(str_[i] == pat.str_[0])
        {
            for(int j =0;j<pat.size_;j++)
            {
                if(str_[i+j] == pat.str_[j])
                {
                    return i;
                    
                }
            }
        }
    }
    
    return -1;
}

void MyString::Print()
{
    for (int i = 0; i < size_; i++)
        cout << str_[i];
    cout << endl;
}

