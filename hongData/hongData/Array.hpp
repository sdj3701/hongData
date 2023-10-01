//
//  Array.hpp
//  hongData
//
//  Created by 신동주 on 2023/09/28.
//

#include <iostream>
#include <algorithm> // swap
#include <cassert>


#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>

#endif /* Array_hpp */
class MyString
{
public:
    MyString();                        // ∫ÒæÓ ¿÷¥¬ MyString() ª˝º∫
    MyString(const char* init);        // ∏« µ⁄ø° ≥Œ ƒ≥∏Ø≈Õ'\0'∞° µÈæÓ ¿÷¥¬ πÆ¿⁄ø≠∑Œ∫Œ≈Õ √ ±‚»≠
    MyString(const MyString& str);    // MyString¿« ¥Ÿ∏• instance∑Œ∫Œ≈Õ √ ±‚»≠
    ~MyString();

    bool IsEmpty();
    bool IsEqual(const MyString& str);
    int Length();
    void Resize(int new_size);

    MyString Substr(int start, int num);    // ¿Œµ¶Ω∫ start¿ßƒ°¿« ±€¿⁄∫Œ≈Õ num∞≥¿« ±€¿⁄∑Œ ªı∑ŒøÓ πÆ¿⁄ø≠ ∏∏µÈ±‚
    MyString Concat(MyString app_str);        // µ⁄ø° µ°∫Ÿ¿Œ ªı∑ŒøÓ πÆ¿⁄ø≠ π›»Ø (append)
    MyString Insert(MyString t, int start); // ¡ﬂ∞£ø° ª¿‘

    int Find(MyString pat);

    void Print();

private:
    char* str_ = nullptr; // ∏∂¡ˆ∏∑ø° '\0' æ¯¿Ω
    int size_ = 0; // ±€¿⁄ ºˆ
};
