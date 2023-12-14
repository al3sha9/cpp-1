#include<iostream>
#include<cmath>
using namespace std;

class Number{
    protected:
        float a,b,c;

    public:
        Number(float a, float b, float c){
            this -> a = a;
            this -> b = b;
            this -> c = c;
        }
        friend class Computation;
        friend void display(Number);
};
class Computation{

};
void display(Number){
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
}
int main(){

}