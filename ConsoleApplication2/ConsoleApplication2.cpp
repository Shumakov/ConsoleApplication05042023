#include <iostream> 
#include "MyArray.h"
#include "Money.h"
#include "Point.h"
#include "Point2D.h"
#include "Test.h"

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
	MyArray a ( s );
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

template <class T>
void print(T t) {
	cout << t << endl;
}

void print(double t) {

	cout << "C = " << (int)t << endl;
	cout << "D = " <<t -  (int)t << endl;

}





template <class T>
class Array {

	T* arr{};
	unsigned int size{};
public:
	Array(const Array&) = delete;
	Array operator= (const Array&) = delete;

	Array(unsigned  int size) : size{ size } {
		arr = new T[size]{};
	}

	T* begin() { return arr; }
	T* end() { return arr + size; }

	Array(const std::initializer_list<T>& list) : Array(list.size()) {
		int i{};

		auto el = list.begin();

		//for (auto& el: list){
		for (; i < list.size(); i++, ++el) {
			arr[i] = *el;
		}
	}



	~Array() {
		delete[] arr;
	}

	int search(T) const;



	friend std::ostream& operator<<<> (std::ostream& o, const Array<T>& m);
	/*{
			for (unsigned int i{}; i < m.size; ++i)
				 o << m.arr[i] << " ";
		 return o;
	 }*/


	int operator[] (int i) const {
		return 0;
	}
};




int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	/*print(2);
	print(2.56);
	print('D');
	print("test");
	print("test 3");*/


	Point_v1<int> p1(1, 1);
	Point_v1<double> p2(1.45, 1.67);

	cout << "P1 = " << p1 << "  P2 = " << p2 << endl;
	return 0;

	
	Test<int> t_int{ 12 };

	Test<double> t_double{ 11.77 };

	Test<string> t_str{ "Test" };
	Test<string> t_str1{ "Test" };


	Test<Test<int>> t_test{ Test{10} };

	//t_test += t_int;


	//t_double+= t_int;

	t_str += t_str1;


	cout << t_str.get() << endl;




	//cout << t.get() << endl;

	////t.calculate(2);
	////cout << t.get() << endl;


	//Test<double> t1( 12.56 );
	//cout << t1.get() << endl;

	//t += tt;

	//t += t1;

	//cout << t.get() << endl;

	////Test<string> t2("sdfdsfdsfkldsfkldfsds");
	////cout << t2.get() << endl;

	return 0;
	
	MyArray a1{1,2,3,4,5,6,7,9};

	cout << a1 << endl;
	
	
	for (auto& el : a1) {

		cout << el << endl;
	}
	

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




