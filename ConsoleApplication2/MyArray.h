#pragma once
// Пример класса

void test();

class MyArray{
	int* mass{};
	unsigned int size{};
public:
	explicit MyArray(unsigned int size = 10);
	MyArray(const MyArray& a);
	~MyArray();
	void gen();
	void print() const;
	int search(int key) const;
	void set(unsigned int ind, int value);

	unsigned int getSize() const {
		return size;
	}

	// Блок прототипов перегрузки операторов дружественными функциями
	friend std::ostream& operator<< (std::ostream& o, const MyArray& m);
	friend MyArray operator+ (const MyArray& a, const MyArray& b);
	friend MyArray operator+ (const MyArray& a, int b);
	friend int operator+ (int a, const MyArray& b );
	friend bool operator== (const MyArray& a, const MyArray& b);
	// Конец блока


	// Перегрузка операторов функциями-членами класса
	MyArray& operator= (const MyArray& a);
	MyArray& operator+= (const MyArray& b);

	//friend std::istream& operator>> (std::istream& o, MyArray& m);
};

