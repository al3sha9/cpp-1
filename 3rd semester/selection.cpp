#include<bits/stdc++.h>
using namespace std;

//selection sort
//the algorithm continously selects smallest or largest number from insorted array
// and swaps it with the first element in the array
// first traversed from (0 to n-1)
// find min element
// replace the min with first element
// again, sequentially traversed find the min and swap with the second element in the array
// this process goes on..

// minIndex keeps track of the position of the smallest element in the remaining unsorted part 
// of the 
void selection(int arr[], int n){
    int minIndex;
    for(int i = 0; i<n; i++){
        minIndex = i; //minIndex ko update karte hain i ky.
        for(int j = i+1; j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[minIndex], arr[i]);
        }
    }
    
}
void print(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {33, 6, 12, 8, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    selection(arr, n);
    print(arr,n);
}