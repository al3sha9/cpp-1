#include<iostream>
#include<string>
using namespace std;

class Employee {
private:
    int ID, salary;
    string name;

public:
    Employee(int ID, int salary, string name) {
        this->ID = ID;
        this->salary = salary;
        this->name = name;
    }

    friend void promoteEmployee(Employee&);

    void display() {
        cout << "Employee ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

void promoteEmployee(Employee& E) {
    double raisedSalary; 
    double raisedPercentage = 0.05;
    cout << "Salary raised by 5%" << endl;
    raisedSalary = E.salary + raisedPercentage * E.salary;
    cout << raisedSalary << endl;
}

int main() {
    Employee object(101, 20000, "Fazila");
    object.display();
    promoteEmployee(object);

    return 0;
}
