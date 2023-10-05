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
	// ũ��(size_) ����
	while (true)
	{
		if (init[size_] != '\0')
			size_++;
		else
			break;
	}
	// �޸� �Ҵ�
	str_ = new char[size_];

	// ������ ����
	for (int i = 0;i < size_;i++)
	{
		str_[i] = init[i];
	}
	
}

// MyString�� �ٸ� instance�κ��� �ʱ�ȭ
MyString::MyString(const MyString& str)
{
	// �⺻ ���� �����ڴ� ������ �ּҸ� �����ϱ� ������ 
	// �Ҹ�� ���� �߻�
	// ���⼭�� ���� �޸𸮸� �Ҵ� �޾Ƽ� ����

	size_ = str.size_;
	str_ = new char[size_];
	for (int i = 0; i < size_;i++)
	{
		str_[i] = str.str_[i];
	}

}

MyString::~MyString()
{
	if(str_ != nullptr) delete[] str_;
	// �޸� ����
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // ���ǻ� ����& ���
{
	// ��Ʈ: str.str_, str.size_ ����
	int count = 0;
	for (int i = 0;i < size_;i++)
	{
		if (str.str_[i] == str_[i])
			count++;
	}

	return count == str.size_ ? true : false;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	// �޸� ���Ҵ�� ���� ���� �ִ� ���� ����
	size_ += new_size;

	if (new_size != size_)
	{
		char* new_str = new char[new_size];

		memcpy(new_str, str_, size_);

		delete[] str_;
		str_ = new_str;
		size_ = new_size;
	}

}

// �ε��� start��ġ�� ���ں��� num���� ���ڷ� ���ο� ���ڿ� �����
MyString MyString::Substr(int start, int num)
{
	// ������ �ε���: start, start + 1, ... , start + num - 1
	// assert(start + num - 1 < this->size_); // ������ �ܼ��ϰ� ����� ���� ����

	MyString temp;

	// TODO:
	temp.Resize(num);

	for (int i = 0; i < num; i++)
		temp.str_[i] = this->str_[start + i];

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;
	temp.Resize(this->size_ + app_str.size_);

	memcpy(temp.str_, this->str_, this->size_);
	memcpy(&temp.str_[this->size_], app_str.str_, app_str.size_);
	// TODO: 

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;
	
	temp.Resize(size_ + t.size_);

	// TODO:t�� �Է��� ���� start�� �ڸ�
	for (int i = 0; i < start; i++)
		temp.str_[i] = str_[i];

	for (int i = start; i < start + t.size_; i++)
		temp.str_[i] = t.str_[i - start];

	for (int i = start + t.size_; i < size_ + t.size_; i++)
		temp.str_[i] = str_[i - t.size_];

	return temp;
}

int MyString::Find(MyString pat)
{
	//TODO: ���� ���ڰ� ������ ���° �ڸ����� �˷������
	for (int i = 0; i < size_;i++)
	{
		int count = 0;
		for (int j = 0;j < pat.size_;j++)
		{
			if (str_[i + j] == pat.str_[j])
			{
				count++;
			}
		}
		if (count == pat.size_)
			return i;
	}

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}

