#include <iostream>

using namespace std;

int sqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int left = 1, right = x;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x1 = 12;
    int x2 = 16;

    cout << "Input: x = " << x1 << endl;
    cout << "Output: " << sqrt(x1) << endl;

    cout << "Input: x = " << x2 << endl;
    cout << "Output: " << sqrt(x2) << endl;

    return 0;
}
