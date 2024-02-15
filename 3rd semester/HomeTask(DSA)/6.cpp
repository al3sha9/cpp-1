// 6. Bank Account: Create a basic bank account program. 
// Define a class BankAccount with attributes account number, balance, and account holder name.
// Implement methods to deposit and withdraw money and display account details.
#include<iostream>
using namespace std;

class BankAccount{
    private:
    int accountNumber;
    float balance;
    string name;

    public:
    int amountDep, amountW;
    BankAccount(int accountNumber, float balance, string name){
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->name = name;
    }
    void deposit(){
        cout<<"Enter the amount you want to deposit:";
        cin>>amountDep;
        balance+=amountDep;
   }
    void withdraw(){
        cout<<"Enter the amount you want to withdraw:";
        cin>>amountW;
        balance-=amountW;
    }
    void display(){
        cout<<"Amount in account: "<<balance<<endl;
        cout<<"Amount deposited: "<<amountDep<<endl;;
        cout<<"Amount withdrawed: "<<amountW<<endl;;
        cout<<"Name of the account holder: "<<name<<endl;;
        cout<<"Account Number: "<<accountNumber<<endl;;
    }
};
int main(){
    BankAccount b1(1223333, 2000.02, "fazila");
    b1.deposit();
    b1.withdraw();
    b1.display();
}