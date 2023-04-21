#pragma once
// ������ ������

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
};

