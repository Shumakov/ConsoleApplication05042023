#pragma once
#include <iostream>


// Описание и определение шаблона класса

template <class T, class T2>
class Point_v1 {

	T x;
	T2 y;
public:	
	Point_v1(T x, T2 y) :x{ x }, y{ y } {}
	
	friend std::ostream& operator<< (std::ostream& o, const Point_v1& p) {
		o << "(" << p.x << "," << p.y << ")";
		return o;
	}

};


template <class T>
class Point_v1<T, double> {

	T x;
	double y;
public:
	Point_v1(T x, double y) :x{ x }, y{ y } {}

	friend std::ostream& operator<< (std::ostream& o, const Point_v1& p) {
		o << "(" << p.x << "," << p.y << ") - особенная";
		return o;
	}

};


// Описание и определение шаблона класса


template <class T>
class Test {
	T i{};
public:
	Test() = default;
	Test(T v) :i{ v } {}
	T get() const { return i; }
	void set(T v) { i = v; }
	void calculate(int v);

	Test& operator+= (const Test& t) {

		i += t.i;
		return *this;
	}


	//std::istream& operator<< (std::istream&, )
	
};



template <class T, class T2>
Test<T>& operator+= (Test<T>& t, const Test<T2>& t1) {
	T i = t.get();
	T2 i1 = t1.get();
	
	
	t.set(i + i1);

	return t;
}


// Определение функции члена шаблона класса 

template <class T>
void Test<T>::calculate(int v) {
	i *= v;
}