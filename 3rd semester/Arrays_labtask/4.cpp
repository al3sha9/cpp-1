#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
    const int MAX_STUDENTS = 2;
    string name[MAX_STUDENTS], course[MAX_STUDENTS];
    int ID[MAX_STUDENTS];

    cout << "Enter the details of " << MAX_STUDENTS << " students:" << endl;

    for(int i = 0; i < MAX_STUDENTS; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name[i];
        cout << "ID: ";
        cin >> ID[i];
        cout << "Course: ";
        cin >> course[i];
    }

    cout << endl;
    cout << "Details: " << endl;

    for(int i = 0; i < MAX_STUDENTS; i++) {
        cout << name[i] << " " << ID[i] << " " << course[i] << endl;
    }

    return 0;
}
