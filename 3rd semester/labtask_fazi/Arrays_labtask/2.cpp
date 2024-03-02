// Create a program to manage a product inventory. Use an array to store product details
// such as name, price, and quantity.

#include<iostream>
using namespace std;

int main(){
    int price[3] = {20, 30, 40};
    string name[3] = {"Colors", "Pencils", "Marker"};
    int quantity[3] =  {1, 2, 3};

    cout<<"The products are: "<<endl;
    cout<<"Name\t\tPrice\t\tQuantity"<<endl;
    for(int i=0; i<3; i++){
        cout<<name[i]<<"\t\t"<<price[i]<<"\t\t"<<quantity[i]<<endl;
    }
    
}