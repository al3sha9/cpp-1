#include <iostream>
#include <string>
using namespace std;

const int sizeOfBoard = 8; // Chess board is 8x8

int main() {
    char chessBoard[sizeOfBoard][sizeOfBoard] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}, 
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    cout << "**Chess Board**\n" << endl;
    for (int i = 0; i < sizeOfBoard; i++) {
        if (i != 0) {
            cout << "--------------------------------" << endl;
        }
        for (int j = 0; j < sizeOfBoard; j++) {
            if (j != 0) {
                cout << "|";
            }
            cout << " " << chessBoard[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
