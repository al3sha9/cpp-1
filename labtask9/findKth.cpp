#include <iostream>
#include <queue>

using namespace std;

int find(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        if (minHeap.size() < k) {
            minHeap.push(arr[i]);
        } else {
            if (arr[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
    }

    return minHeap.top();
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "The " << k << "th largest element is: " << find(arr, 6, k) << endl;

    return 0;
}
