#include <iostream>
#include "MyArray.h"

void test() {
	std::cout << "Message from test " << std::endl;
}

MyArray::MyArray(unsigned int size) :size{ size }, mass{ new int[size]  }{
	std::cout << "Create Array  = " << this << std::endl;
}

MyArray::MyArray(const MyArray& a) :size{ a.size } {
	std::cout << "Create Array (COPY)  = " << this << std::endl;
	mass = new int[size] {};
	for (int i{}; i < size; i++)
		mass[i] = a.mass[i];
}

MyArray::~MyArray() {
	std::cout << "Delete Array  = " << this << std::endl;
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

