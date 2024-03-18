#include <iostream>
#include <string>
using namespace std;

const int month = 1;
const int col = 7;
const int row = 6;
const string february[month] = {"February"};

int main() {
    int calendar[row][col];

    int day = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((i == 0 && j >= 1) || (i > 0 && day <= 28)) {
                calendar[i][j] = day;
                day++;
            } else {
                calendar[i][j] = 0;
            }
        }
    }

    cout << february[0] << " Calendar:" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (calendar[i][j] == 0) {
                cout << "    ";
            } else {
                cout << (calendar[i][j] < 10 ? " " : "") << calendar[i][j] << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}

