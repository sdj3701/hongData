#include "MyString.h"

using namespace std;

// ��� �ִ� MyString() ����
MyString::MyString()
{
	str_ = nullptr;
	size_ = 0;
}

// �� �ڿ� �� ĳ����'\0'�� ��� �ִ� ���ڿ��κ��� �ʱ�ȭ
MyString::MyString(const char* init)
{
	size_ = sizeof(init) / sizeof(init[0]);
	// ũ��(size_) ����
	const char* str_ = new char[size_];
	// �޸� �Ҵ�
	str_ = init;
	// ������ ����
}

// MyString�� �ٸ� instance�κ��� �ʱ�ȭ
MyString::MyString(const MyString& str)
{
	// �⺻ ���� �����ڴ� ������ �ּҸ� �����ϱ� ������ 
	// �Ҹ�� ���� �߻�
	// ���⼭�� ���� �޸𸮸� �Ҵ� �޾Ƽ� ����

}

MyString::~MyString()
{
	delete[] str_;
	// �޸� ����
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // ���ǻ� ����& ���
{
	// ��Ʈ: str.str_, str.size_ ����

	return false;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	// �޸� ���Ҵ�� ���� ���� �ִ� ���� ����
}

// �ε��� start��ġ�� ���ں��� num���� ���ڷ� ���ο� ���ڿ� �����
MyString MyString::Substr(int start, int num)
{
	// ������ �ε���: start, start + 1, ... , start + num - 1
	// assert(start + num - 1 < this->size_); // ������ �ܼ��ϰ� ����� ���� ����

	MyString temp;

	// TODO:

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;

	// TODO: 

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;

	// TODO:

	return temp;
}

int MyString::Find(MyString pat)
{
	//TODO:

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}