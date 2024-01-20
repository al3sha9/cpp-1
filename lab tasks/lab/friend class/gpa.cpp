#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int grade[3];

    public:
    Student(string name){
        this->name = name;
    }
    friend class GPACalculator;
    void display(){
        cout<<name<<endl;
        cout<<grade<<endl;
    }
};
class GPACalculator{
    public:
    void calculateGPA(Student& s){
        s.grade[3];
    }
};
int main(){
    Student studentObject("ali");
    int grade[3] = {34,33,20};
}