#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string USER_FILE = "users.txt";

class User
{
public:
    string username;
    string password;

    User(const string &uname = "", const string &pword = "") : username(uname), password(pword) {}

    void saveUser() const
    {
        ofstream userFile(USER_FILE, ios::app);
        if (userFile.is_open())
        {
            userFile << username << " " << password << endl;
            userFile.close();
        }
        else
        {
            cout << "Error: Could not open the user file for writing." << endl;
        }
    }

    static User* loadUsers(int &count)
    {
        ifstream userFile(USER_FILE);
        count = 0;
        string uname, pword;
        
        // First, count the number of users
        while (userFile >> uname >> pword)
        {
            count++;
        }
        userFile.clear(); // clear eof and fail bits
        userFile.seekg(0, ios::beg); // rewind file to beginning

        // Allocate memory for users
        User* users = new User[count];
        int index = 0;
        while (userFile >> uname >> pword)
        {
            users[index++] = User(uname, pword);
        }
        userFile.close();
        return users;
    }

    static void freeUsers(User* users)
    {
        delete[] users;
    }
};

void bubbleSort(User* users, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (users[j].username > users[j + 1].username)
            {
                swap(users[j], users[j + 1]);
            }
        }
    }
}

bool linearSearch(User* users, int count, const string &username, const string &password)
{
    for (int i = 0; i < count; i++)
    {
        if (users[i].username == username && users[i].password == password)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // Load users
    int userCount;
    User* users = User::loadUsers(userCount);

    // Sort users using bubble sort
    bubbleSort(users, userCount);

    while (true)
    {
        cout << "1. Register new user" << endl;
        cout << "2. Check if user is registered" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string username, password;
            cout << "Enter new username: ";
            cin >> username;
            cout << "Enter new password: ";
            cin >> password;

            // Save the new user
            User newUser(username, password);
            newUser.saveUser();

            // Reload and sort users after adding a new user
            delete[] users;
            users = User::loadUsers(userCount);
            bubbleSort(users, userCount);
        }
        else if (choice == 2)
        {
            string username, password;
            cout << "Enter username to check: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (linearSearch(users, userCount, username, password))
            {
                cout << "User is registered." << endl;
            }
            else
            {
                cout << "User is not registered." << endl;
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    // Free the dynamically allocated memory
    User::freeUsers(users);

    return 0;
}
