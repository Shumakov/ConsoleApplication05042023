#include <iostream>
#include <cassert>
#include "MyArray.h"


// Консруктор позволяет создавать обьект с помощью унифицированного механизма списковой инициализации
//  std::initializer_list находится в библиотеке <initializer_list>
MyArray::MyArray(const std::initializer_list<int>& list) : MyArray(list.size()) {
	
	int i{};
	//for (; i < list.size(); i++, ++el) {
	//auto el = list.begin();

	//  for each цикл 
	for (auto& el: list){	
		mass[i] = el;
		++i;
	}
}


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


//  Конструктор перемещения
MyArray::MyArray(MyArray&& a):size{ a.size } {
	std::cout << "Create Array (MOVE)  = " << this << std::endl;
	// Сохранили указатель на динамическую память
	mass = a.mass;
	// Отвязали указатель переданного обьекта от динамической памяти
	a.mass = nullptr;
	a.size = 0;
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
	// Сообщение об ошибке работы программы
	// Условие в скобках не истина
	assert(ind < size && "Error, index very big");
	return mass[ind];
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
	MyArray arr( a.size + b.size );

	
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
// MyArray a1{10};
// MyArray a2{10};
// a1+=a2;
MyArray& MyArray::operator+= (/* MyArray* this, */  const MyArray& b) {
	// Создаем новый массив данных , размер равен
	//  сумме размеров складываемых экземпляров
	int* m = new int[size + b.size]{};
	int j{};
	// Копирование данных из левого операнда
	for (int i{}; i < size; ++i, ++j)
		m[j] = this->mass[i];
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
	MyArray arr( a.size );
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

	std::cout << "operator= COPY" << std::endl;

	//  Исключаем приравнивание самому себе
	if (this == &a)
		return *this;

	if (size != a.size) {
		//  Освобождаем ранее выделеную память
		delete[] mass;
		//  Сохраняем новый размер массива данных
		size = a.size;
		// Создаем новый массив данных 
		mass = new int[size];
	}

	// Копирование данных из правого операнда
	for (int i{}; i < size; i++) {
		std::cout << "copy data" << std::endl;
		mass[i] = a.mass[i];
	}

	return *this;
}

//  Оператор перемещающего приравнивания 

MyArray& MyArray::operator= (MyArray&& a) {

	std::cout << "operator= MOVE" << std::endl;

	//  Освобождаем ранее выделеную память
	delete[] mass;	
	//  Сохраняем новый размер массива данных
	size = a.size;
	// Создаем новый массив данных 
	mass = a.mass;
	a.mass = nullptr;
	
	return *this;
}


