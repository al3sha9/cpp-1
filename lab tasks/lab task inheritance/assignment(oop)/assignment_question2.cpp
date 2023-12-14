#include<iostream>
#include<cmath>
using namespace std;


class Number{
    protected:
        float a,b,c;

    public:
        Number(){}
        Number(float a, float b, float c){
            this -> a = a;
            this -> b = b;
            this -> c = c;
        }
        friend class Computation;
        friend void display(Number);
};
class Computation{
    public:
    int squareOfSums(Number n){
        return (n.a * n.a + n.b * n.b + n.c * n.c + 2 * n.a * n.b + 2 * n.b * n.c + 2 * n.c * n.a);
    }
    int squareOfDifference(Number n){
        return(n.a * n.a - n.b * n.b - n.c * n.c - 2 * n.a * n.b - 2 * n.b * n.c - 2 * n.c * n.a);
    }
    int meanOfThreeNumber(Number n){
        return (n.a * n.b * n.c)/3;
    }
};
void display(Number n){
    cout<<"a is: "<<n.a<<endl;
    cout<<"b is: "<<n.b<<endl;
    cout<<"c is: "<<n.c<<endl;
}
int main(){
    Number numberObject(2,3,4);
    display(numberObject);
    Computation computationObject;
    cout<<"Sum: "<<computationObject.squareOfSums(numberObject)<<endl;
    cout<<"Difference: "<<computationObject.squareOfDifference(numberObject)<<endl;
    cout<<"Mean: "<<computationObject.meanOfThreeNumber(numberObject)<<endl;
}