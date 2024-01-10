#include<iostream>
#include<string>
#include<fstream>
using namespace std;

fstream file6;

class BookDetails {
    string title, author;
    int ISBN;

public:
    BookDetails(string t, string a, int i) : title(t), author(a), ISBN(i) {}

    void addBook() {
        file6.open("file6.txt", ios::out | ios::app);
        if (!file6.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }
        else {
            cout << "Enter the book name you want to add: ";
            cin.ignore();
            getline(cin, title);
            file6 << title << endl;
            
            cout << "Enter the book author: ";
            getline(cin, author);
            file6 << author << endl;

            cout << "Enter the ISBN number: ";
            cin >> ISBN;
            file6 << ISBN << endl;
        }

        file6.close();
    }

    void searchBook() {
        file6.open("file6.txt", ios::in);
        if (!file6.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        int searchISBN;
        cout << "Enter the ISBN number to search: ";
        cin >> searchISBN;

        string line;
        bool found = false;
        while (getline(file6, line)) {
            if (stoi(line) == searchISBN) {
                found = true;
                cout << "Book found!" << endl;
                getline(file6, line);  // Read and print the title
                cout << "Title: " << line << endl;
                getline(file6, line);  // Read and print the author
                cout << "Author: " << line << endl;
                break;
            }
        }

        if (!found) {
            cout << "Book not found!" << endl;
        }

        file6.close();
    }

    void deleteBookfromCatalog() {
        file6.open("file6.txt", ios::in);
        ofstream tempFile("temp.txt", ios::out);

        if (!file6.is_open() || !tempFile.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        int deleteISBN;
        cout << "Enter the ISBN number to delete: ";
        cin >> deleteISBN;

        string line;
        bool found = false;
        while (getline(file6, line)) {
            if (stoi(line) == deleteISBN) {
                found = true;
                cout << "Book deleted!" << endl;
                getline(file6, line);  
                getline(file6, line);  
            }
            else {
                tempFile << line << endl; 
            }
        }

        if (!found) {
            cout << "Book not found!" << endl;
        }

        file6.close();
        tempFile.close();

    
        remove("file6.txt");
        rename("temp.txt", "file6.txt");
    }
};

int main() {
    BookDetails bookObject("DefaultTitle", "DefaultAuthor", 0);
    int choice;

    cout << "1. Add Book\n2. Search Book\n3. Delete Book\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
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
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}
