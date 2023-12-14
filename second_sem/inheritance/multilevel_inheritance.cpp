#include<iostream>
using namespace std;

class Person {
    protected:
     string name;
     int age;
};
class Student : public Person{
    public:
        int Id;

        void get_info(){
            cout<<"Enter name age and Id: ";
            cin>>name>>age>>Id;
        }
        void display_info(){
            cout<<"Name = "<<name<<endl;
            cout<<"Age = "<<age<<endl;
            cout<<"Id = "<<Id<<endl;
        }
};
class CollegeStudent : public Student{
    public:
        string college_name, major;

        void get_info2(){
            cout<<"Enter college name and major: ";
            cin>>college_name>>major;
        }
        void display_info2(){
            cout<<"College: "<<college_name<<endl;
            cout<<"Major: "<<major<<endl;
        }
};
int main(){
    Person P;
    Student S;
    S.get_info();
    S.display_info();
    CollegeStudent C;
    C.get_info();
    C.display_info2();
}