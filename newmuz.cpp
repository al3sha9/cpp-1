#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
int main()
{

    // sorry for the multiple couts sir, my backslash was not working.
    char arr[8][8] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
        'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
    int k, l;
    char piece;
    cout << "Type the piece you want to find the index of" << endl;
    cin >> piece;
    for (k = 0; k < 8; k++)
    {
        for (l = 0; l < 8; l++)
        {
            if (arr[k][l] == piece)
            {
                break;
            }
        }
        if (l < 8)
        {
            break;
        }
    }

    if (k < 8 && l < 8)
    {
        cout << "location = [" << k << ", " << l << "]" << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}