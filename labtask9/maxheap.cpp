#include <iostream>
using namespace std;

#define MAX 1000

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert_max_heap(int arr[], int& n, int Key)
{
    n = n + 1;
    arr[n - 1] = Key;
    heapify(arr, n, n - 1);
}

void delete_max_heap(int arr[], int& n)
{
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    heapify(arr, n, 0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[MAX] = { 10, 5, 3, 2, 4 };
    int n = 5;
    int key = 15;
    insert_max_heap(arr, n, key);
    printArray(arr, n);
    return 0;
}
