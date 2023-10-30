#include <iostream>
#include <string>

using namespace std;

class Publication
{
private:
    string title;
    string author;
    int quantity;

public:
    Publication() : title(""), author(""), quantity(0) {}

    Publication(string title, string author, int quantity)
        : title(title), author(author), quantity(quantity) {}

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    int getQuantity() const
    {
        return quantity;
    }

    void setQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }

    void displayInfo() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

class Patron
{
private:
    string name;
    string contactDetails;

public:
    Patron() : name(""), contactDetails("") {}

    Patron(string name, string contact) : name(name), contactDetails(contact) {}

    string getName() const
    {
        return name;
    }

    string getContactDetails() const
    {
        return contactDetails;
    }

    void setContactDetails(string contact)
    {
        contactDetails = contact;
    }

    void displayInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Contact Details: " << contactDetails << endl;
    }
};

class Transaction
{
private:
    Patron patron;
    Publication publication;
    bool returned;

public:
    Transaction() : patron(Patron()), publication(Publication()), returned(false) {}

    Transaction(Patron p, Publication pub) : patron(p), publication(pub), returned(false) {}

    Patron getPatron() const
    {
        return patron;
    }

    Publication getPublication() const
    {
        return publication;
    }

    bool isReturned() const
    {
        return returned;
    }
};

class Inventory
{
private:
    static const int MAX_PUBLICATIONS = 100;
    Publication publications[MAX_PUBLICATIONS];
    int numPublications;

public:
    Inventory() : numPublications(0) {}

    void addPublication(string title, string author, int quantity)
    {
        if (numPublications < MAX_PUBLICATIONS)
        {
            publications[numPublications++] = Publication(title, author, quantity);
            cout << "Publication added successfully." << endl;
        }
        else
        {
            cout << "Inventory is full. Cannot add more publications." << endl;
        }
    }

    int getNumPublications() const
    {
        return numPublications;
    }

    const Publication *getPublication(int index) const
    {
        if (index >= 0 && index < numPublications)
        {
            return &publications[index];
        }
        else
        {
            return nullptr;
        }
    }
};

class LibrarySystem
{
private:
    Inventory inventory;
    Patron patrons[100];
    Transaction transactions[100];

public:
    void addPublication(string title, string author, int quantity)
    {
        inventory.addPublication(title, author, quantity);
    }

    void addPatron(string name, string contact)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (patrons[i].getName().empty())
            {
                patrons[i] = Patron(name, contact);
                cout << "Patron added successfully." << endl;
                break;
            }
        }
    }

    void borrowBook(string title, string patronName)
    {
        Publication book;
        Patron borrower;

        for (int i = 0; i < inventory.getNumPublications(); ++i)
        {
            if (inventory.getPublication(i)->getTitle() == title)
            {
                book = *inventory.getPublication(i);
                break;
            }
        }

        for (int i = 0; i < 100; ++i)
        {
            if (patrons[i].getName() == patronName)
            {
                borrower = patrons[i];
                break;
            }
        }

        bool foundEmptySlot = false;
        for (int i = 0; i < 100; ++i)
        {
            if (transactions[i].getPublication().getTitle().empty())
            {
                transactions[i] = Transaction(borrower, book);
                foundEmptySlot = true;
                cout << "Book borrowed successfully." << endl;
                break;
            }
        }

        if (!foundEmptySlot)
        {
            cout << "Transaction slots are full. Cannot complete the transaction." << endl;
        }
    }

    void returnBook(string title)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (transactions[i].getPublication().getTitle() == title)
            {
                transactions[i].getPublication().setQuantity(transactions[i].getPublication().getQuantity() + 1);
                transactions[i].getPatron().setContactDetails("Returned");
                transactions[i] = Transaction(Patron(), Publication());
                cout << "Book returned successfully." << endl;
                return;
            }
        }

        cout << "Book not found in the borrowed list." << endl;
    }

    void generateAvailableBooksReport() const
    {
        cout << "Available Books Report:" << endl;
        for (int i = 0; i < inventory.getNumPublications(); ++i)
        {
            const Publication *pub = inventory.getPublication(i);
            if (pub)
            {
                cout << "Title: " << pub->getTitle() << endl;
                cout << "Author: " << pub->getAuthor() << endl;
                cout << "Quantity: " << pub->getQuantity() << endl;
                cout << "----------------------------------------" << endl;
            }
        }
    }

    void generateBorrowedBooksReport() const
    {
        cout << "Borrowed Books Report:" << endl;
        for (int i = 0; i < 100; ++i)
        {
            const Transaction &transaction = transactions[i];
            if (!transaction.getPublication().getTitle().empty() && !transaction.getPatron().getName().empty())
            {
                const Publication &pub = transaction.getPublication();
                const Patron &patron = transaction.getPatron();
                cout << "Title: " << pub.getTitle() << endl;
                cout << "Author: " << pub.getAuthor() << endl;
                cout << "Borrower: " << patron.getName() << endl;
                cout << "Contact Details: " << patron.getContactDetails() << endl;
                cout << "----------------------------------------" << endl;
            }
        }
    }
};

int main()
{
    LibrarySystem library;

    int choice;

    while (true)
    {
        cout << "\n__________________\n\n";
        cout << "Library Management System" << endl;
        cout << "1. Add Publication\n2. Add Patron\n3. Borrow Book\n4. Return Book\n5. Generate Available Books Report\n6. Generate Borrowed Books Report\n7. Exit" << endl;
        cout << "\n__________________\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            int quantity;

            cout << "Enter publication title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter quantity: ";
            cin >> quantity;

            library.addPublication(title, author, quantity);
            break;
        }
        case 2:
        {
            string name, contact;

            cout << "Enter patron name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter contact details: ";
            getline(cin, contact);

            library.addPatron(name, contact);
            break;
        }
        case 3:
        {
            string bookTitle, patronName;

            cout << "Enter book title to borrow: ";
            cin.ignore();
            getline(cin, bookTitle);
            cout << "Enter patron name: ";
            getline(cin, patronName);

            library.borrowBook(bookTitle, patronName);
            break;
        }
        case 4:
        {
            string bookTitle;

            cout << "Enter book title to return: ";
            cin.ignore();
            getline(cin, bookTitle);

            library.returnBook(bookTitle);
            break;
        }
        case 5:
            library.generateAvailableBooksReport();
            break;
        case 6:
            library.generateBorrowedBooksReport();
            break;
        case 7:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
