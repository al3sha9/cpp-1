#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book {
public:
    string bookTitle;
    string authorName;
    int publicationYear;

    Book(string title, string author, int year) {
        this->bookTitle = title;
        this->authorName = author;
        this->publicationYear = year;
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
            cout << "Title: " << book.bookTitle << endl;
            cout << "Author: " << book.authorName << endl;
            cout << "Year: " << book.publicationYear << endl << endl;
        }
    }

    void searchBookByTitle(string title) {
        cout << "Searching for book with title: " << title << endl;
        bool found = false;
        for (const auto& book : books) {
            if (book.bookTitle == title) {
                cout << "Book found:\n";
                cout << "Title: " << book.bookTitle << endl;
                cout << "Author: " << book.authorName << endl;
                cout << "Year: " << book.publicationYear << endl;
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
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
    library.addBook(Book("Famous Five", "ABC", 1960));
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 1813));

    library.displayAllBooks();
    library.searchBookByTitle("Famous Five");

    return 0;
}
