#include <iostream>
#include <cassert>
#include "MyArray.h"

void test() {
	std::cout << "Message from test " << std::endl;
}

//  ����������� � ����������� ������������������ ������
MyArray::MyArray(unsigned int size) :size{ size }, mass{ new int[size] {} }{
	std::cout << "Create Array  = " << this << std::endl;
}


//  ����������� �����������
MyArray::MyArray(const MyArray& a) :size{ a.size } {
	std::cout << "Create Array (COPY)  = " << this << std::endl;

	// �������� ��������� ����������� ������ �� ������� ����������
	mass = new int[size] {};
	for (int i{}; i < size; i++)
		mass[i] = a.mass[i];
}


//  ����������� �����������
MyArray::MyArray(MyArray&& a):size{ a.size } {
	std::cout << "Create Array (MOVE)  = " << this << std::endl;
	// ��������� ��������� �� ������������ ������
	mass = a.mass;
	// �������� ��������� ����������� ������� �� ������������ ������
	a.mass = nullptr;
}



//  ����������
MyArray::~MyArray() {
	std::cout << "Delete Array  = " << this << std::endl;
	//  ������������ ������
	delete[] mass;
}

void MyArray::gen() {
	for (unsigned int i{}; i < size; ++i)
		mass[i] = rand() % 101;
}
void MyArray::print() const {
	for (unsigned int i{}; i < size; ++i)
		std::cout << mass[i] << " ";
	std::cout << std::endl;
}

std::ostream& operator<< (std::ostream& o, const MyArray& m) {
	for (unsigned int i{}; i < m.size; ++i)
		o << m.mass[i] << " ";	
	return o;
}

int MyArray::search(int key) const {
	for (int i{}; i < size; ++i)
		if (mass[i] == key)
			return i;
	return -1;
}

void MyArray::set(unsigned int ind, int value) {
	if (ind < size)
		mass[ind] = value;
}

int MyArray::get(unsigned int ind) {
	if (ind >= size)
		return -1;
	return mass[ind];
}

int MyArray::operator[] (unsigned int ind) const {
	if (ind >= size)
		return -1;
	return mass[ind];
}

int& MyArray::operator[] (unsigned int ind){	
	// ��������� �� ������ ������ ���������
	// ������� � ������� �� ������
	assert(ind < size && "Error, index very big");
	return mass[ind];
}

/*
// ���������� �������� �������, �������������� ������ �������� �������
MyArray operator+ (const MyArray& a, const MyArray& b) {
	unsigned int size = std::max(a.size,b.size) ;	
	
	MyArray arr{ size };

	for (int i{}; i < size; ++i) {
		if (i < a.size)
			arr.mass[i] += a.mass[i];
		if (i < b.size)
			arr.mass[i] += b.mass[i];
	}

	return arr;		
}
*/

// ������������ ���� ��������
MyArray operator+ (const MyArray& a, const MyArray& b) {
	
	//  ������� ����� ���������, ������ �����
	//  ����� �������� ������������ �����������
	MyArray arr{ a.size + b.size };

	
	int j{};
	
	// ����������� ������ �� ������ ��������
	for (int i{}; i < a.size; ++i,++j) 
		arr.mass[j] = a.mass[i];

	// ����������� ������ �� ������� ��������
	for (int i{}; i < b.size; ++i, ++j)
		arr.mass[j] = b.mass[i];
	
	return arr;
}

//  �������� ����������� ��������
MyArray& MyArray::operator+= (const MyArray& b) {

	// ������� ����� ������ ������ , ������ �����
	//  ����� �������� ������������ �����������
	int* m = new int[size + b.size]{};

	int j{};
	// ����������� ������ �� ������ ��������
	for (int i{}; i < size; ++i, ++j)
		m[j] = mass[i];

	// ����������� ������ �� ������� ��������
	for (int i{}; i < b.size; ++i, ++j)
		m[j] = b.mass[i];

	//  ����������� ����� ��������� ������
	delete[] mass;

	//  ��������� ����� ������ ������� ������
	size += b.size;
	 // ��������� ��� ������
	mass = m;
	return *this;
}



MyArray operator+ (const MyArray& a, int b) {	
	MyArray arr{ a.size };
	for (int i{}; i < a.size; ++i)
		arr.mass[i] += a.mass[i]+b;	
	return arr;
}

int operator+ (int a, const MyArray& b) {

	int res = a;
	for (int i{}; i < b.size; ++i)
		res += b.mass[i];

	return res;

}

bool operator== (const MyArray& a, const MyArray& b) {

	if (a.size != b.size)
		return false;
	for (int i{}; i < a.size; ++i)
		if (a.mass[i] != b.mass[i])
			return false;
	return true;
}


//  �������� ������������� 
// ���������� ������ � �������
MyArray& MyArray::operator= (const MyArray& a) {

	std::cout << "operator= COPY" << std::endl;

	//  ��������� ������������� ������ ����
	if (this == &a)
		return *this;

	if (size != a.size) {
		//  ����������� ����� ��������� ������
		delete[] mass;
		//  ��������� ����� ������ ������� ������
		size = a.size;
		// ������� ����� ������ ������ 
		mass = new int[size];
	}

	// ����������� ������ �� ������� ��������
	for (int i{}; i < size; i++) {
		std::cout << "copy data" << std::endl;
		mass[i] = a.mass[i];
	}

	return *this;
}

//  �������� ������������� ������������� 

MyArray& MyArray::operator= (MyArray&& a) {

	std::cout << "operator= MOVE" << std::endl;

	//  ����������� ����� ��������� ������
	delete[] mass;	
	//  ��������� ����� ������ ������� ������
	size = a.size;
	// ������� ����� ������ ������ 
	mass = a.mass;
	a.mass = nullptr;
	
	return *this;
}


