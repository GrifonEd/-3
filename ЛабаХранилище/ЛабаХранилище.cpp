
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <iomanip> 
#include <string>
#include <ctime>

using namespace std;
class MyStorage {
private :
    Shape** objects;
    int size;
public:
    MyStorage(int size) {
        this->size = size;
        objects = new Shape * [size];
    }
    void SetObject(int index, Shape* object) {
        objects[index] = object;
    }
    Shape& GetObject(int index) {
        return *objects[index];
    }
    void delete_obj(int index)
    {

    }
    void add(Shape* object) {

    }

    int getCount() {
        return size;
    }
};

class Shape {
     Shape() {

    }
     void show() {
         cout << "Абстрактная фигура"<<endl;
     }
    ~Shape() {
        cout << "Фигура удалилась"<<endl;
    }

};


class Point :public Shape {
private: 
    int x,y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    void show() {
        cout << "Точка с координатами( " << x << ", " << y << " )"<<endl;
    }
    ~Point() {
        cout << "Точка удалилась";
    }

};

class Section : public Shape {
private :
    Point* p1, * p2;
    int x1, x2, y1, y2;
public :
    Section() {
        p1 = new Point;
        p2 = new Point;
    }
    void show() {
        cout << "Отрезок с точками : "; p1->show(); p2->show();
    }
    ~Section() {
        delete p1;
        delete p2;
    }
};


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    MyStorage storage(10);
    for (int i = 0, i < storage.getCount(); i++) {

    }
}
