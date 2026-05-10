#include <cstdlib>
#include <ctime>
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "LinkedList.h"

int main() {
    srand(time(0));  // Санамсаргүй тоо үүсгэгчийг цагаар эхлүүлнэ

    LinkedList<Shape*> list;  // Shape pointer-ийн жагсаалт үүсгэнэ

    // 25 санамсаргүй дүрсийн объект үүсгэж жагсаалтад нэмнэ
    int total = 25;
    for (int i = 0; i < total; i++) {
        int type = rand() % 3;
        double x    = rand() % 20;
        double y    = rand() % 20;
        double size = (rand() % 10 + 1) + (rand() % 10) * 0.1;

        if (type == 0)
            list.add(new Circle(x, y, size));
        else if (type == 1)
            list.add(new Square(x, y, size));
        else
            list.add(new Triangle(x, y, size));
    }

    cout << "========================================" << endl;
    cout << "  Total shapes: " << list.length() << endl;
    cout << "========================================" << endl;

    cout << "\n--- Эрэмбэлэхийн өмнө ---\n" << endl;
    list.printAll();

    list.sortByArea();  // Талбайгаар эрэмбэлнэ

    cout << "\n--- Талбайгаар эрэмбэлсний дараа ---\n" << endl;
    list.printAll();

    // insert туршина
    cout << "\n--- insert(Circle r=99.9, index=0) ---" << endl;
    list.insert(new Circle(0, 0, 99.9), 0);
    list.get(0)->print();
    cout << endl;

    // deleteAt туршина
    cout << "\n--- deleteAt(0) ---" << endl;
    list.deleteAt(0);
    list.get(0)->print();
    cout << endl;

    cout << "\n--- Final length: " << list.length() << " ---" << endl;

    // Shape объектуудын санах ойг чөлөөлнө
    for (int i = 0; i < list.length(); i++)
        delete list.get(i);

    return 0;
}