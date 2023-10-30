#include <iostream>
#include <string>

using namespace std;

class LibraryItem
{
public:
    string title;
    string author;
    int quantity;

    LibraryItem() : title(""), author(""), quantity(0) {}

    LibraryItem(string title, string author, int quantity)
        : title(title), author(author), quantity(quantity) {}

    void displayInfo() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Quantity: " << quantity << endl;
    }

    bool operator==(const LibraryItem &other) const
    {
        return (title == other.title) && (author == other.author);
    }
};

class LibraryMember
{
public:
    string name;
    string contactDetails;

    LibraryMember() : name(""), contactDetails("") {}

    LibraryMember(string name, string contact) : name(name), contactDetails(contact) {}

    void displayInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Contact Details: " << contactDetails << endl;
    }
};

class LibraryTransaction
{
public:
    LibraryMember member;
    LibraryItem item;
    bool returned;

    LibraryTransaction() : member(LibraryMember()), item(LibraryItem()), returned(false) {}

    LibraryTransaction(LibraryMember member, LibraryItem item) : member(member), item(item), returned(false) {}
};

class LibraryInventory
{
private:
    static const int MAX_ITEMS = 100;
    LibraryItem items[MAX_ITEMS];
    int numItems;

public:
    LibraryInventory() : numItems(0) {}

    void addItem(string title, string author, int quantity)
    {
        if (numItems < MAX_ITEMS)
        {
            items[numItems].title = title;
            items[numItems].author = author;
            items[numItems].quantity = quantity;
            cout << "Item added successfully." << endl;
            numItems++;
        }
        else
        {
            cout << "Inventory is full. Cannot add more items." << endl;
        }
    }

    int getNumItems() const
    {
        return numItems;
    }

    const LibraryItem *getItem(int index) const
    {
        if (index >= 0 && index < numItems)
        {
            return &items[index];
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
    LibraryInventory inventory;
    LibraryMember members[100];
    LibraryTransaction transactions[100];

public:
    void addItem(string title, string author, int quantity)
    {
        inventory.addItem(title, author, quantity);
    }

    void addMember(string name, string contact)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (members[i].name.empty())
            {
                members[i].name = name;
                members[i].contactDetails = contact;
                cout << "Member added successfully." << endl;
                break;
            }
        }
    }

    void borrowItem(string title, string memberName)
    {
        LibraryItem item;
        LibraryMember borrower;

        for (int i = 0; i < inventory.getNumItems(); ++i)
        {
            if (inventory.getItem(i)->title == title)
            {
                item = *inventory.getItem(i);
                break;
            }
        }

        for (int i = 0; i < 100; ++i)
        {
            if (members[i].name == memberName)
            {
                borrower = members[i];
                break;
            }
        }

        bool foundEmptySlot = false;
        for (int i = 0; i < 100; ++i)
        {
            if (transactions[i].item.title.empty())
            {
                transactions[i] = LibraryTransaction(borrower, item);
                foundEmptySlot = true;
                cout << "Item borrowed successfully." << endl;
                break;
            }
        }

        if (!foundEmptySlot)
        {
            cout << "Transaction slots are full. Cannot complete the transaction." << endl;
        }
    }

    void returnItem(string title)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (transactions[i].item.title == title)
            {
                transactions[i].item.quantity++;
                transactions[i].member.contactDetails = "Returned";
                transactions[i] = LibraryTransaction(LibraryMember(), LibraryItem());
                cout << "Item returned successfully." << endl;
                return;
            }
        }

        cout << "Item not found in the borrowed list." << endl;
    }

    void generateAvailableItemsReport() const
    {
        cout << "Available Items Report:" << endl;
        for (int i = 0; i < inventory.getNumItems(); ++i)
        {
            const LibraryItem *item = inventory.getItem(i);
            if (item)
            {
                cout << "Title: " << item->title << endl;
                cout << "Author: " << item->author << endl;
                cout << "Quantity: " << item->quantity << endl;
                cout << "----------------------------------------" << endl;
            }
        }
    }

    void generateBorrowedItemsReport() const
    {
        cout << "Borrowed Items Report:" << endl;
        for (int i = 0; i < 100; ++i)
        {
            const LibraryTransaction &transaction = transactions[i];
            if (!transaction.item.title.empty() && !transaction.member.name.empty())
            {
                const LibraryItem &item = transaction.item;
                const LibraryMember &member = transaction.member;
                cout << "Title: " << item.title << endl;
                cout << "Author: " << item.author << endl;
                cout << "Borrower: " << member.name << endl;
                cout << "Contact Details: " << member.contactDetails << endl;
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
        cout << "1. Add Item\n2. Add Member\n3. Borrow Item\n4. Return Item\n5. Generate Available Items Report\n6. Generate Borrowed Items Report\n7. Exit" << endl;
        cout << "\n__________________\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string title, author;
            int quantity;

            cout << "Enter item title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter quantity: ";
            cin >> quantity;

            library.addItem(title, author, quantity);
        }
        else if (choice == 2)
        {
            string name, contact;

            cout << "Enter member name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter contact details: ";
            getline(cin, contact);

            library.addMember(name, contact);
        }
        else if (choice == 3)
        {
            string itemTitle, memberName;

            cout << "Enter item title to borrow: ";
            cin.ignore();
            getline(cin, itemTitle);
            cout << "Enter member name: ";
            getline(cin, memberName);

            library.borrowItem(itemTitle, memberName);
        }
        else if (choice == 4)
        {
            string itemTitle;

            cout << "Enter item title to return: ";
            cin.ignore();
            getline(cin, itemTitle);

            library.returnItem(itemTitle);
        }
        else if (choice == 5)
        {
            library.generateAvailableItemsReport();
        }
        else if (choice == 6)
        {
            library.generateBorrowedItemsReport();
        }
        else if (choice == 7)
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
