#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream file7;
class Transaction{
    private:
    string date;
    string description;
    double amount;

    public:
    friend void addTransaction(Transaction T);
    friend void displayHistory(Transaction H); 
};
void addTransaction(Transaction T){
    file7.open("file7.txt", ios::out| ios::app);
    if(!file7.is_open()){
        cout<<"File does not exist!";
    }
    else{
        cout<<"How much money withdraw? ";
        cin>>T.amount;
        file7<<T.amount<<endl;
        cout<<"Enter today's date: ";
        cin.ignore();  
        getline(cin, T.date);
        file7<<T.date<<endl;
        cout<<"For what purpose you withdraw this cash? Enter..";
        cin.ignore();  
        getline(cin, T.description);
        file7<<T.description<<endl;

        cout<<"Cash withdrawed "<<T.amount<<" !!"<<endl;
    }
    file7.close();
}
void displayHistory(Transaction T) {
    file7.open("file7.txt", ios::in);

    if (!file7.is_open()) {
        cout << "File does not exist!" << endl;
    } else {
        cout << "History: \n";
        while (file7 >> T.amount >> ws && getline(file7, T.date) && getline(file7, T.description)) {
            cout << "Amount: " << T.amount << endl;
            cout << "Date: " << T.date << endl;
            cout << "Description: " << T.description << endl;
        }
    }
    file7.close();
}


int main(){
    Transaction t;
    int choice;
    cout<<"1. Add Transaction 2. Display History ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        addTransaction(t);
        break;
    case 2:
        displayHistory(t);
        break;
    default:
        break;
    }
}