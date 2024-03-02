#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class BookLibrary {
private: 
    string title[3];
    string author[3];
    bool available[3];

public:
    BookLibrary() {
        int i = 0;
        while (i < 3) {
            cout << "Enter details for book " << i + 1 << ":" << endl;
            cout << "Title: ";
            getline(cin >> ws, title[i]);
            cout << "Author: ";
            getline(cin >> ws, author[i]);
            cout << "Availability (1 for available, 0 for not available): ";
            cin >> available[i];
            i++;
        }
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
    BookLibrary object;
    object.displayBooks();
    return 0;
}
