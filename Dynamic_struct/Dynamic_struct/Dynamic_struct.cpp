#include <iostream>

using namespace std;


class Stack {
	//Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 5 };

	//Массив для хранения данных
	char st[FULL + 1];

	//индекс определяющий вершину стека
	int top;

public:
	//Конструктор
	Stack();

	//Добавление элемента
	void push(char c);

	//Извлечение элемента
	char pop(bool isPop = true);

	//Очистка стека
	void clear();

	//Проверка существования элементов в стеке
	bool isEmpty();

	//Проверка на переполнение стека
	bool isFull();

	//Количество элементов в стеке
	int getCount();

	void show() {
		for (int i{ top }; i != EMPTY; i--)
			cout << st[i] << " ";
		cout << endl;
	}
};

Stack::Stack() {
	//Изначально стек пуст
	top = EMPTY;
}

void Stack::clear() {

	//Эффективная "очистка" стека
	//(данные в массиве все еще существуют,
	//но функции класса, ориентированные
	//на работу с вершиной стека,
	//будут их игнорировать)
	top = EMPTY;
}

bool Stack::isEmpty() {
	//Пуст?
	return top == EMPTY;

}

bool Stack::isFull() {
	//Полон?
	return top == FULL;
}

int Stack::getCount() {
	//Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::push(char c) {
	//Если в стеке есть место, то увеличиваем указатель
	//на вершину стека и вставляем новый элемент
	if (!isFull())
		st[++top] = c;
}

char Stack::pop(bool isPop) {
	//Если в стеке есть элементы, то возвращаем
	//верхний и уменьшаем указатель на вершину стека
	if (!isEmpty())
		if (isPop)
			return st[top--];
		else
			return st[top];
	else //Если в стеке элементов нет
		return 0;
}


int main_stack(){

	srand(time(0));

	Stack ST;
	char c;
	//пока стек не заполнится
	while (!ST.isFull()) {
		c = rand() % 20 + 48;
		cout << c << " ";
		ST.push(c);
	}

	cout << endl;
	//ST.push('a');
	//пока стек не освободится

	while (c = ST.pop()) {
		cout << c << " ";
	}
	cout << "\n\n";

    return 0;
}



class Queue {

	//Очередь
	int* Wait;

	//Максимальный размер очереди
	int MaxQueueLength;

	//Текущий размер очереди
	int QueueLength;

public:

	//Конструктор
	Queue(int m);

	//Деструктор
	~Queue();

	//Добавление элемента
	void add(int c);

	//Извлечение элемента
	int extract();

	//Очистка очереди
	void clear();

	//Проверка существования элементов в очереди
	bool isEmpty();

	//Проверка на переполнение очереди
	bool isFull();

	//Количество элементов в очереди
	int getCount();

	//демонстрация очереди
	void show();
};

void Queue::show() {

	cout << "\n-----------------------------------\n";

	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}

Queue::~Queue() {
	//удаление очереди
	delete[]Wait;
}

Queue::Queue(int m) {
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//Изначально очередь пуста
	QueueLength = 0;
}

void Queue::clear() {
	//Эффективная "очистка" очереди
	QueueLength = 0;
}

bool Queue::isEmpty() {
	//Пуст?
	return QueueLength == 0;
}

bool Queue::isFull() {
	//Полон?
	return QueueLength == MaxQueueLength;
}

int Queue::getCount() {
	//Количество присутствующих в стеке элементов
	return QueueLength;
}

void Queue::add(int c) {
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!isFull())
		Wait[QueueLength++] = c;
}

int Queue::extract() {
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!isEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		QueueLength--;
		//вернуть первый(нулевой)
		return temp;
	}
	else //Если в очереди элементов нет
		return -1;
}

int main_queue(){


	srand(time(0));
	//создание очереди
	Queue QU(25);
	//заполнение части элементов
	for (int i = 0; i < 5; i++) {
		QU.add(rand() % 50);
	}

	//показ очереди
	QU.show();

	cout << endl;

	//извлечение элемента
	cout << QU.extract() << endl;

	cout << endl;
	//показ очереди
	cout << endl;
	QU.show();
	cout << endl;


	return 0;
}

/*
Определите правильность расстановки скобок в арифметическом
выражении.Возможно использование  квадратные скобки[]
*/
bool check(const char* str) {
	Stack st;
	for (int i{}; str[i] != '\0'; ++i) {
		if (str[i] == '[')
			st.push(str[i]);
		if (str[i] == ']')
			if (st.pop() == 0)
				return false;
	}
	return st.isEmpty();
}

/*
Определите правильность расстановки скобок в арифметическом выражении. 
Возможно использование скобок трех типов: круглые скобки (), квадратные скобки [] и фигурные скобки {}
*/

bool check_v2(const char* str) {
	Stack st;

	const unsigned int count{ 4 };
	char open_ch[count]{ '[','{','(','/'};
	char close_ch[count]{ ']','}',')', '\\'};

	for (int i{}; str[i] != '\0'; ++i) {
		for (int j{}; j < count; ++j) {

			if (open_ch[j] == str[i])
				st.push(str[i]);

			if (close_ch[j] == str[i]) {
				char ch = st.pop();
				if (ch == 0 || ch != open_ch[j])
					return false;
			}
		}
	}
	return st.isEmpty();
}

int main_tasck() {

	cout << check_v2("[1/2\\3{333(444)444}555]") << endl;


	return 0;
}



class point {
private:
	int x, y;
public:

	static int id;
	point(int X, int Y) :x{ X }, y{ Y } {}
	point() :point(0, 0) {}
	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	void setX(int X) {
		x = X;
	}

	void setY(int Y) {
		y = Y;
	}

	void show() const {
		cout << x << " " << y << endl;
	}
};
int point::id{ 0 };


class pointIteration {
private:
	point* value;
	pointIteration* nextIterator;
	pointIteration* prevIterator;
public:

	pointIteration(point* value) {
		this->value = value;
		nextIterator = nullptr;
		prevIterator = nullptr;
	}

	pointIteration() :pointIteration((point*)NULL) {}

	pointIteration(pointIteration* iterator) {
		this->value = new point(*iterator->getValue());
		this->nextIterator = NULL;
		this->prevIterator = NULL;
	}

	void insert_after(pointIteration* iterator) {

		iterator->prevIterator = this;
		iterator->nextIterator = nextIterator;

		if (nextIterator)
			nextIterator->prevIterator = iterator;

		nextIterator = iterator;

	}

	void insert_before(pointIteration* iterator) {

		iterator->nextIterator = this;
		iterator->prevIterator = prevIterator;


		if (prevIterator)
			prevIterator->nextIterator = iterator;

		prevIterator = iterator;

	}

	pointIteration* getNext() {
		return nextIterator;
	}

	pointIteration* getPrev() {
		return prevIterator;
	}

	const point* getValue() const {
		return value;
	}


	void setValue(point* p) {
		value = p;
	}

	void setNext(pointIteration* next) {
		nextIterator = next;
	}

	void setPrev(pointIteration* prev) {
		prevIterator = prev;
	}

	void show() const {
		value->show();
	}

	~pointIteration() {
		if (value) {
			delete value;
			value = NULL;
		}
		if (prevIterator)
			prevIterator->nextIterator = nextIterator;

		if (nextIterator)
			nextIterator->prevIterator = prevIterator;
	}
};


class myList {

private:
	pointIteration* firstPoint;
	pointIteration* endPoint;
public:


	myList() {
		firstPoint = NULL;
		endPoint = firstPoint;
	}


	myList(point* value) {
		firstPoint = new pointIteration(value);
		endPoint = firstPoint;
	}



	myList(myList* list) {
		pointIteration* start1 = NULL;
		pointIteration* start2 = list->Begin();

		while (start2) {
			pointIteration* tmp = new pointIteration(start2);
			start1 = tmp;
			start2 = start2->getNext();
			start1->setNext(new pointIteration(start2));
			start1 = start1->getNext();
			start1->setPrev(tmp);
		}
	}


	~myList() {
		pointIteration* start = firstPoint;
		while (start->getNext()) {
			start = start->getNext();
			delete start->getPrev();
		}
		delete endPoint;
	}

	void pop_back() {
		if (endPoint) {
			pointIteration* tmp = endPoint->getPrev();
			delete endPoint;
			endPoint = tmp;
		}
		else {
			firstPoint = NULL;
		}
	}

	void push_back(point* value) {

		pointIteration* newEnd = new pointIteration(value);

		if (endPoint)
			endPoint->insert_after(newEnd);
		else
			firstPoint = newEnd;

		endPoint = newEnd;
	}

	void pop_front() {
		if (firstPoint) {
			pointIteration* tmp = firstPoint->getNext();
			delete firstPoint;
			firstPoint = tmp;
		}
		else {
			endPoint = NULL;
		}
	}


	void push_front(point* value) {
		pointIteration* newStart = new pointIteration(value);
		if (firstPoint)
			firstPoint->insert_before(newStart);
		else
			endPoint = newStart;

		firstPoint = newStart;
	}

	void show() const {
		pointIteration* start = firstPoint;
		int count = 0;
		while (start) {
			cout << "Point number " << ++count << endl;
			start->getValue()->show();
			start = start->getNext();
		}
		/*
			for(pointIteration* start = firstPoint; start; start = start->getNext()){
			 cout << "Point number " << ++count << endl;
			 start->getValue()->show();
			}
		*/
	}

	void show_rev() const {
		pointIteration* start = endPoint;
		int count = 0;
		while (start) {
			cout << "Point number " << ++count << endl;
			start->getValue()->show();
			start = start->getPrev();
		}
		/*
			for(pointIteration* start = firstPoint; start; start = start->getNext()){
			 cout << "Point number " << ++count << endl;
			 start->getValue()->show();
			}
		*/
	}

	void setFirst(pointIteration* start) {
		firstPoint = start;
	}
	void setEnd(pointIteration* end) {
		endPoint = end;
	}

	pointIteration* Begin() {
		return firstPoint;
	}

	pointIteration* End() {
		return endPoint;
	}
};


int main() {

	myList* my = new myList(new point(0, 0));
	float sum = 0;
	for (int i = 0; i < 10; ++i) {
		my->push_back(new point(i, i));
	}

	//my->show();

	auto node = my->Begin();

	for (int i = 0; i < 5; ++i) {
		node = node->getNext();
	}

	node->insert_before(new pointIteration(new point(100, 100)));

	my->show();

	cout << endl << endl;
	my->show_rev();

}