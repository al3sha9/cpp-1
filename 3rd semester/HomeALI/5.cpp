#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    char grade;
public:
    void setName(string name) {
        this->name = name;
    }
    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }
    void setGrade(char grade) {
        this->grade = grade;
    }
    string getName() {
        return name;
    }
    int getRollNo() {
        return rollNo;
    }
    char getGrade() {
        return grade;
    }
    void display() {
        cout << "Name is : " << name << endl;
        cout << "Roll Number is : " << rollNo << endl;
        cout << "Grade is : " << grade << endl;
    }
};

int main() {
    Student object;
    object.setName("Alishan");
    object.setRollNo(2280246);
    object.setGrade('A');
    object.display();
    return 0;
}
