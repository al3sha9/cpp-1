#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+c)/2;

    int len1 = mid - s +1;
    int len2 = e - mid;

    //first array and second array created

    int *first = new int[len1];
    int *second = new int[len2];

    //copying the array start to mid
    int k = s; //k se start se shuru horhi

    for(int i = 0; i<len1; i++){
        first[i] = arr[k++];
    }
    //second array copy mid+1 to end
    int k = mid+1;
    for(int i = 0; i<len2; i++){
        second[i]=arr[k++];
    }

    //merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;

    k = s;
    while(index1<len1 && index2<len2){
        if(first[index]<second[index]){
            arr[k]=first[index1++];
        }
        else{
            arr[k] = second[index2++];
        }
    }
    while(index1<len1){
        arr[k]=first[index1++];
    }
    while(index2<len2){
        arr[k] = second[index2++];        
    }
}
void mergeSort(){

}
int main(){
    
}