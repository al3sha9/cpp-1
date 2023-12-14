#include<iostream>
#include<string>
using namespace std;

class AccountHolder{
    protected:
    string name;
    int AccountNumber;
    public:
    void displayInfo(){
        cout<<"Account holder name: "<<name<<endl;
        cout<<"Account number: "<<AccountNumber<<endl;
    }
};
class SavingsAccount{
    protected:
     double balance, interestRate;
    public:
     void calculateInterest(){
            // interestRate = p*rate*tenure;
     }
};
class CurrentAccount{
    protected:
     double balance, overDraftLimit;
    public:
    void applyOverdraft(){
        cout<<"You are overdrafting the money."<<endl;
    } 

};
class BankAccount :public SavingsAccount, public CurrentAccount{

};
int main(){
    BankAccount bankAccountObject;
        bankAccountObject.calculateInterest();
        bankAccountObject.applyOverdraft();
}