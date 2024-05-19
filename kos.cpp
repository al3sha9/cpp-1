
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int employeeID;

public:
    Employee(string name, int employeeID) : name(name), employeeID(employeeID) {}

    string getName() const { return name; }
    int getEmployeeID() const { return employeeID; }

    virtual double calculateSalary() const = 0;
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(string name, int employeeID, double monthlySalary)
        : Employee(name, employeeID), monthlySalary(monthlySalary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(string name, int employeeID, double hourlyRate, int hoursWorked)
        : Employee(name, employeeID), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    FullTimeEmployee fullTimeEmp("John Doe", 1001, 5000.0);
    PartTimeEmployee partTimeEmp("Alice Smith", 1002, 20.0, 80);

    cout << "Full-time employee salary: $" << fullTimeEmp.calculateSalary() << endl;
    cout << "Part-time employee salary: $" << partTimeEmp.calculateSalary() << endl;

    ofstream file("employees.txt");
    if (file.is_open()) {
        file << "Name: " << fullTimeEmp.getName() << ", Employee ID: " << fullTimeEmp.getEmployeeID()
             << ", Salary: $" << fullTimeEmp.calculateSalary() << endl;
        file << "Name: " << partTimeEmp.getName() << ", Employee ID: " << partTimeEmp.getEmployeeID()
             << ", Salary: $" << partTimeEmp.calculateSalary() << endl;
        file.close();
    } else {
        cerr << "Unable to open file!" << endl;
    }

    return 0;
}