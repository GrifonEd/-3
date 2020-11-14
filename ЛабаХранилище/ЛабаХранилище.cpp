
#include <iostream>
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
        
};

class Shape {
     Shape() {

    }

    ~Shape() {
        cout << "Фигура удалилась";
    }

};


class Point : public Shape {
private: 
    int x,y;
public:
    Point() {
        x = 0;
        y = 0;
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
    ~Section() {
        delete p1;
        delete p2;
    }
};


int main()
{
    cout << "Hello World!\n";


}
