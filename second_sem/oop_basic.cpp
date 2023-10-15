#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int roll_no;

public:
    void studData(string stdName, int stdroll)
    {
        name = stdName;
        roll_no = stdroll;
    }

    void displayStudentData() const
    {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
    }
};

int main()
{
    Student St1;

    St1.studData("John", 2);

    St1.displayStudentData();

    return 0;
}
