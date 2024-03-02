#include<iostream>
using namespace std;

int main(){
    int grades[5], average = 0;
    cout<<"Enter the grades of five subjects: "<<endl;
    
    for (int i = 0; i < 5; i++){
        cin>>grades[i];
    }
    cout<<"The grades are: ";
    for (int i = 0; i < 5; i++){
        cout << grades[i] << " ";
        average += grades[i];
    }
    average /= 5;
    cout<<endl<<"The average is: "<<average<<endl;

    return 0;
}
