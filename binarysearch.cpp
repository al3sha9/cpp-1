#include <iostream>
using namespace std;

int binSearch(int arr[], int toFind, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == toFind)
        {
            return mid;
        }
        else if (arr[mid] < toFind)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int n = 5;
    int arr[n] = {23, 53, 65, 23, 90};

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int toFind;
    cout << "enter a number to find in array" << endl;
    cin >> toFind;

    cout << binSearch(arr, toFind, 0, 4) + 1;

    return 0;
}