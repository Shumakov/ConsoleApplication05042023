#include <iostream> 
#include "MyArray.h"
#include "Money.h"
#include "Point.h"
using namespace std;

void print(const MyArray& a) {
	a.print();
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	Money a,b;

	cout << "Enter rub/cent:";
	cin >> a;
	cout << "Enter rub/cent:";
	cin >> b;
	cout << a << endl;
	cout << b << endl;

	return 0;

	/*MyArray a{ 10 };
	a.gen();
	print(a);*/


	Money a1{ 1,5 };
	Money a2{ 2,10 };
	Money a3 = a1 + a2;
	/*a1.print();
	a2.print();
	a3.print();


	(a1++).print();
	a1.print();

	(a1--).print();
	a1.print();*/

	cout << a1<< " Rubl" << endl;

	/*a3 += a2;
	a3.print();

	++a3;
	cout << "++a3 = ";
	a3.print();
	(++a3).print();


	--a3;
	cout << "--a3 = ";
	a3.print();
	(--a3).print();*/

/*
	test();

	MyArray	a;
	a.gen();
	a.print();
	*/


	/*
	Point p;

	Money m1{ 10,33 };
	Money m2{ 11,48 };
	Money m3;

	m1.print();
	m2.print();


	cout <<"if (m1 == m2) " << m1.equals(m2) << endl; 
	cout << "if (m1 > m2) " << m1.gt(m2) << endl;
	cout << "if (m1 < m2) " << m1.lt(m2) << endl;

	Money m3 = m1;
	m1.print();
	m3.print();
	cout << "if (m1 == m3) " << m1.equals(m3) << endl;

	m1.plus(1, 1);
	m1.print();
	m1.plus(0, 99);
	m1.print();
	m1.minus(0, 99);
	m1.print();

	m1.plus(m2); // m1 += m2 // m1 = m1+ m2
	//m1 += m2;
	m1.print();

	int a = 10;
	int b = 45;

	a += b; // a =a+b


	*/
	return 0;	
}


/*

Класс Деньги для работы с денежными суммами.
Число должно быть представлено двумя полями:
типа long для рублей и типа 
unsigned char - для копеек. 
Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой.
Реализовать 
сложение, 
вычитание, 
деление сумм, 
деление суммы на дробное число, 
умножение на дробное число 
и операции сравнения.
В функции main проверить эти методы.
*/




