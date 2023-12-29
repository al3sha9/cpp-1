#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
    string name;

public:
    virtual void display() = 0;
    virtual double calculateArea() = 0;
};

class Rectangle : public Shape
{
private:
    double lenght, width;

public:
    Rectangle(double l, double w)
    {
        lenght = l;
        width = w;
    }
    void display()
    {
        cout << "\nlenght and width of the Rectangle are: \n\tLenght: " << lenght << "\n\tWidth: " << width << endl;
    }
    double calculateArea()
    {
        return lenght * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }
    void display()
    {
        cout << "\nRadius of the Circle is: " << radius << endl;
    }
    double calculateArea()
    {
        return (radius * radius) * 3.14;
    }
};
int main()
{
    int arSize = 4;
    Shape *shapes[arSize];

    shapes[0] = new Rectangle(66.8, 99.3);
    shapes[1] = new Circle(77.3);
    shapes[2] = new Rectangle(6.9, 9.3);
    shapes[3] = new Circle(988.3);

    for (int i = 0; i < arSize; i++)
    {
        shapes[i]->display();
        cout << "area of the shape is" << shapes[i]->calculateArea() << endl;
    }

    for (int i = 0; i < arSize; i++)
    {
        delete shapes[i];
    }

    return 0;
}