#include<iostream>
using namespace std;

class Shape
{
protected:
    float area, perim;
public:
Shape(){};
    Shape(float a, float p){
        area = a;
        perim = p;
    };
    
};

class Circle : public Shape{
    private:
    float circum;
    float radius;
    public:
    Circle(float c, float r):  circum(c), radius(r){
        calA();
    };
    void calA(){
        area = 3.14 * radius * radius;
        dis();
    }
    void dis(){
        cout<< area<<endl;
    }
};
class Rect : public Shape{
    private:
    float len;
    float wid;
    public:
    Rect(float len, float wid): len(len), wid(wid){
        calA();
        // comment
    };
    void calA(){
        area = len * wid;
        dis();
    }
    void dis(){
        cout<< area<<endl;
    }
};

int main(){
    Circle C(34, 4);
    Rect(45, 34);
}