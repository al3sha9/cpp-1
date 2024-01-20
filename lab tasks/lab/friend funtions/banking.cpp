#include<iostream>
#include<string>
using namespace std;

class BankAccount {
private:
    int accountNumber, balance;
    string name;

public:
    BankAccount(int accountNumber, int balance, string name) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->name = name;
    }

    friend void transferAmount(BankAccount& obj1, BankAccount& obj2);

    void displayUpdatedBalance() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Updated Balance: " << balance << endl;
    }
};

void transferAmount(BankAccount& obj1, BankAccount& obj2) {
    int amount;
    
    cout << "Enter the amount you want to transfer to obj2: ";
    cin >> amount;

    if (obj1.balance >= amount) {
        obj1.balance -= amount;
        obj2.balance += amount;
        cout << "Amount transferred successfully." << endl;
    } else {
        cout << "Insufficient balance for the transfer." << endl;
    }
}

int main() {
    BankAccount account1(11999, 3000, "Fazila");
    BankAccount account2(12290, 0, "Roshan");
    cout << "Initial Balances:" << endl;
    account1.displayUpdatedBalance();
    account2.displayUpdatedBalance();
    transferAmount(account1, account2);
    cout << "Updated Balances:" << endl;
    account1.displayUpdatedBalance();
    account2.displayUpdatedBalance();

    return 0;
}
