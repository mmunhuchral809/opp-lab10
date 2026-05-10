#pragma once
#include "Shape.h"

// Shape-аас удамшсан 2D дүрсийн суурь класс
// x, y - дүрсийн байршлын координат
class TwoDShape : public Shape {
protected:
    double x, y;
public:
    TwoDShape(double x = 0, double y = 0, string n = "2DShape")
        : Shape(n), x(x), y(y) {}

    double getX() { return x; }
    double getY() { return y; }
};