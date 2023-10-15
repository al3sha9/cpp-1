#include<iostream>
#include <string>
using namespace std;

class Employee{
    private:
        string name;
        int yrOfJng;
        float salary;
        string address;
    public:
        Employee(string n, int y, float s, string a){
            name = n;
            yrOfJng = y;
            salary = s;
            address = a;
        }
        void showDetails(){
             cout << name << "\t" << yrOfJng << "\t"<<salary<<"\t" << address << endl;
        }
};

int main(){
    Employee employee1("Robert", 1994, 0.0, "64C- WallsStreet");
    Employee employee2("Sam   ", 2000, 0.0, "68D- WallsStreet");
    Employee employee3("John  ", 1999, 0.0, "26B- WallsStreet");

    // Displaying employee information
    cout << "Name\tYear of joining\tAddress" << endl;
    employee1.showDetails();
    employee2.showDetails();
    employee3.showDetails();
}