#include<iostream>
#include<string>
using namespace std;

class Shape{
    protected:
        string name;

    public:
        virtual void display(){}
        
        virtual double calculateArea(){
            cout<<"This will calculate the area";
            return 0;
        }
};
class Rectangle: public Shape{
    private:
        double length, width;
    public:
        Rectangle(double length, double width){
            this->length = length;
            this->width = width;
            name = "Rectangle ";
        }

        void display(){
            cout<<name;
        }
        double calculateArea(){
            return length*width;
        }
};
class Circle: public Shape{
    private:
        double radius;

    public:
        Circle(double radius){
            this->radius = radius;
            name = "Circle ";
        }
        void display(){
            cout<<name;
            cout<<"Radius:"<<radius<<endl;
        }
        double calculateArea(){
            return 3.14*radius*radius;
        }
};
int main(){
    int size = 4;
    Shape* shapes[size];

    shapes[0] = new Rectangle(4.0, 0.0);
    shapes[1] = new Circle(5.9);
    shapes[2] = new Rectangle(3.0, 6.0);
    shapes[3] = new Circle(4.0);

    for (int i = 0; i < size; ++i){
        shapes[i]->display();
        cout << "Area: " << shapes[i]->calculateArea()<<endl;
    }
    
    for (int i = 0; i < size; ++i){
        delete shapes[i];
    }

    return 0;
}