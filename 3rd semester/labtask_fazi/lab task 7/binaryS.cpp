#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int searchValue){
    int low = 0;
    int high = size - 1;

    while(low<=high){
        int mid = (low+high)/2;
    if(searchValue==arr[mid]){
        return mid;
    }
    else if(searchValue>mid){
        low = mid+1;
    }
    else
        high = mid-1;
    }
    //if not found
    return -1;
}
int main(){
    int arr[] = {2, 3 , 55, 66,88,99,100};
    int userValue;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the number to be found: ";
    cin>>userValue;
    int result = binarySearch(arr, size, userValue);
    if(result>=0){
        cout<<"The number "<<arr[result]<<"was found at index "<<result<<endl;
    }
    else{
        cout<<"The number was not found"<<endl;
    }
}
