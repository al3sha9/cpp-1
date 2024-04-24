#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int element) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    
    int element = 6;
    int index = binarySearch(arr, size, element);
    if (index != -1)
        cout << "Element " << element << " found at index " << index;
    else
        cout << "Element " << element << " not found";
        
    return 0;
}
