#include <iostream>

using namespace std;

void occurance(int n[], int size, int t) {
    int first = -1;
    int last = -1;
    
    for (int i = 0; i < size; ++i) {
        if (n[i] == t) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    
    if (first != -1) {
        cout << "The first occurrence of element " << t << " is located at index " << first << endl;
        cout << "The last occurrence of element " << t << " is located at index " << last << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }
}

int main() {
    int n[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int size = sizeof(n) / sizeof(n[0]);
    int target = 5;
    
    occurance(n, size, target);
    
    return 0;
}
