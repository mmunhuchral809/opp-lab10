#pragma once
#include <iostream>
#include <string>
using namespace std;

// Бүх дүрсийн суурь abstract класс
class Shape {
protected:
    string name;
public:
    Shape(string n = "Shape") : name(n) {}

    virtual double area() = 0;       // Талбай - pure virtual
    virtual double perimeter() = 0;  // Периметр - pure virtual

    virtual void print() {
        cout << "Name: " << name
             << " | Area: " << area()
             << " | Perimeter: " << perimeter();
    }

    string getName() { return name; }
    virtual ~Shape() {}
};