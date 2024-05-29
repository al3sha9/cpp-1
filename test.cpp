#include <iostream>
using namespace std;

int findNum(int arr[], int total, int toFind)
{
    for (int a = 0; a < total; a++)
    {
        if (arr[a] == toFind)
        {
            return a;
        }
    }

    return -1;
}

int main()
{
    int n = 5;
    int arr[n] = {23, 45, 78, 12, 99};

    int toFind;
    cout << "enter a number to find in array" << endl;
    cin >> toFind;

    cout << findNum(arr, n, toFind);

    return 0;
}