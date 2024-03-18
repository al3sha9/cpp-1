#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;
    string publisher;
    int year;

    Book(string title, string author, int pages, string publisher, int year) {
        this->title = title;
        this->author = author;
        this->pages = pages;
        this->publisher = publisher;
        this->year = year;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    void displayAllBooks() {
        cout << "Library Books:\n";
        for (const auto& book : books) {
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Pages: " << book.pages << endl;
            cout << "Publisher: " << book.publisher << endl;
            cout << "Year: " << book.year << endl << endl;
        }
    }

    void searchBookByTitle(string title) {
        cout << "Searching for book with title: " << title << endl;
        bool found = false;
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found:\n";
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Pages: " << book.pages << endl;
                cout << "Publisher: " << book.publisher << endl;
                cout << "Year: " << book.year << endl;
                found = true;
                break; 
            }
        }
        if (!found) {
            cout << "Book with title '" << title << "' not found." << endl;
        }
    }
};

int main() {
    Library library;
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 180, "Scribner", 1925));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 281, "J. B. Lippincott & Co.", 1960));
    library.addBook(Book("1984", "George Orwell", 328, "Secker & Warburg", 1949));

    library.displayAllBooks();
    library.searchBookByTitle("1984");

    return 0;
}
