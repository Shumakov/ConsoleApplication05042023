#include <iostream> 
using namespace std;


class Student {
	char name[255]{};
	unsigned int age{};
	int avMark{};

public:
	
	Student(const char* n) {
		cout << "Create class (2) Student " << n << endl;
		setName(n);
	}

	Student(const char* n, unsigned int a) {
		cout << "Create class Student " << n << endl;
		setName(n);
		setAge(a);
	}
	
	int getAge() {
		return age;
	}

	const char* getName() {
		return name;
	}

	void setName(const char* n) {
		strcpy_s(name,	255,n );		
	}

	void setAge(int a) {
		if (a <= 30)
			age = a;
		else
			age = 0;

	}
	void print() {
		cout << "Student " << name << ", age " << age << "." << endl;
		cout << " AV Mark = " << avMark << endl;
	}


private:
	int calculate();
};


int main() {

	setlocale(LC_ALL, "Rus");

	Student s1{ "Петров И И" , 25};
	Student s2{ "Шумаков К А" , 45 };
	Student s3{ "Иванов К А"};
	s1.print();
	s2.print();

	s2.setName("Шумаков-Иванов Ф А");
	s2.setAge(21);
	s2.print();

	s2.setAge(51);
	s2.print();

	return 0;
}

