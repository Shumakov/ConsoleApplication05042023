#include <iostream> 
#include <string>
#include "MyArray.h"
#include "Money.h"
#include "Point.h"
#include "Point2D.h"
#include "Test.h"

#include <stdarg.h>

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
		
	~Array() {
		delete[] arr;
	}
	friend std::ostream& operator<< (std::ostream& o, const Array<T>& m)
	{
			for (unsigned int i{}; i < m.size; ++i)
				 o << m.arr[i] << " ";
		 return o;
	 }
};



template <>
class Array<double> {

	double* arr{};
	unsigned int size{};
public:
	Array(const Array&) = delete;
	Array operator= (const Array&) = delete;

	Array(unsigned  int size) : size{ size } {
		arr = new double[size]{};
	}

	double* begin() { return arr; }
	double* end() { return arr + size; }

	~Array() {
		delete[] arr;
	}
	friend std::ostream& operator<< (std::ostream& o, const Array<double>& m)
	{
		for (unsigned int i{}; i < m.size; ++i)
			o <<"D=" << m.arr[i] << " ";
		return o;
	}


	void message() {

		cout << "Специализация шаблона для double" << endl;
	}

};


/* 15.05.2023 non- type параметры шаблона*/


template <class T, int SIZE>
class Array_v1 {
	T mass[SIZE]{};

public:

	friend std::ostream& operator<< (std::ostream& o, const Array_v1& a) {
		
		for (auto& el : a.mass)
			o << el << "  ";

		return o;
	}

};



/*Работа с функциями, с переменным количеством аргументов*/
/* Для работы этого примера необходимо подключить библиотеку stdarg.h */


/*
	va_start задает указатель arg_ptr на первый необязательный аргументу в списке аргументов,
	который передан функции. Аргумент arg_ptr должен иметь тип va_list.
	Аргумент prev_param — это имя обязательного параметра, который непосредственно предшествует
	первому необязательному аргументу в списке аргументов.
	Если параметр prev_param объявлен в классе регистрового хранения, поведение макроса не определено.
	 va_start необходимо использовать до первого использования va_arg.



	va_arg извлекает значение type из расположения, которое задано параметром arg_ptr,
	и увеличивает значение указателя arg_ptr, чтобы он указывал на следующий аргумент в списке,
	используя размер type для определения места начала следующего аргумента.
	va_arg можно использовать в функции любое количество раз, чтобы получить аргументы из списка.


	После получения va_end всех аргументов сбрасывает указатель на NULL.
	va_end должен вызываться для каждого списка аргументов,
	который инициализируется va_start или va_copy, до выполнения возврата функцией.
*/



void testit(int count, ...) {
	va_list argptr;
	va_start(argptr, count);

	for (int i{}; i < count; ++i) {
		int n = va_arg(argptr, int);
		cout << n << "   ";
	}
	va_end(argptr);
}


/*
void print_arg() {
	cout << endl;
}

*/


template <typename T>
void print_arg(const T& t) {
	cout << t << endl;
}


template <typename First, typename... Rest>
void print_arg(const First& first, const Rest&... rest) {
	cout << first << ", ";
	print_arg(rest...); // recursive call using pack expansion syntax
}



int main_template() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));


	//print_arg(10, 20);
	//print_arg(100, 200, 300);
	print_arg("first", 2, "third", 3.14159);



	/*testit(5, 1, 2, 3, 4, 5);
	cout << endl;
	testit(15, 1, 2, 3, 4, 5,6,7,8,9,0,1,2,3,4,5);
	cout << endl;*/

	/*Array_v1<int,10> a;
	Array_v1<bool,20> b;

	cout << a << endl;

	cout << b << endl;*/


	/*Array<int> a(10);
	Array<double> d(10);

	cout << a << endl;
	cout << d << endl;

	d.message();*/


	/*Point_v1<int, double> p(1, 6.78);

	Point_v1<double, int> p1(1.455444, 6);

	cout << p << endl;
	cout << p1 << endl;*/

	return 0;	
}



// Работа со строками, набор разных функций
int main_string() {

    std::cout << "Stirngs" << endl << endl;

    //            01234567890123456789
    //string text{ "this is a c++ string" };
    //char carr[10]{ 0 };
    //text.copy(carr, 8, 5);
    //cout << " " << carr << endl;

    //cout << " " << text.substr(5, 9) << endl;
    //cout << " " << text.substr(5) << endl;
    //cout << " " << text << endl;

    //if (str.empty())
    //{
    //    cout << "No content" << endl;
    //}

    string piIs = "Pi is " + to_string(3.1415926);
    cout << " " << piIs << endl;

    /*string orbits("365.24 29.53");
    unsigned int sz;

    double earthTurn = stod(orbits, &sz);
    double moonTurn = stod(orbits.substr(sz));
    cout << "  The moon completes " << (earthTurn / moonTurn) << " orbits per Earth year" << endl;

    *///string text1{ "129" };
    //unsigned int number1 = stoul(text1);
    //unsigned long number1 = stoul(text1);
    //cout << " " << number1 << endl;
    //


   /*
    string text2{ "124,8" };
    int number2 = stoi(text2);
    cout << " " << number2 << endl;
    */

    //string text3{ "1248" };
    //int number3 = stoi(text3, &pos, 8);
    //cout << " " << number3 << endl;
    //cout << " " << pos << endl;

    //string text{ "this is a c++ string" };
    //string str{ "abcdef" };
    //string none;
    //cout << " " << text.length() << endl;
    //cout << " " << text.size() << endl;
    //cout << " " << text.capacity() << endl;
    //cout << " " << text.max_size() << endl;

    ////cout << " " << str.length() << endl;
    ////cout << " " << str.capacity() << endl;
    ////cout << " " << str.max_size() << endl;

    //cout << " " << none.length() << endl;
    //cout << " " << none.capacity() << endl;




    //text.reserve(8);
    //cout << text << endl;
    //cout << " " << text.capacity() << endl;

    //text.shrink_to_fit();
    //cout << " " << text.capacity() << endl;


    /*string txt = text;
    txt.replace(10, 3, str); 
    cout << " " << txt << endl;*/

    //txt = text;
    //txt.replace(10, 3, str, 2, 2);
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(10, 3, "new");
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(10, 3, "1234", 1, 2);
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(10, 3, 3, '!');
    //cout << " " << txt << endl;

    //txt = text;
    //txt.replace(txt.begin() + 10, txt.end() - 7, str);
    //cout << " " << txt << endl;

    //for (auto it = text.begin(); it < text.end(); it++)
    //{
    //    if (!isalpha(*it) && !isspace(*it))
    //    {
    //        cout << *it;
    //    }
    //}
    //cout << endl;

    /*text.push_back('F');

    cout << text << endl;

    text.pop_back();

    cout << text << endl;

    string theStr{ "abcdef" };

    string str = text;
    cout << " " <<str.insert(5, theStr) << endl;*/

    //str.

    //str = text;
    //cout << " " << str.insert(5, theStr, 2, 3) << endl;

    //str = text;
    //str.insert(str.begin() + 2, 'A');
    //cout << " " << str << endl;

    //cout << " " << text.assign(str, 3, 4) << endl;
    //cout << " " << text.assign("abcdef") << endl;
    //cout << " " << text.assign("abcdef", 2) << endl;
    //cout << " " << text.assign(5, 'a') << endl;
    //cout << " " << text << endl;
    // 
    // 

    string text{ "this is a c++ string" };
    cout << " " << text << endl;

    //cout << " " << text.find_first_not_of("abcdefghijklmnopqrstuvwxyz ") << endl;
    //cout << " " << text.find_last_of("bac") << endl;

    cout << " " << text.find("c++!") << endl;

    //cout << " " << text.find("is", 4) << endl;
    //cout << " " << text.rfind("is") << endl;
    //cout << " " << text.rfind("is", 4) << endl;
    //cout << " " << text.find("strong", 0, 3) << endl;
    //cout << " " << text.find("strong") << endl;

    //char stringC[]{ 'a', 'b', 'c', '\0', 'c', 'b', 'a' };
    //string stringCPP{ 'a', 'b', 'c', '\0', 'c', 'b', 'a'};

    //cout << "  |" << stringC << "|" << endl;
    //cout << "  |" << stringCPP << "|" << endl;

    //string s1;
    //string s2;
    //string s3;

    //s1 = "abc";
    //s2 = { 'x', 'y', 'z'};
    //s3 = s1;

    //cout << " " << s1 << " " << s2 << " " << s3 << endl;
    //cout << " " << (s1 == s2) << " " << (s1 != s2) << " " << (s1 < s2) << " " << (s1 >= s2) << endl;
    //cout << " " << s1 + s2 << endl;
    //s2 += s1;
    //cout << " " << s2 << endl;

    //s1.at();

    //char     ch{ 'a' };  
    //char8_t  ch8{ u8'a' };  //  òðåáóåòñÿ âåðñèÿ C++ 20
    //char16_t ch16{ u'a' };
    //char32_t ch32{ U'a' };
    //wchar_t  chw{ L'a' };   // íåñòàíäàðòíûé òèï êîìïèëÿòîðà Microsoft

    //cout << ch << endl;
    //cout << ch8 << endl;
    //cout << ch16 << endl;
    //cout << ch32 << endl;
    //wcout << chw << endl;
    //ch = 127;
    //cout << ch << endl;

    //char text[20]{ "This a c-string" };
    //char text1[20]{ "This a string" };
    /*std::string text{ "This is a c++ string" };
    std::string aString;
    std::cout << text << endl;*/

    //string text{ "Hello" }; // ñòðîêà èç const char*
    //string text{ "Hello" };
    //cout << text;



/*
    string text;
    getline(cin, text);
    cout << text << endl;
    */



    //getline(cin, text, '*');
    //cout << text << endl;


    //string name0(8, 'a');  // ñòðîêà èç 8 'a' ñèìâîëîâ
    //string name( 8, 'a' );  // ñòðîêà èç 8 'a' ñèìâîëîâ
    //string name1(8, 'a');  // ñòðîêà èç 8 'a' ñèìâîëîâ
    //string name{ "1a2b3c4d5a" };
    //name.find()
    //const char* pname = name.data();
    //char& beg = name.front();
    //char& fin = name.back();
    //char c1 = name[10];
    //char c2 = name.at(10);
    //cout << c2 << endl;
    //string month = "March"; // òî æå, ÷òî string month{"March"};

    //cout << text.size();
    //int len = name.length();

    //cout << name << endl;
    //char ch = name[3];
    //cout << ch << endl;
    //for (int i = 0; i < name.length(); i++)
    //{
    //    cout << name[i];
    //}
    //cout << endl;
    //for (auto c : name)
    //{
    //    cout << c;
    //}
    //cout << endl;

    return 0;
}



class Knife {

    string type;

public:
    void use() {
        cout << type << " -----  Вжик" << endl;
    }

    const string& getType() const {
        return type;
    }

    void setType(const string& str) {
        type = str;
    }
};
class Gun {

    string type;
    int count{ 30 };

public:
    void use() {
        cout << type << " -----  Бах  " << count << endl;
        --count;
    }

    const string& getType() const {
        return type;
    }

    void setType(const string& str) {
        type = str;
    }



};
class Grenade {
public:
    void use() {
        cout << "Ба-Бах" << endl;
    }
};
class machineGun {

public:
    void use() {
        cout << "Бах- Бах - Бах" << endl;
    }
};

// Шаблон
template <class T, int SIZE>
class webGear {
    T content[SIZE];
public:
    void use() {
        for (auto& unit : content)
            unit.use();
    }

    T& operator[] (unsigned int i) {
        if (i > SIZE)
            return content[0];
        return content[i];
    }

    T operator[] (unsigned int i)const {
        if (i > SIZE)
            return content[0];
        return content[i];
    }

    int getSize() const {
        return SIZE;
    }
};






int main() {

    setlocale(LC_ALL, "Rus");
    
    webGear<Knife, 10> wk;
    for (int i{}; i < wk.getSize(); ++i)
        wk[i].setType("TYPE" + to_string(i));

    wk.use();

    webGear<Gun, 10> guns;
    for (int i{}; i < guns.getSize(); ++i)
        guns[i].setType("TYPE GUN" + to_string(i));

    guns.use();
    guns.use();
    guns.use();
    guns.use();
    guns.use();

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




