#include<iostream>
using namespace std;
class BaseClass{
    public:
    int var_base;
    void display(){
        cout<<"Display base class varible:"<<var_base<<endl;
    }
};
class DerivedClass : public BaseClass{
    public:
    int var_derived;
    void display(){
        cout<<"Display base class varible:"<<var_base<<endl;
        cout<<"Display derived class varible:"<<var_derived<<endl;
    }
};
int main(){
    BaseClass *base_class_pointer;
    BaseClass obj_base;

    DerivedClass obj_derived;
    base_class_pointer = &obj_derived;
    base_class_pointer->var_base = 32;
    base_class_pointer->display();

    DerivedClass *derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_derived = 12;
    derived_class_pointer->display();

}