#include <iostream>
#include "MyArray.h"

void test() {
	std::cout << "Message from test " << std::endl;
}

//  Конструктор с применением инициализационного спаска
MyArray::MyArray(unsigned int size) :size{ size }, mass{ new int[size] {} }{
	std::cout << "Create Array  = " << this << std::endl;
}


//  Конструктор копирования
MyArray::MyArray(const MyArray& a) :size{ a.size } {
	std::cout << "Create Array (COPY)  = " << this << std::endl;

	// Механизм глубокого копирования данных из второго экземпляра
	mass = new int[size] {};
	for (int i{}; i < size; i++)
		mass[i] = a.mass[i];
}


//  Деструктор
MyArray::~MyArray() {
	std::cout << "Delete Array  = " << this << std::endl;
	//  Освобождение памяти
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

/*
// Складываем элементы массива, результирующий массив бОльшего размера
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

// Конкотенация двух массивов
MyArray operator+ (const MyArray& a, const MyArray& b) {
	
	//  Создаем новый экземпляр, размер равен
	//  сумме размеров складываемых экземпляров
	MyArray arr{ a.size + b.size };

	
	int j{};
	
	// Копирование данных из левого операнда
	for (int i{}; i < a.size; ++i,++j) 
		arr.mass[j] = a.mass[i];

	// Копирование данных из правого операнда
	for (int i{}; i < b.size; ++i, ++j)
		arr.mass[j] = b.mass[i];
	
	return arr;
}

//  Оператор сокращенное сложение
MyArray& MyArray::operator+= (const MyArray& b) {

	// Создаем новый массив данных , размер равен
	//  сумме размеров складываемых экземпляров
	int* m = new int[size + b.size]{};

	int j{};
	// Копирование данных из левого операнда
	for (int i{}; i < size; ++i, ++j)
		m[j] = mass[i];

	// Копирование данных из правого операнда
	for (int i{}; i < b.size; ++i, ++j)
		m[j] = b.mass[i];

	//  Освобождаем ранее выделеную память
	delete[] mass;

	//  Сохраняем новый размер массива данных
	size += b.size;
	 // Сохраняем сам массив
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


//  Оператор приравнивания 
// Корректная работа с памятью
MyArray& MyArray::operator= (const MyArray& a) {

	std::cout << "operator=" << std::endl;

	//  Исключаем приравнивание сосмому себе
	if (this == &a)
		return *this;

	//  Освобождаем ранее выделеную память
	delete[] mass;

	//  Сохраняем новый размер массива данных
	size = a.size;

	// Создаем новый массив данных 
	mass = new int[size];

	// Копирование данных из правого операнда
	for (int i{}; i < size; i++)
		mass[i] = a.mass[i];

	return *this;
}


