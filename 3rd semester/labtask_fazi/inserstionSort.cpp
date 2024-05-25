#include<iostream>
using namespace std;


// insertion sort
// we will always consider the second element 
// also called (in-place) sprting
//  
void insertionSort(int arr[], int size) {
    int j, key; // key temporarily hold the *value* of the element 
    // j *track the current index* being compared
    for (int i = 1; i < size; i++) {  // outer loop - start from the second element - iterates through each element of the array until i < size.
        key = arr[i]; // assigned the value of the *current element* arr[i]
        j = i - 1; // index of the last element of the currently sorted portion of the array.
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
