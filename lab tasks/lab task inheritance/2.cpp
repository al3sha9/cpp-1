#include<iostream>
#include<string>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape() {}
    Shape(string c) : color(c) {}
};

class Rectangle : public Shape {
protected:
    int length, width;

public:
    Rectangle() {}
    Rectangle(int l, int w, string color) : Shape(color), length(l), width(w) {}

    void areaCalculate() {
        cout << "Color is: " << color << endl;
        cout << "Area of Rectangle is: " << length * width << endl;
    }
};

class Square : public Rectangle {
public:
    Square() {}
    Square(int side, string color) : Rectangle(side, side, color) {}

    void info() {
        if (length == width) {
            cout << "It is a square" << endl;
            cout << "Area of Square is: " << length * width << endl;
        } else
            cout << "Not a square" << endl;
    }
};

int main() {
    Shape shapeObject;

    Rectangle rObject(2, 3, "Blue");
    rObject.areaCalculate();

    Square sObject(4, "Red");
    sObject.areaCalculate();
    sObject.info();

    return 0;
}
