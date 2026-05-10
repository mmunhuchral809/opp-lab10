#pragma once
#include "TwoDShape.h"
#include <cmath>

// Тойрог класс - TwoDShape-аас удамшсан
class Circle : public TwoDShape {
private:
    double radius;  // Радиус
public:
    Circle(double cx = 0, double cy = 0, double r = 1.0, string n = "Circle")
        : TwoDShape(cx, cy, n), radius(r) {}

    // Copy constructor
    Circle(const Circle& other)
        : TwoDShape(other.x, other.y, other.name), radius(other.radius) {}

    double area() override {
        return M_PI * radius * radius;
    }
    double perimeter() override {
        return 2 * M_PI * radius;
    }
    double getRadius() { return radius; }

    void print() override {
        cout << "[Circle] Center=(" << x << "," << y << ")"
             << " Radius=" << radius
             << " Area=" << area()
             << " Perimeter=" << perimeter();
    }
};