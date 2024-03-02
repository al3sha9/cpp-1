#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Library {
private: 
    string title[3];
    string author[3];
    bool available[3];
public:
    Library() {
        title[0] = "Hello World";
        author[0] = "John";
        available[0] = true;

        title[1] = "Cpp";
        author[1] = "Mack";
        available[1] = false;

        title[2] = "Maths";
        author[2] = "AB.h";
        available[2] = true;
    }

    void displayBooks() {
        cout << "Book Inventory:" << endl;
        cout << setw(20) << "Title" << setw(20) << "Author" << setw(20) << "Availability" << endl;
        for(int i = 0; i < 3; i++) {
            cout << setw(20) << title[i] << setw(20) << author[i] << setw(20);
            if(available[i])
                cout << "Available" << endl;
            else
                cout << "Not Available" << endl;
        }
    }
};

int main() {
    Library myLibrary;
    myLibrary.displayBooks();
    return 0;
}
