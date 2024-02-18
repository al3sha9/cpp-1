#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string name, int employeeID, double salary) {
        this->name = name;
        this->employeeID = employeeID;
        this->salary = salary;
    }

    void setEmployeeDetails(string name, int employeeID, double salary) {
        this->name = name;
        this->employeeID = employeeID;
        this->salary = salary;
    }

    void displayEmployeeDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Employee Salary: $" << salary << endl;
    }
};

int main() {
    Employee emp("Fazila", 1001, 50000.0);

    cout << "Initial Employee Details:" << endl;
    emp.displayEmployeeDetails();
    cout << endl;

    emp.setEmployeeDetails("Fazila", 1001, 50000.0);

    cout << "Updated Employee Details:" << endl;
    emp.displayEmployeeDetails();

    return 0;
}
