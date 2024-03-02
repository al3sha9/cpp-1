#include <iostream>
#include <string>
using namespace std;

const int sizeOfBoard = 3;

int main() {
    char ticTacToe[sizeOfBoard][sizeOfBoard]; 
    for (int i = 0; i < sizeOfBoard; i++) {
        for (int j = 0; j < sizeOfBoard; j++) {
            ticTacToe[i][j] = ' ';
        }
    }

    cout << "Tic-Tac-Toe Board:" << endl;
    for (int i = 0; i < sizeOfBoard; i++) {
        // Horizontal lines
        if (i != 0) {
            cout << "-------------" << endl;
        }
        for (int j = 0; j < sizeOfBoard; j++) {
            // Vertical lines
            if (j != 0) {
                cout << "|";
            }
            cout << " " << ticTacToe[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
