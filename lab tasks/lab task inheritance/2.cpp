#include<iostream>
#include<string>
using namespace std;

class Shape{
    protected:
    string color;

    public:
    Shape(){}
    Shape(string c){
        color = c;
    }
    
};
class Rectangle:public Shape{
    protected:
    int length, width;
    public:
    Rectangle(){}
    Rectangle(int l,int  w, string color){
        length = l;
        width = w;
        this->color = color;
    }
    void areaCalculate(){
        cout<<"Color is: "<<color<<endl;
        cout<<"Area of Rectange is: "<<length*width<<endl;
    }

};
class Square:public Rectangle{
    public:
    Square(){}
    int info(){
         if (length==width){
        cout<<"it is a square"<<endl;
        cout<<length*width;
    }else
    cout<<"not a square"<<endl;
    }
    
};
int main(){
    Shape shapeObject;

    Rectangle rObject(2,3, "Blue");
    rObject.areaCalculate();
    Square sObject;
    sObject.areaCalculate();
    sObject.info();
}