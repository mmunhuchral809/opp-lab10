#pragma once
#include "TwoDShape.h"

// Квадрат класс - TwoDShape-аас удамшсан
class Square : public TwoDShape {
private:
    double side;  // Талын урт
public:
    Square(double x = 0, double y = 0, double s = 1.0, string n = "Square")
        : TwoDShape(x, y, n), side(s) {}

    // Copy constructor
    Square(const Square& other)
        : TwoDShape(other.x, other.y, other.name), side(other.side) {}

    double area() override {
        return side * side;
    }
    double perimeter() override {
        return 4 * side;
    }
    double getSide() { return side; }

    void print() override {
        cout << "[Square] TopLeft=(" << x << "," << y << ")"
             << " Side=" << side
             << " Area=" << area()
             << " Perimeter=" << perimeter();
    }
};