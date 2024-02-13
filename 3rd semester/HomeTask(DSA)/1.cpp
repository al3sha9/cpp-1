/*
1. Create a simple class
Define a class called Person with attributes name and age. Implement
methods to set and display these attributes.
*/
#include<iostream>
#include<string>
using namespace std;

class Person{
    private:
        string name;
        int age;

    public:
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }

};
int main(){
    Person p;
    p.setName("Fazila");
    p.setAge(20);
    cout<<p.getName()<<endl;
    cout<<p.getAge()<<endl;
    p.getName();
    p.getAge();
    return 0;
}
