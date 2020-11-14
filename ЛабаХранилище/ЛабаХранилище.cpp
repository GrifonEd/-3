
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <iomanip> 
#include <string>
#include <ctime>

using namespace std;

class Shape {
public:
    Shape() {

    }
    virtual void show() {
        cout <<endl<< "Абстрактная фигура" << endl;
    }
    virtual ~Shape() {
        cout << "Фигура удалилась\n" << endl;
    }

};

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
        objects[index]->~Shape();
    }
    void add(Shape* object) {
        Shape** object1 = new Shape * [size + 1];
        for (int i = 0; i < size; i++)
            object1[i] = objects[i];
        object1[size] = object;
        size++;
        delete objects;
        objects = object1;
        cout << "Добавили объект ";
        object->show();
        cout << "В память c индексом  " << size - 1 << endl<<endl;
    }

    int getCount() {
        return size;
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
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void show() {
        cout << "Точка с координатами( " << x << ", " << y << " )"<<endl;
    }
    ~Point() {
        cout << "Точка удалилась с координатами " << x << " , " << y << endl;
    }

};

class Section : public Shape {
private :
    Point* p1, * p2;
    int x1, x2, y1, y2;
public :
    Section() {
        p1 = new Point(rand()%10, (rand() % 10));
        p2 = new Point(rand() % 10, (rand() % 10));
    }
    void show() {
        cout << endl << "Отрезок с точками : ";
            cout << endl;
            ; p1->show(); p2->show();
        cout << endl;
    }
    ~Section() {
        cout << "Отрезок с точками : ";
        cout << endl; 
        p1->show(); p2->show();
        delete p1;
        delete p2;
    }
};


int main()
{
    Shape* q;
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    MyStorage storage(10);
    for (int i = 0; i < storage.getCount(); i++) {
        int a = rand() % 2 + 1;
        if (a == 2)
            storage.SetObject(i, new Point(rand()%10,rand()%10));
        else
            storage.SetObject(i, new Section());
    }
    for (int i = 0; i < storage.getCount(); i++) {
        storage.GetObject(i).show();
    }


    cout << endl << storage.getCount() << " - Это размер хранилища" << endl << endl;

    unsigned int start_time = clock();
    for (int i = 0; i < 100; i++) {
        int luck = rand() % 4 + 1;
        switch (luck) {

        case 1:
            luck = rand() % 2 + 1;
            if (luck == 1) {
                q = new Point(rand() % 10, rand() % 10);
            }
            else
                q = new Section();
            break;

        case 2:
            luck = rand() % 2 + 1;
            if (luck == 1) {
                q = new Point(rand() % 10, rand() % 10);
            }
            else
                q = new Section();
            storage.add(q);
            break;
            
        case 3 :
            cout << "Используем метод show\n";
            storage.GetObject(rand() % storage.getCount()).show();
            cout << endl;
            break;

        case 4:
            storage.delete_obj(rand() % storage.getCount());
            cout << endl;
            break;
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Время работы программы = " << search_time << endl;
    system("pause");
    system("cls");

     start_time = clock();
    for (int i = 0; i < 10000; i++) {
        int luck = rand() % 4 + 1;
        switch (luck) {

        case 1:
            luck = rand() % 2 + 1;
            if (luck == 1) {
                q = new Point(rand() % 10, rand() % 10);
            }
            else
                q = new Section();
            break;

        case 2:
            luck = rand() % 2 + 1;
            if (luck == 1) {
                q = new Point(rand() % 10, rand() % 10);
            }
            else
                q = new Section();
            storage.add(q);
            break;

        case 3:
            cout << "Используем метод show\n";
            storage.GetObject(rand() % storage.getCount()).show();
            cout << endl;
            break;

        case 4:
            storage.delete_obj(rand() % storage.getCount());
            cout << endl;
            break;
        }
    }
    end_time = clock();
     search_time = end_time - start_time;
    cout << "Время работы программы = " << search_time << endl;
    system("pause");
    system("cls");

    start_time = clock();
    for (int i = 0; i < 100; i++) {
        int luck = rand() % 4 + 1;
        switch (luck) {

        case 1:
            luck = rand() % 2 + 1;
            if (luck == 1) {
                q = new Point(rand() % 10, rand() % 10);
            }
            else
                q = new Section();
            break;

        case 2:
            luck = rand() % 2 + 1;
            if (luck == 1) {
                q = new Point(rand() % 10, rand() % 10);
            }
            else
                q = new Section();
            storage.add(q);
            break;

        case 3:
            cout << "Используем метод show\n";
            storage.GetObject(rand() % storage.getCount()).show();
            cout << endl;
            break;

        case 4:
            storage.delete_obj(rand() % storage.getCount());
            cout << endl;
            break;
        }
    }
   end_time = clock();
    search_time = end_time - start_time;
    cout << "Время работы программы = " << search_time << endl;
    system("pause");
    system("cls");
}
