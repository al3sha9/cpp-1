#include<iostream>
#include<string>
using namespace std;

class AccountHolder {
protected:
    string name;
    int accountNumber;

public:
    void displayInfo() {
        cout << "Account holder name: " << this->name << endl;
        cout << "Account number: " << this->accountNumber << endl;
    }
};

class SavingsAccount {
protected:
    double savingsBalance;
    double interestRate;

public:
    void calculateInterest() {
        cout << "Calculating interest for Savings Account" << endl;
    }
};

class CurrentAccount {
protected:
    double currentBalance;  
    double overdraftLimit;

public:
    void applyOverdraft() {
        cout << "Applying overdraft for Current Account" << endl;
    }
};

class BankAccount : public SavingsAccount, public CurrentAccount, public AccountHolder {
public:
    void displayBankInfo() {
        displayInfo();
        cout << "Savings Account Balance: " << this->savingsBalance << endl;
        cout << "Interest Rate: " << this->interestRate << endl;
        cout << "Current Account Balance: " << this->currentBalance << endl;
        cout << "Overdraft Limit: " << this->overdraftLimit << endl;
    }

    
    BankAccount(string name, int accountNumber, double savingsBalance, double interestRate, double currentBalance, double overdraftLimit)
        : AccountHolder(), SavingsAccount(), CurrentAccount() {
        this->name = name;
        this->accountNumber = accountNumber;
        this->savingsBalance = savingsBalance;
        this->interestRate = interestRate;
        this->currentBalance = currentBalance;
        this->overdraftLimit = overdraftLimit;
    }
};

int main() {
    BankAccount bankAccountObject("John Doe", 123456, 1000.0, 0.02, 500.0, 200.0);

    bankAccountObject.displayBankInfo();
    bankAccountObject.calculateInterest();
    bankAccountObject.applyOverdraft();

    return 0;
}
