#include <iostream>

using namespace std;

int find_first(int n[], int size, int t) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (n[mid] >= t) {
            right = mid - 1;
            if (n[mid] == t) {
                result = mid;
            }
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int find_last(int n[], int size, int t) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (n[mid] <= t) {
            left = mid + 1;
            if (n[mid] == t) {
                result = mid;
            }
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int count(int nums[], int size, int target) {
    int first = find_first(nums, size, target);
    int last = find_last(nums, size, target);
    
    if (first != -1 && last != -1) {
        return last - first + 1;
    } else {
        return 0;
    }
}

int main() {
    int n[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int n2[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int size = sizeof(n) / sizeof(n[0]);
    int t = 5;

    int oc = count(n, size, t);
    cout << "Target " << t << " occurs " << oc << " times" << endl;

    t = 6;
    oc = count(n2, size, t); 
    cout << "Target " << t << " occurs " << oc << " times" << endl;

    return 0;
}
