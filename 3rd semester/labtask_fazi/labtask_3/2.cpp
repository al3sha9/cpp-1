#include <iostream>
#include <string>
using namespace std;

const int students = 2;
const int subjects = 3;
string studentName[students];
string subjectName[subjects] = {"Maths", "Computer", "Physics"};

int main() {
    int grades[students][subjects];
    cout << "Enter the name of 2 students: ";
    for (int i = 0; i < students; i++) {
        cin >> studentName[i];
    }
    for (int i = 0; i < students; i++) {
        cout << "Grades for " << studentName[i] << " : " << endl;
        for (int j = 0; j < subjects; j++) {
            cout << "Enter grade for " << subjectName[j] << ": ";
            cin >> grades[i][j];
        }
    }
    for (int i = 0; i < students; i++) {
        cout << "Displaying grades of " << studentName[i] << " : " << endl;
        for (int j = 0; j < subjects; j++) {
            cout << subjectName[j] << ": " << grades[i][j] << endl;
        }
    }

    return 0;
}
