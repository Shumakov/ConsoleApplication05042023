﻿#include <iostream> 
#include "MyArray.h"
#include "Money.h"
#include "Point.h"
#include "Point2D.h"

using namespace std;

/*
Операторы, которые перегружать нельзя:
?: (тернарный оператор);
:: (доступ к вложенным именам);
. (доступ к полям);
.* (доступ к полям по указателю);
sizeof, typeid и операторы каста.
*/

/*
Операторы, которые можно перегрузить только в качестве методов класса:
= (присваивание);
-> (доступ к полям по указателю);
() (вызов функции);
[] (доступ по индексу);
->* (доступ к указателю-на-поле по указателю);
операторы преобразования и управления памятью.
*/

/*
Оператор индексации (operator[]) должен иметь две версии перегрузки:
константную (константный метод)
не константную.
*/



/*
компилятор сгенерирует
■ конструктор по умолчанию,
■ конструктор копирования,
■ оператор копирующего присваивания,
■ конструктор перемещения,
■ оператор перемещающего присваивания,
■ деструктор.


НО!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

■ явное определение собственной версии произвольно-
го конструктора предотвращает автоматическую гене-
рацию компилятором конструктора по умолчанию;
■ явное определение конструктора перемещения или
оператора перемещающего присваивания предот-
вращает автоматическую генерацию компилятором
как конструктора копирования, так и оператора ко-
пирующего присваивания;
■ явное определение конструктора копирования, опе-
ратора копирующего присваивания, конструктора
перемещения, оператора перемещающего присваи-
вания или деструктора предотвращает автоматиче-
скую генерацию компилятором как конструктора
перемещения, так и оператора перемещающего при-
сваивания.

*/




void print(const MyArray& a) {
	a.print();
}

MyArray getArr(unsigned int s) {
	std::cout << "MyArray getArr(unsigned int s)" << endl;
	MyArray a{ s };
	a.gen();
	return a;
}


void func_counter() {
	static int a{};
	cout << a << endl;
	a++;

}


class Counter {
	int cnt;
public:
	Counter(int start=0) : cnt{ start } {};

	//Counter() : Counter(0) {};

	int operator()() { return ++cnt; }
	int operator()(int v) { return cnt += v; }
	int operator()(char v) {

		switch ( v)
		{
		case 'P':
			cnt += 4;
			break;
		case 'M':
			cnt -= 4;
			break;
		case 'Y':
			cnt *= 4;
			break;
		default:
			break;
		}
		
		return cnt; 
	}

	void resetTo(int start) { cnt = start; }
};

void useCntr() {

	const int maxCnt{ 5 };
	Counter cnt1{};
	Counter cnt2{ 100 };
	for (int i{ 0 }; i < maxCnt; ++i)
	{
		std::cout << "cnt1: " << cnt1() << '\n';
		std::cout << "cnt2: " << cnt2() << '\n';
	}
	std::cout << '\n';
	cnt1.resetTo(10);
	cnt2.resetTo(200);
	for (int i{ 0 }; i < maxCnt; ++i)
	{
		std::cout << "cnt1: " << cnt1() << '\n';
		std::cout << "cnt2: " << cnt2('Y') << '\n';
	}
	std::cout << '\n';
}


int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	//Point2D point_1;
	//Point2D point_2 = point_1;


	int a = 55;

	int& l = a;

	const int& l1 = (56 + 89);

	int&& l3 = (56 + 89);


	//useCntr();
/*
	func_counter();
	func_counter();
	func_counter();
	func_counter();
	func_counter();
	*/
	return 0;





	MyArray* a1 = new MyArray{10};
	a1->gen();
	MyArray* a2 = new MyArray{ std :: move( * a1)};
	
	delete a1;
		
	a2->print();


	delete a2;
	 
	return 0;



	Point2D p2d{ 1,1 };
	Point3D p3d{ 2,2,2 };

	cout << p2d.x << ", " << p2d.y << endl;
	cout << p3d.x << ", " << p3d.y << ", "<<p3d.z << endl;

	p2d = p3d;

	cout << p2d.x << ", " << p2d.y << endl;

	p3d = p2d;

	cout << p3d.x << ", " << p3d.y << ", " << p3d.z << endl;

	Money m{ 10,30 };

	cout << m.getRub() << endl;
	cout << (int)m.getCent() << endl;

	cout << m['R'] << endl;
	cout << m['c'] << endl;

	int r = (int)m;

	double d = m;

	cout <<"r = " << r << endl;
	cout << "d = " << d << endl;
		

/*
	// Целочисленная переменная
	int a = 33;
	//  Ссылка на переменную а (lvalue)
	int& b = a;

	// Ссылка на временный обьект (rvalue)
	const int& b1 = 56 + 89;

	// Ссылка на временный обьект (rvalue)
	int&& b2 = (33 + 56);

	cout << b1 << endl;
	*/


	/*
	MyArray arr{ 20 };
	arr = getArr(10);
	std::cout << arr << endl;

	std::cout << arr.get(0) << endl;
	std::cout << arr[0] << endl;
	arr.set(0, 100);
	arr[0] = 100;
	std::cout << arr << endl;
	*/
	


	//MyArray arr1{ 5 };
	//arr1.gen();
	////cout << arr1 << endl;
	//MyArray arr2{ 5 };
	//arr2.gen();
	//cout << arr2 << endl;
	//arr2 = arr2;
	//cout << arr2 << endl;

	//arr2 += arr1;


	//MyArray arr2{ getArr(10) };

	/*MyArray arr1{ 3 };
	MyArray arr2{ 4 };

	arr1.set(0, 1);
	arr1.set(1, 2);
	arr1.set(2, 3);

	arr2.set(0, 4);
	arr2.set(1, 5);
	arr2.set(2, 6);
	arr2.set(3, 7);*/

	//MyArray arr3 = arr1 + arr2;

	//arr1 = arr1 + arr2;
	/*arr1 += arr2;

	cout << arr1 << endl;
	cout << arr2 << endl;*/
	

	/*
	MyArray arr4{ 3 };
	MyArray arr5{ 3 };

	arr4.set(0, 1);
	arr4.set(1, 2);
	arr4.set(2, 3);

	arr5.set(0, 1);
	arr5.set(1, 2);
	arr5.set(2, 6);
	
	cout << "(arr4 == arr5)  " << (arr4 == arr5) << endl;*/

	/*MyArray arr4 = arr3 + 10;
	cout << arr4 << endl;

	cout << arr1 + 4 + arr4 << endl;*/

	//MyArray arr{ 10 };
	//arr.gen();
	////arr.print();

	//MyArray arr1{ 10 };
	//arr1.gen();
	//cout << arr <<" | "<< arr1 << endl;

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




