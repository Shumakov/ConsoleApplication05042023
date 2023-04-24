#include <iostream> 
#include "MyArray.h"
#include "Money.h"
#include "Point.h"
using namespace std;

void print(const MyArray& a) {
	a.print();
}

MyArray getArr(unsigned int s) {
	cout << "MyArray getArr(unsigned int s)" << endl;
	MyArray a{ s };
	a.gen();
	return a;
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

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

	MyArray arr1{ 3 };
	MyArray arr2{ 4 };

	arr1.set(0, 1);
	arr1.set(1, 2);
	arr1.set(2, 3);

	arr2.set(0, 4);
	arr2.set(1, 5);
	arr2.set(2, 6);
	arr2.set(3, 7);

	//MyArray arr3 = arr1 + arr2;

	//arr1 = arr1 + arr2;
	arr1 += arr2;

	cout << arr1 << endl;
	cout << arr2 << endl;
	

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




