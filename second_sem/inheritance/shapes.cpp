#include<iostream>
using namespace std;

class shapes{
    protected:
    float area;
    float perimeter;
    ~shapes(){
        cout<<"The classes has been destroyed now!"<<endl;
    }
};

class circle:public shapes{
    public:
    float r;

    int getvalues(){
       
        area = 3.14 * r *r;
        return area;
        perimeter = 2*3.14*r;
        return perimeter;
    }
};
class rectangle:public shapes{
    public:
    float w,l;

    int displayR(){
        area = w*l;
        return area;

        perimeter = (l+w)*2;
        return perimeter;
    }
};
class triangle :public shapes{
    public:
    int h,br;
    int a, b,c;

    int findArea(){
       
        area = (h*br)/2;
        return area;
    }
    int findPerimeter(){
       
        perimeter = a+b+c;
        return perimeter;
    }
};
int main(){
    
    circle C;
    cout<<"Enter the radius: ";
    cin>>C.r;
    cout<<"Circle: "<<C.getvalues()<<endl;

    rectangle R;
    cout<<"Enter width and length: "<<endl; 
    cin>>R.w>>R.l;
    cout<<"Rectangle: "<<R.displayR()<<endl;

    triangle T;
    cout<<"Enter the height and breadth of triangle: "<<endl;
    cin>>T.h>>T.br;
    cout<<"Triangle Area: "<<T.findArea()<<endl;
    cout<<"Enter the three sides of triangle: "<<endl;
    cin>>T.a>>T.b>>T.c;
    cout<<"Trianngle Perimeter: "<<T.findPerimeter()<<endl;
    return 0;
}