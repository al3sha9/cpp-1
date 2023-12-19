#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream file5;

class StudentGrades {
public:
    int a, b, c, i;

    void add_new_grades() {
        file5.open("file.txt", ios::out); // Use ios::app to append to the file
        if (!file5.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        cout << "Enter three subjects grades: " << endl;
        cin >> a >> b >> c;
        file5 << a << " " << b << " " << c << endl;
        cout << "Grades have been stored!" << endl;

        file5.close();
    }

    void calculate_average_grades() {
        int calculate;
        file5.open("file.txt", ios::in);
        if (!file5.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        file5 >> a >> b >> c;
        calculate = (a + b + c) / 3;
        cout << "Average grade: " << calculate << endl;

        file5.close();
    }

    void display_highest_lowest_grades() {
        file5.open("file.txt", ios::in);
        if (!file5.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        file5 >> a >> b >> c;
        if (a > b && a > c) {
            cout << a << " is the highest grade!" << endl;
        } else if (b > a && b > c) {
            cout << b << " is the highest grade!" << endl;
        } else {
            cout << c << " is the highest grade!" << endl;
        }

        file5.close();
    }
};

int main() {
    StudentGrades object;
    int choice;
    cout << "1. Add Grades 2. Calculate Average 3. Display Highest and Lowest Grade ";
    cin >> choice;

    switch (choice) {
    case 1:
        object.add_new_grades();
        break;
    case 2:
        object.calculate_average_grades();
        break;
    case 3:
        object.display_highest_lowest_grades();
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}
