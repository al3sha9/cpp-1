#include <iostream>
using namespace std;

class Employee
{
private:
    float salary;
    int hrsPrDay;

public:
    void getInfo(float sal, int hr)
    {
        salary = sal;
        hrsPrDay = hr;
    }
    void AddSal()
    {
        if (salary < 500)
        {
            salary += 10;
        }
    }
    void AddWork()
    {
        if (hrsPrDay > 6)
        {
            salary += 5;
        }
    }
    void finalSalary()
    {
        cout << "Final Salary is : " << salary << endl;
    }
};

int main()
{
    Employee emp;

    float sala;
    int wh;

    cout << "Enter Salary" << endl;
    cin >> sala;

    cout << "enter work hours" << endl;
    cin >> wh;

    emp.getInfo(sala, wh);

    emp.AddSal();
    emp.AddWork();

    emp.finalSalary();

    return 0;
}
