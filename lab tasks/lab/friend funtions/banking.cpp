#include<iostream>
#include<string>
using namespace std;

class BankAccount{
    private:
    int accountNumber, balance;
    string name;

    public:
    BankAccount(int accountNumber, int balance, string name){
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->name = name;
    }
    friend void transferAmount(BankAccount obj1, BankAccount obj2);

    void displayUpdatedBalance(){

    }
};
void transferAmount(BankAccount obj1, BankAccount obj2){
    int amount;
    obj1.accountNumber = 11999;
    obj1.balance = 3000;
    obj1.name = "Fazila";

    obj2.accountNumber = 12290;
    obj2.balance = 0;
    obj2.name = "Roshan";

    cout<<"Enter the amount you want to transfer to obj2: ";
    cin>>amount;
    obj1.balance - amount;

    
}
int main(){

}