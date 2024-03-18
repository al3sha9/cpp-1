#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
    int total_students = 2;
    string name[total_students] = {"Ali", "Alishan"};
    string course[total_students] = {"Math", "English"};
    int ID[total_students] = {0};

    cout << "Enter the details of " << total_students << " students:" << endl;

    for(int i = 0; i < total_students; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> ID[i];
    }

    cout << endl;
    cout << "Details: " << endl;

    for(int i = 0; i < total_students; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: " << name[i] << endl;
        cout << "ID: " << ID[i] << endl;
        cout << "Course: " << course[i] << endl;
        cout << endl;
    }

    return 0;
}
