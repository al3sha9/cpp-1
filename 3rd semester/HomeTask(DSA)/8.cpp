#include<iostream>
using namespace std;

class shape {
protected:
    int length, width, radius;

public:
    shape(int length, int width, int radius) {
        this->length = length;
        this->width = width;
        this->radius = radius;
    }
    virtual int calculate() = 0; // Pure virtual function
};

class rectangle : public shape {
public:
    rectangle(int length, int width) : shape(length, width, 0) {}

    int calculate() override {
        return length * width;
    }
};

class circle : public shape {
public:
    circle(int radius) : shape(0, 0, radius) {}

    int calculate() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    rectangle r(2, 4);
    cout << "The area of rectangle is: " << r.calculate() << endl;

    circle c(5);
    cout << "The area of circle is: " << c.calculate() << endl;

    return 0;
}
