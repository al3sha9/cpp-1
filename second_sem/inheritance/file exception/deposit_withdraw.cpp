#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
    double balance = 1000.0;
    try{
        double amount;
        //depost amount
        cout<<"Enter the amount you want to deposit:";
        cin>>amount;
        if(amount<=0){
            throw invalid_argument("invalid deposit amount!");
        }
        balance = balance + amount;
        cout<<"Available amount: "<<balance<<endl;

        //withdraw
        cout<<"Enter the amount you want to withdraw: ";
        cin>>amount;
        if(amount<= 0){
            throw invalid_argument("invalid withdraw amount1");
        }
        if(amount>balance){
            throw runtime_error("Insuffient balance!");
            balance = balance - amount;
            cout<<"Available balance: "<<balance<<endl;
        }
    }
    catch(exception& e){
        cout<<e.what()<<endl;
    }
}