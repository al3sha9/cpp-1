#include <iostream>

using namespace std;

int smallest(int n[], int size) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (n[mid] != mid) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int inputs[][7] = {
        {0, 1, 2, 6, 9, 11, 15},  
        {1, 2, 3, 4, 6, 9, 11},  
        {0, 1, 2, 3, 4, 5, 6} 
    };

    for (int i = 0; i < 3; ++i) {
        int size = sizeof(inputs[i]) / sizeof(inputs[i][0]);
        int smallestMissing = smallest(inputs[i], size);
        cout << "For input " << i + 1 << ", ";
        cout << "The smallest missing element is " << smallestMissing << endl;
    }

    return 0;
}
