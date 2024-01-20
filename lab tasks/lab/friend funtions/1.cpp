#include<iostream>
#include<cmath>
using namespace std;

class Point{
    private:
    int x, y;
    int x2, y2;
    public:
    friend void calculateDistance(Point obj1, Point obj2);
};
void calculateDistance(Point obj1, Point obj2){
    cout<<"Enter value for x1: ";
    cin>>obj1.x;
    cout<<"Enter value for x2: ";
    cin>>obj1.x2;
    cout<<"Enter value for y1: ";
    cin>>obj2.y;
    cout<<"Enter value for y2: ";
    cin>>obj2.y2;
    float d = sqrt((obj1.x - obj1.x2)*(obj1.x - obj1.x2) + (obj2.y - obj2.y2)*(obj2.y - obj2.y2));
    cout<<"Distance: "<<d<<endl;
}
int main(){
    Point POb1, POb2;
    calculateDistance(POb1,POb2);
}