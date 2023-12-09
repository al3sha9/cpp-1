#include<iostream>
#include<string>
using namespace std;

class Employee{
    private:
    int employeeId, salary;
    string name;
    
    public:
    Employee(int ID, string n, int s):employeeId(ID), name(n), salary(s){}
    friend double promoteEmployee(Employee objE);
};
double promoteEmployee(Employee objE){
        cout<<"Name: "<<objE.name<<endl;
        cout<<"ID: "<<objE.employeeId<<endl;
        cout<<"Previous Salary: "<<objE.salary<<endl;
        
        cout<<"Raise in salary of 20% "<<endl;
        objE.salary = (objE.salary*20)/100;
        cout<<objE.salary + 30000;
}
int main(){
    Employee object(101, "Fazila", 30000);

    promoteEmployee(object);
}