// queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;

class point {
private:
    int x, y;
public:
    point(int X, int Y) :x{ X }, y{ Y } {}
    point() :point(0, 0) {}
    int getX() const {
        return x;
    }

    int getY() const { return y; }
    void setX(int X) { x = X; }
    void setY(int Y) { y = Y; }
    void show() const {
        cout << '(' << x << ", " << y << ')' << endl;
    }

    friend ostream& operator<<(ostream& o, const point& p) {
        o << '(' << p.x << ", " << p.y << ')' << endl;
        return o;
    }
};


// Прототип шаблона класса список
template <class T>
class myListOne;

// Класс хранящий листик списка
template <class T>
class IteratorOne { 
    
    friend class myListOne<T>; // Дружественный класс , для доступа к полям в приватной секции

private:
    
    T* value;  // Данные
    IteratorOne<T>* nextIterator; // Указатель на следующий лит
public:

    //  Коструктор
    IteratorOne(T* value) {
        cout << "Create Iterator for point ";
        value->show();
        cout << endl;

        // Сохраняем данные и указатель на следующий лист = 0
        this->value = value;
        nextIterator = nullptr;
    }

    // Вставка  нового листа за текущим
    void insert(IteratorOne* iterator) {
        iterator->nextIterator = nextIterator; // Отдем свою связь новому листу
        nextIterator = iterator; //  Сохраняем адрес нового листа
    }

    // Удаление листа за текущим
    void del_next() {
        IteratorOne* temp = nextIterator; // Сохранили адрес листа
        nextIterator = nextIterator->nextIterator; // Сохранили адрес листа за удаляемым
        delete temp; // удалили исключенный лист
    }

    IteratorOne* getNext() {
        return nextIterator;
    }

    const T* getValue() const {
        return value;
    }

    void setValue(T* p) {
        value = p;
    }

    void show() const {
        //value->show();
        cout << value;
    }

    // Деструктор (работа с динамической памятью)
    ~IteratorOne() {
        cout << "Delete Iterator for point ";
        value->show();
        cout << endl;

        // Освобождаем память данных
        delete value;
    }
};


// Класс однонаправленный список
template <class T>
class myListOne {

private:

    IteratorOne<T>* head; // голова списка
    IteratorOne<T>* tail; // хвост списка

public:

    myListOne() {
        head = nullptr;
        tail = head;
    }

    myListOne(point* value) {
        head = new IteratorOne<T>(value);
        tail = head;
    }
    // Деструктор
    ~myListOne() {
        // Идем по листам  списка и удаляем каждый первый элемент
        while (head->nextIterator) {
            IteratorOne<T>* temp = head;
            head = temp->nextIterator;
            delete temp;
        }
        delete head;
    }


    // Удаление листа с конца
    void pop_back() {


        if (tail) { // список не пустой 
            if (tail != head) { // в списке больше, чем  1 лист
                IteratorOne<T>* prev = head;
                // Находм лист, предыдущий перед хвостом
                for (; prev->nextIterator != tail; prev = prev->nextIterator);
                delete tail; // удалили хвост
                tail = prev; // сохранили новый хвост
                tail->nextIterator = nullptr; // у хвоста указатель на следующий лист = 0
            }
            else { //  в списке 1 лист
                delete tail;
                tail = nullptr;
                head = nullptr;
            }

        }
    }

    void push_back(T* value) {

        IteratorOne<T>* newEnd = new IteratorOne<T>(value);

        // Добавляем элемент после хвоста
        if (tail)
            tail->insert(newEnd);
        else
            head = newEnd;

        tail = newEnd;
    }

    void pop_front() {
        if (head) {
            IteratorOne<T>* tmp = head->nextIterator;
            delete head;
            head = tmp;
        }
        if (!head) {
            tail = nullptr;
        }
    }


    void push_front(T* value) {
        IteratorOne<T>* newStart = new IteratorOne<T>(value);
        if (head)
            newStart->nextIterator = head;
        else
            tail = newStart;

        head = newStart;
    }

    void insert(T* value, int pos = 0) {

        if (pos == 0) {
            push_front(value);
            return;
        }

        if (!head) {
            push_back(value);
            return;
        }

        IteratorOne<T>* nI = new IteratorOne<T>(value);
        IteratorOne<T>* posI = head;
        for (int i{ 0 }; i < pos - 1 && posI->nextIterator; i++, posI = posI->nextIterator);

        posI->insert(nI);
    }

    void del(int pos = 0) {

        if (pos == 0) {
            pop_front();
            return;
        }
        if (!head)
            return;

        IteratorOne<T>* posI = head;
        for (int i{ 0 }; i < pos - 1 && posI->nextIterator; i++, posI = posI->nextIterator);

        if (posI == tail || posI->nextIterator == tail) {
            pop_back();
            return;
        }
        posI->del_next();
    }

    void show() const {
        IteratorOne<T>* start = head;
        while (start) {
            start->value->show();
            start = start->nextIterator;

        }
    }
    IteratorOne<T>* begin() {
        return head;
    }

    IteratorOne<T>* end() {
        return tail;
    }
};





// Лист для двунапрвленного списка
class Iterator {

    friend class myList;

private:
    point* value;
    Iterator* nextIterator;
    Iterator* prevIterator;
public:

    Iterator(point* value) {
        this->value = value;
        nextIterator = NULL;
        prevIterator = NULL;
    }

    void insert_after(Iterator* iterator) {

        iterator->prevIterator = this;
        iterator->nextIterator = nextIterator;

        if (nextIterator)
            nextIterator->prevIterator = iterator;

        nextIterator = iterator;

    }

    void insert_before(Iterator* iterator) {

        iterator->nextIterator = this;
        iterator->prevIterator = prevIterator;


        if (prevIterator)
            prevIterator->nextIterator = iterator;

        prevIterator = iterator;

    }

    Iterator* getNext() {
        return nextIterator;
    }

    Iterator* getPrev() {
        return prevIterator;
    }

    const point* getValue() const {
        return value;
    }


    void setValue(point* p) {
        value = p;
    }

    void show() const {
        value->show();
    }

    ~Iterator() {
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

// Класс для двунаправленного списка
class myList {

private:
    Iterator* head;
    Iterator* tail;
public:

    myList() {
        head = NULL;
        tail = head;
    }

    myList(point* value) {
        head = new Iterator(value);
        tail = head;
    }

    ~myList() {
        Iterator* start = head;
        while (start->getNext()) {
            start = start->getNext();
            delete start->getPrev();
        }
        delete tail;
    }

    void pop_back() {
        if (tail) {
            Iterator* tmp = tail->getPrev();
            delete tail;
            tail = tmp;
        }
        else {
            head = NULL;
        }
    }

    void push_back(point* value) {

        Iterator* newEnd = new Iterator(value);

        // Добавляем элемент после хвоста
        if (tail)
            tail->insert_after(newEnd);
        else
            head = newEnd;

        tail = newEnd;
    }

    void pop_front() {
        if (head) {
            Iterator* tmp = head->getNext();
            delete head;
            head = tmp;
        }
        if (!head)
            tail = nullptr;
    }


    void push_front(point* value) {
        Iterator* newStart = new Iterator(value);
        if (head)
            head->insert_before(newStart);
        else
            tail = newStart;

        head = newStart;
    }

    void show() const {
        Iterator* start = head;
        int count = 0;
        while (start) {
            cout << "Point number " << ++count << endl;
            start->getValue()->show();
            start = start->getNext();
        }
    }

    void show_rev() const {
        Iterator* start = tail;
        int count = 0;
        while (start) {
            cout << "Point number " << ++count << endl;
            start->getValue()->show();
            start = start->getPrev();
        }
    }

    Iterator* getHead() {
        return head;
    }

    Iterator* getTail() {
        return tail;
    }
};



int main()
{
    myList* my = new myList;

    my->show();

    my->push_front(new point(1, 1));
    my->push_front(new point(2, 2));
    my->push_front(new point(3, 3));
    my->push_front(new point(4, 4));
    my->push_front(new point(5, 5));
    //my->insert(new point(999, 888), 1);

    my->show();

    cout << endl << endl ;

    my->show_rev();

   

    delete my;
}

