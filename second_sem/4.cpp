#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int roll_no;
    float phNo;

public:
    void studData(string stdName, int stdroll, int stdN)
    {
        name = stdName;
        roll_no = stdroll;
        phNo = stdN;
    }

    void displayStudentData()
    {
        cout << "<---------------------------->" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
        cout << "Phone Number: " << phNo << endl;
        cout << "<---------------------------->" << endl;
    }
};

int main()
{
    Student St1, St2;

    St1.studData("John", 2, 0356);

    St1.displayStudentData();

    St2.studData("Sam", 1, 03246);

    St2.displayStudentData();

    return 0;
}
