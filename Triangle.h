#pragma once
#include "TwoDShape.h"
#include <cmath>

// Зөв гурвалжин класс - TwoDShape-аас удамшсан
class Triangle : public TwoDShape {
private:
    double side;  // Талын урт
public:
    Triangle(double x = 0, double y = 0, double s = 1.0, string n = "Triangle")
        : TwoDShape(x, y, n), side(s) {}

    // Copy constructor
    Triangle(const Triangle& other)
        : TwoDShape(other.x, other.y, other.name), side(other.side) {}

    double area() override {
        return (sqrt(3.0) / 4.0) * side * side;
    }
    double perimeter() override {
        return 3 * side;
    }
    double getSide() { return side; }

    void print() override {
        cout << "[Triangle] TopLeft=(" << x << "," << y << ")"
             << " Side=" << side
             << " Area=" << area()
             << " Perimeter=" << perimeter();
    }
};