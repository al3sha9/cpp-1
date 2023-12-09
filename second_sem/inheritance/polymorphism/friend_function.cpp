#include<iostream>
#include<string>
using namespace std;

class Complex{
    int a, b;

    public: 
    void setNum(int n1, int n2){
        a = n1;
        b = n2;
    }
    //this declaration is must in order to give access to the friend fuction
    friend Complex sumComp(Complex o1, Complex o2);
    void print(){
        cout<<"Number is : "<<a<<" + "<<b<<"i"<<endl;
    }
};

Complex sumComp(Complex o1, Complex o2){
    Complex o3;
    o3.setNum((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
//friend function
int main(){
    Complex c1, c2, sum;
    c1.setNum(1,4);
    c1.print();

    c2.setNum(2,4);
    c2.print();
    
    sum = sumComp(c1,c2);
    sum.print();
}