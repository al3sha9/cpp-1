#include<iostream>
using namespace std;

class Rectangle{
   public:
    int length;
    int width;
    int area;
    
    Rectangle (int len, int wid){
        length = len;
        width = wid;
        area = len*wid;
    }
    public:
    int calculateArea(){
        return area;
    }
};

int main(){
    Rectangle r1(2,3);
    r1.calculateArea();
    
    cout<<"Area: "<<r1.calculateArea();
}
