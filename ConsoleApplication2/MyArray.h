#pragma once
#include <initializer_list>

// ������ ������

void test();

// �����-������� ��� �������� ������������� ����������
// ������������ ���� � ��������� ������ 
class MyArray{
	int* mass{}; // ������
	unsigned int size{}; //  ������ �������
public:

	// �����������, ����  ��� �������� ���������� �� ���������� ����������
	// �� ����� ������ ������ �� 10 ��������� � ����� ����������� �������� ���
	//  ����������� ������������ �� ���������
	explicit MyArray(unsigned int size = 10);


	MyArray(const std::initializer_list<int>& list);

	// ��� ����������� ������ � ����� �������� � ������� for each �����
	// ����� ��� ������ begin () end()
	int* begin() { return mass; }
	int* end() { return mass+size; }

	// ����������� ����������� �.�. � ������ ������������ ������ � ������������ �������
	//  �� ���������� ���������� ����� ������������ � ���������� ��������� �����������
	MyArray(const MyArray& a);

	// ����������� �����������, ���������� ��� ����������� ��������� ��������
	// � ��� ����������� �������� ������������
	MyArray(MyArray&& a);

	// ����������
	~MyArray();

	//  �������-����� ��� �������� ������ �����������. ����� ������� ������
	// �������� � �� ����������������
	void gen();
	void print() const;
	int search(int key) const;
	void set(unsigned int ind, int value);
	int get(unsigned int ind);

	unsigned int getSize() const {
		return size;
	}

	// ���� ���������� ���������� ���������� �������������� ���������

	//  ���������� ��������� ��� ������ � ����������� ������� ������
	// ���������� ������ �� ����� ��� ����������� ����������� ������� �������
	friend std::ostream& operator<< (std::ostream& o, const MyArray& m);

	// ���������� ��������� +, ��� �������� ���������� ������ ������
	// ���������� ����� �������
	friend MyArray operator+ (const MyArray& a, const MyArray& b);
	// MyArray operator+ (const MyArray& b);


	// ���������� ��������� +, ����� ������� -  ��������� ������ ������
	// ������ ������� - ������������� ����������
	// ���������� ����� �������
	friend MyArray operator+ (const MyArray& a, int b);

	// ���������� ��������� +, ����� ������� = ������������� ����������,
	// ������ ������� - ��������� ������ ������
	// ���������� ������������� ����������
	friend int operator+ (int a, const MyArray& b );

	//  �������� ==, ���������� ��� ���������� ������ ������ �� ������ �� ������������
	// ���������� ���������� ����������
	friend bool operator== (const MyArray& a, const MyArray& b);
	// ����� ����� ���������� ���������� ���������� �������������� ���������


	// ���������� ���������� ���������-������� ������
	// ����=��������� �������� ��, ��� �� ����������� ����� �������
	// �� ������������� ����� ������� �� this

	// �������� = (����������� �������������)
	// ���������� ���������� ��=�� ����, ��� � ������ �������
	// ������ � ������������ �������
	MyArray& operator= (const MyArray& a);

	// �������� = (������������� �������������)	
	// �� ���������� ��������� �����������
	MyArray& operator= (MyArray&& a);

	// �������� += (����������� ��������)
	MyArray& operator+= (const MyArray& b);

	int operator[] (unsigned int) const;
	int& operator[] (unsigned int);

	//friend std::istream& operator>> (std::istream& o, MyArray& m);
};

