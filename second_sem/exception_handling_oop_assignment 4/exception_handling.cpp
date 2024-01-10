#include<iostream>
using namespace std;

int main(){
    int numerator, demonimator, result;
    cout<<"Enter the values for numerator and denominator ";
    cin>>numerator>>demonimator;

   try{
     if(demonimator == 0){
        throw demonimator;
     }
     result = numerator / demonimator;
   }
   catch(int ex){
    cout<<"exception!!! No zero allowed in the denominator!"<<endl;
   }
    cout<<"Result: "<<result<<endl;
}