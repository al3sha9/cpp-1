#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream file6;
class BookDetails{
    string title, author;
    int ISBN;

    public:
    BookDetails(string t, string a, int i):title(t), author(a), ISBN(i){}

    void addBook{
        file6.open("file6.txt", ios::out | ios::app);
        if (!file5.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        else{
        cout<<"Enter the book name you want to add: ";
        cin>>title;
        file6<<title;
        cout<<"Enter the book author: ";
        cin>>author;
        file6<<author;
        cout<<"Enter the ISBN number: ";
        cin>>ISBN;
        file6<<ISBN;
        }
       
        file6.close();
    }
    void searchBook{

    }
    void deleteBookfromCatalog{

    }

};
int main(){
    BookDetails bookObject;
    int choice;
    switch (choice)
    {
    case 1:
        bookObject.addBook();
        break;
    case 2: 
        bookObject.searchBook();
        break;
    case 3: 
        bookObject.deleteBookfromCatalog();
        break;   
    default:
        cout<<"Invalid choice!";
        break;
    }
}

