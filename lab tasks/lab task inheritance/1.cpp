#include<iostream>
#include<string>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    

};
class Student : public Person{
    public:
    int StudentID;
    void getinfo(){
        cout<<"Enter name, age and id: ";
        cin>>name>>age>>StudentID;
    }
    void diplayinfo(){
        cout<<"Name "<<name<<endl;
        cout<<"Age "<<age<<endl;
        cout<<"Id "<<StudentID<<endl;
    }
};
class CollegeStudent: public Student{
    public:
    string collegeName, major;
    void get(){
        cout<<"Enter college name and major "<<endl;
        cin>>collegeName>>major;
    }
    void display(){
        cout<<"College name: "<< collegeName<<" "<<"Major: "<<major<<endl;
    }
};
int main(){
    Person P;
    Student S;
    S.getinfo();
    S.diplayinfo();

    CollegeStudent C;
    C.get();
    C.display();
}