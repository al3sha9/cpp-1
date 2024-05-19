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

    // Getters
    string getName() const { return name; }
    int getEmployeeID() const { return employeeID; }

    // Virtual function to calculate salary
    virtual double calculateSalary() const = 0;
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(string name, int employeeID, double monthlySalary)
        : Employee(name, employeeID), monthlySalary(monthlySalary) {}

    // Override calculateSalary method for full-time employees
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

    // Override calculateSalary method for part-time employees
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    // Example usage
    FullTimeEmployee fullTimeEmp("John Doe", 1001, 5000.0);
    PartTimeEmployee partTimeEmp("Alice Smith", 1002, 20.0, 80);

    // Display salaries
    cout << "Full-time employee salary: $" << fullTimeEmp.calculateSalary() << endl;
    cout << "Part-time employee salary: $" << partTimeEmp.calculateSalary() << endl;

    // Storing employee information and salaries in a text file
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
