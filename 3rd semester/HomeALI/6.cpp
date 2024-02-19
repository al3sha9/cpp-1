#include<iostream>
using namespace std;

class BankAccount{
private:
    int accountNumber;
    float balance;
    string name;

public:
    BankAccount(int accountNumber, float balance, string name){
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->name = name;
    }
    void deposit(float amount){
        balance += amount;
    }
    void withdraw(float amount){
        if(balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
    void display(){
        cout << "Name of the account holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Amount in account: " << balance << endl;
    }
};

int main(){
    BankAccount b1(10101010, 5000.0, "ali");

    float depositAmount, withdrawAmount;
    cout << "Enter the amount you want to deposit: ";
    cin >> depositAmount;
    b1.deposit(depositAmount);

    cout << "Enter the amount you want to withdraw: ";
    cin >> withdrawAmount;
    b1.withdraw(withdrawAmount);

    b1.display();
    return 0;
}
