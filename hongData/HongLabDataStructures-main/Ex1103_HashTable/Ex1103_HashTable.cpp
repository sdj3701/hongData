#include <iostream>
#include <string> // std::string

using namespace std;

template<typename K, typename V>
class HashTable
{
public:
	struct Item
	{
		K key = K();
		V value = V();
	};

	HashTable(const int& cap = 8)
	{
		capacity_ = cap;
		table_ = new Item[capacity_];
	}

	~HashTable()
	{
		delete[] table_;
	}

	void Insert(const Item& item)
	{
		// TODO:

		size_t index = item.key; // Ű�� �ε����� ���
		table_[index] = item;
	}

	V Get(const K& key)
	{
		// TODO: �� ã���� 0�� ��ȯ

		size_t index = key;
		return table_[index].value;
	}

	// ���� -> �ؽ���
	size_t HashFunc(const int& key)
	{
		// TODO:

		return key;
	}

	// ���ڿ��� ���� �ε���(�ؽ���)�� ��ȯ
	// Horner's method
	//size_t HashFunc(const string& s)
	//{
	//  return TODO:
	//}

	void Print()
	{
		for (int i = 0; i < capacity_; i++)
			cout << i << " : " << table_[i].key << " " << table_[i].value << endl;
		cout << endl;
	}

private:
	Item* table_ = nullptr;
	int capacity_ = 0;
};

int main()
{
	// �浹 
	// - ���� �ּҹ�: ���� �����
	// - ü�̴�: ��� ���� Item* table_ ��ſ� LinkedList<Item>* table_���

	// Ű: int, ��: int �� ���
	// Ű�� ������ ���� ũ�� �������� ������ ���� ���
	{
		using Item = HashTable<int, int>::Item;

		HashTable<int, int> h(8);

		h.Insert(Item{ 123, 456 });

		h.Print();

		cout << "Get 123 " << h.Get(123) << endl;

		h.Insert(Item{ 1000021, 9898 });

		h.Print();

		cout << "Get 1000021 " << h.Get(1000021) << endl;

		h.Insert(Item{ 1211, 999 }); // �浹!

		h.Print();

		cout << "Get 123 " << h.Get(123) << endl;
		cout << "Get 1211 " << h.Get(1211) << endl;
	}

	// Ű: std::string, ��: int
	//{
	//	using Item = HashTable<string, int>::Item;

	//	HashTable<string, int> h(8);

	//	h.Insert(Item{ "apple", 1 });
	//	h.Insert(Item{ "orange", 2 });
	//	h.Insert(Item{ "mandarin", 4 });

	//	h.Print();

	//	cout << "apple " << h.Get("apple") << endl;
	//	cout << "orange " << h.Get("orange") << endl;
	//	cout << endl;

	//	h.Print();

	//	h.Insert(Item{ "tomato", 4 });

	//	h.Print(); 

	//	cout << "apple " << h.Get("apple") << endl;
	//	cout << "orange " << h.Get("orange") << endl;
	//	cout << "pineapple " << h.Get("pineapple") << endl;
	//	cout << endl;
	//}

	return 0;
}