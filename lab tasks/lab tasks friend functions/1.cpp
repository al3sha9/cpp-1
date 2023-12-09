#include<iostream>
using namespace std;

class Point{
    private: 
     float x, y;
     
    public:
     Point(float x, float y):x(x), y(y){}
     
     friend float calculateDistance(Point p1, Point p2);
};

float calculateDistance(Point p1, Point p2){
    return ((p2.x + p1.y) - (p2.x + p1.y));
}

int main(){
    float x,y,xp1,yp2; 
    Point  p1(x,y), p2(xp1,yp2);
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    cout<<"Enter x: ";
    cin>>xp1;
    cout<<"Enter y: ";
    cin>>yp2;
    
    cout<<"Distance : "<<calculateDistance(p1,p2);
}
