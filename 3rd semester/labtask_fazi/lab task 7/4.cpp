#include <iostream>
using namespace std;

int floor(int n[], int size, int t) {
    int left = 0, right = size - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (n[mid] == t) {
            return t;
        } else if (n[mid] < t) {
            floor = n[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return floor;
}

int ceil(int n[], int size, int t) {
    int left = 0, right = size - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (n[mid] == t) {
            return t;
        } else if (n[mid] < t) {
            left = mid + 1;
        } else {
            ceil = n[mid];
            right = mid - 1;
        }
    }

    return ceil;
}

int main() {
    int n[] = {1, 4, 6, 8, 9};
    int size = sizeof(n) / sizeof(n[0]);

    for (int i = 0; i <= 10; ++i) {
        cout << "Number " << i << " --> ceil is " << ceil(n, size, i) << ", floor is " << floor(n, size, i) <<endl;
    }

    return 0;
}