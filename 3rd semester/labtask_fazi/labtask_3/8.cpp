#include <iostream>
#include <string>
using namespace std;

const int categories = 3;
const int familyMembers = 2;

string familyMemberNames[familyMembers];
string categoryNames[categories] = {"Stationary", "Ticket", "Indrive"};

int main() {
    float expenses[familyMembers][categories];

    cout << "Enter the names of " << familyMembers << " family members:" << endl;
    for (int i = 0; i < familyMembers; i++) {
        cout << "Family member " << i + 1 << ": ";
        cin >> familyMemberNames[i];
    }

    for (int i = 0; i < familyMembers; i++) {
        cout << "Enter monthly expenses for " << familyMemberNames[i] << ":" << endl;
        for (int j = 0; j < categories; j++) {
            cout << "Enter expenses for " << categoryNames[j] << ": Rs";
            cin >> expenses[i][j];
        }
    }

    cout << endl << "Monthly Expenses:" << endl;
    for (int i = 0; i < familyMembers; i++) {
        cout << "Expenses for " << familyMemberNames[i] << ":" << endl;
        for (int j = 0; j < categories; j++) {
            cout << categoryNames[j] << ": Rs" << expenses[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
