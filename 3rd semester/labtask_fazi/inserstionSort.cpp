#include<iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    int j, key;
    for (int i = 1; i < size; i++) {  // Start from the second element
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 34, 2, 7, 20};  // Properly initialize the array
    int size = sizeof(arr) / sizeof(arr[0]);

    print(arr, size);  // Print the array before sorting
    insertionSort(arr, size);  // Sort the array
    print(arr, size);  // Print the array after sorting

    return 0;
}
