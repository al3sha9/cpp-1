#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;

public:
    friend void setEmployeeDetails(Employee &emp, string name, int employeeID, double salary);
    friend void displayEmployeeDetails(const Employee &emp);

    Employee(string name, int employeeID, double salary) {
        this->name = name;
        this->employeeID = employeeID;
        this->salary = salary;
    }
};

void setEmployeeDetails(Employee &emp, string name, int employeeID, double salary) {
    emp.name = name;
    emp.employeeID = employeeID;
    emp.salary = salary;
}

void displayEmployeeDetails(const Employee &emp) {
    cout << "Employee Name: " << emp.name << endl;
    cout << "Employee ID: " << emp.employeeID << endl;
    cout << "Employee Salary: $" << emp.salary << endl;
}

int main() {
    Employee emp("Fazila", 1001, 50000.0);

    cout << "Initial Employee Details:" << endl;
    displayEmployeeDetails(emp);
    cout << endl;

    setEmployeeDetails(emp, "Ali", 1222, 600000.0);

    cout << "Updated Employee Details:" << endl;
    displayEmployeeDetails(emp);

    return 0;
}
