#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    string accName;
    int accNum;
    string accType;
    double balance;

public:
    Bank(string name, int num, string type, double bal)
    {
        accName = name;
        accNum = num;
        accType = type;
        balance = bal;
    }

    void addBal(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount " << amount << "has been added to account" << endl;
            cout << "New balance" << balance << endl;
        }
        else
        {
            cout << "Invalid Amount entered" << endl;
        }
    }

    void remBal(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Amount " << amount << "has been removed to account" << endl;
            cout << "New balance" << balance << endl;
        }
        else if (amount > 0 && balance < amount)
        {
            cout << "Insufficient balance" << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
    void disAcc()
    {
        cout << "Account Name: " << accName << endl;
        cout << "Account Number: " << accNum << endl;
        cout << "Account Type: " << accType << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    string name;
    int num;
    string type;
    double bal;

    cout << "Enter Account Name: ";
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> num;

    cin.ignore(); // Clear the newline character left in the input buffer

    cout << "Enter Account Type: ";
    getline(cin, type);

    cout << "Enter Initial Balance: ";
    cin >> bal;

    Bank acc(name, num, type, bal);

    acc.disAcc();

    double addAmount, removeAmount;

    cout << "Enter amount to add: ";
    cin >> addAmount;
    acc.addBal(addAmount);

    cout << "Enter amount to remove: ";
    cin >> removeAmount;
    acc.remBal(removeAmount);

    return 0;
}