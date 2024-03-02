#include<iostream>
using namespace std;

class Shape {
protected:
    int length, width, radius;

public:
    Shape(int length, int width, int radius) {
        this->length = length;
        this->width = width;
        this->radius = radius;
    }
    virtual int calculate() = 0; // Pure virtual function
};

class Rectangle : public Shape {
public:
    Rectangle(int length, int width) : Shape(length, width, 0) {}

    int calculate() override {
        return length * width;
    }
};

class Circle : public Shape {
public:
    Circle(int radius) : Shape(0, 0, radius) {}

    int calculate() override {
        return 3.14 * radius * radius;
    }
};

class Triangle : public Shape {
public:
    Triangle(int length, int width) : Shape(length, width, 0) {}

    int calculate() override {
        return 0.5 * length * width;
    }
};

int main() {
    Rectangle r(2, 4);
    cout << "The area of rectangle is: " << r.calculate() << endl;

    Circle c(5);
    cout << "The area of circle is: " << c.calculate() << endl;

    Triangle t(3, 6);
    cout << "The area of triangle is: " << t.calculate() << endl;

    return 0;
}
