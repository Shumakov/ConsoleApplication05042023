#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout; 
using std::endl;

union Test {
	int a;
	char ch[4];
};


auto func(int a) {

	if (a > 0) {
		return 123.88;
	}
	else {
		return (double)33;
	}
}


int main() {

	Test t{};
	t.a = 111;	
	cout << t.a << endl;
	cout << (int)t.ch[0] << endl;
	cout << (int)t.ch[1] << endl;
	cout << (int)t.ch[2] << endl;
	cout << (int)t.ch[3] << endl;

	//https://learn.microsoft.com/ru-ru/cpp/cpp/auto-cpp?view=msvc-170
	auto var = 4/55;

	//https://learn.microsoft.com/ru-ru/cpp/cpp/decltype-cpp?view=msvc-170
	decltype (45.78 / 45) var1{6645.3434};

	cout << var1 << endl;



	// Созданиессылки с помощью decltype
	int temp = 123;
	int& l_temp = temp;
	cout << l_temp << endl;
	decltype (l_temp) decl_temp{temp};
	decl_temp = 333;
	cout << temp<< endl;
	auto auto_temp = l_temp;



	return 0;
}