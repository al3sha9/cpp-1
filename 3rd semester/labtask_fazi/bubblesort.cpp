#include<iostream>
using namespace std;
//Bubble Sort - 
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n){
    for (int i = 0; i<n-1; i++){
        for(int j = 0; j<n - i - 1; j++){ //j<n - i - 1; 
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void print(int arr[], int size){
    for(int i= 0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]= {33 ,9, 2, 40, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    print(arr,size);
    
}