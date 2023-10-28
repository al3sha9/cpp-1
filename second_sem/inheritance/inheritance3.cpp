#include<iostream>
using namespace std;
//base class
class Animal{
    public: 
    void eat(){
        cout<<"I can eat!\n";
    }
    void sleep(){
        cout<<"I can sleep!\n";
    }
};
//derived class
class Dog: public Animal{
    public:
    void Bark(){
        cout<<"I can do everything!\n";
    }
};

int main(){
    Dog dog1;
    dog1.eat();
    dog1.sleep();
    
    dog1.Bark();
    
    
}