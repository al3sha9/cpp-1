#include <iostream>
#include <string>
using namespace std;

const int days = 5;
const int subjects = 5;
const string subjectNames[subjects] = {"English", "Maths", "Science", "Physics", "Urdu"};

int main() {
    string timetable[days][2]; 
    for (int i = 0; i < days; i++) {
        cout << "Enter subjects for Day " << i + 1 << ":" << endl;
        for (int j = 0; j < 2; j++) {
            cout << "Subject " << j + 1 << ": ";
            getline(cin, timetable[i][j]);
        }
    }
    cout << "\nTimetable:" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ":" << endl;
        for (int j = 0; j < 2; j++) {
            cout << "   " << timetable[i][j] << endl;
        }
        cout << "-----------------------------------" << endl;
    }

    return 0;
}
