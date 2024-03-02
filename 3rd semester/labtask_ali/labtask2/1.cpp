#include<iostream>
using namespace std;

class Student {
private:
    int grades[5];
    int average;

public:
    void getGrade() {
        cout << "Enter the grades of five subjects: " << endl;
        for (int i = 0; i < 5; i++) {
            cin >> grades[i];
        }
    }

    void calculateAverage() {
        average = 0;
        cout << "The grades are: ";
        for (int i = 0; i < 5; i++) {
            cout << grades[i] << " ";
            average += grades[i];
        }
        average /= 5;
        cout << endl << "The average is: " << average << endl;
    }
};

int main() {
    Student student;
    student.getGrade();
    student.calculateAverage();
    return 0;
}
