#pragma once

#include <iostream>
#include <algorithm> // swap
#include <cassert>

// Abstract Data Type ���� �Ұ�
// ����: ���� ADT�� Ư�� �� ���ӵǴ� ������ �ƴմϴ�.

/* Horowitz ����
An abstract data type (ADT) is a data type
that is organized in such a way that the specification of the operations
on the objects is separated from the representation of the objects and
the implementation of the operations.
*/

/*

class MyArray // ���ο��� �̸��տ� My�� �ٿ��� ȥ�� ����
{
public:
	MyArray(int size);

	~MyArray(); // ADT��� ���ٴ� ��� Ư��

	float Retrieve(int i);

	void Store(int i, float x);

private:
	float* arr_ = 0;
	int size_ = 0;
}

*/

class MyString
{
public:
	MyString();						// ��� �ִ� MyString() ����
	MyString(const char* init);		// �� �ڿ� �� ĳ����'\0'�� ��� �ִ� ���ڿ��κ��� �ʱ�ȭ
	MyString(const MyString& str);	// MyString�� �ٸ� instance�κ��� �ʱ�ȭ
	~MyString();

	bool IsEmpty();
	bool IsEqual(const MyString& str);
	int Length();
	void Resize(int new_size);

	MyString Substr(int start, int num);	// �ε��� start��ġ�� ���ں��� num���� ���ڷ� ���ο� ���ڿ� �����
	MyString Concat(MyString app_str);		// �ڿ� ������ ���ο� ���ڿ� ��ȯ (append)
	MyString Insert(MyString t, int start); // �߰��� ����

	int Find(MyString pat);

	void Print();

private:
	char* str_ = nullptr; // �������� '\0' ����
	int size_ = 0; // ���� ��
};