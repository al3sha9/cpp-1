#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

const string USER_FILE = "users.txt";
const string NOTES_FILE = "notes.txt";

class TaskList;
class NoteTakingApp;
class Calendar;
class User;
string description; 

// USER - CLASS
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

    static User *loadUsers(int &count)
    {
        ifstream userFile(USER_FILE);
        count = 0;
        string uname, pword;

        // First, count the number of users
        while (userFile >> uname >> pword)
        {
            count++;
        }
        userFile.clear();            // clear eof and fail bits
        userFile.seekg(0, ios::beg); // rewind file to beginning

        // Allocate memory for users
        User *users = new User[count];
        int index = 0;
        while (userFile >> uname >> pword)
        {
            users[index++] = User(uname, pword);
        }
        userFile.close();
        return users;
    }

    static void freeUsers(User *users)
    {
        delete[] users;
    }
};

void bubbleSort(User *users, int count)
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

bool linearSearch(User *users, int count, const string &username, const string &password)
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
void displayUsers(const User *users, int count)
{
    if (count == 0)
    {
        cout << "No users found." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "User " << i + 1 << ": " << endl;
        cout << "Username: " << users[i].username << endl;
        cout << "Password: " << users[i].password << endl;
        cout << "-------------------" << endl;
    }
}
void addUser()
{
    string uname, pword;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pword;

    User newUser(uname, pword);
    newUser.saveUser();
    cout << "User added successfully!" << endl;
}

void displayMenu()
{
    cout << "1. Add User" << endl;
    cout << "2. Display Users" << endl;
    cout << "3. Sort Users" << endl;
    cout << "4. Search User" << endl;
    cout << "5. Exit" << endl;
}

// TASK - CLASS
class Task
{
public:
    string description;
    bool isCompleted;

    Task(const string &desc) : description(desc), isCompleted(false) {}
};

class TaskList
{
private:
    stack<Task> tasks; // original stack

public:
    void addTask(const string &description)
    {
        Task task(description);
        tasks.push(task); // tasks is stack - task is object of Task class
    }

    void markTaskAsCompleted()
    {
        if (!tasks.empty())
        {
            tasks.top().isCompleted = true;
        }
        else
        {
            cout << "No tasks to mark as completed." << endl;
        }
    }

    void displayTasks()
    {
        if (tasks.empty())
        {
            cout << "No tasks found." << endl;
            return;
        }

        // Use another stack to temporarily store tasks
        stack<Task> sortedTasks = sortTasks();

        cout << "Tasks:" << endl;
        while (!sortedTasks.empty())
        {
            Task task = sortedTasks.top();
            sortedTasks.pop();

            cout << task.description << " - " << (task.isCompleted ? "Completed" : "Pending") << endl;
        }
    }

    stack<Task> sortTasks()
    {
        stack<Task> sortedTasks;
        while (!tasks.empty())
        {
            Task currentTask = tasks.top();
            tasks.pop();

            while (!sortedTasks.empty() && sortedTasks.top().description > currentTask.description)
            {
                tasks.push(sortedTasks.top());
                sortedTasks.pop();
            }

            sortedTasks.push(currentTask);
        }

        // Put sorted tasks back into the original stack
        while (!sortedTasks.empty())
        {
            tasks.push(sortedTasks.top());
            sortedTasks.pop();
        }

        return tasks;
    }

    int linearSearch(const string &description)
    {
        stack<Task> tempTasks = tasks;
        int index = 0;

        while (!tempTasks.empty())
        {
            Task task = tempTasks.top();
            tempTasks.pop();
            if (task.description == description)
            {
                return index;
            }
            ++index;
        }

        return -1; // Task not found
    }
};

// NOTES - CLASS
class NoteBase
{
public:
    string title;
    string content;

    // Abstract class - pure virtual function
    virtual void createNote() = 0;
    virtual void displayNote() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void deleteNote() = 0;
};

// Note Child Class
class Note : public NoteBase
{
public:
    void createNote() override
    {
        cout << "Enter note title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter note content: ";
        getline(cin, content);
    }

    void displayNote() const override
    {
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
    }

    bool isEmpty() const override
    {
        return title.empty() && content.empty();
    }

    void deleteNote() override
    {
        title.clear();
        content.clear();
    }
};

class NoteTakingApp
{
private:
    Note *notes;
    int noteCount;
    int capacity;

public:
    NoteTakingApp()
        : notes(nullptr), noteCount(0), capacity(0)
    {
        loadNotes();
    }

    ~NoteTakingApp()
    {
        saveNotes();
        delete[] notes;
    }

    void createNote()
    {
        if (noteCount == capacity)
        {
            int newCapacity = capacity == 0 ? 1 : capacity * 2;
            Note *newNotes = new Note[newCapacity];

            for (int i = 0; i < noteCount; ++i)
            {
                newNotes[i] = notes[i];
            }

            delete[] notes;
            notes = newNotes;
            capacity = newCapacity;
        }

        notes[noteCount].createNote();
        ++noteCount;
    }

    void viewNotes() const
    {
        if (noteCount == 0)
        {
            cout << "No notes found." << endl;
            return;
        }

        cout << "Notes:" << endl;
        for (int i = 0; i < noteCount; ++i)
        {
            notes[i].displayNote();
            cout << "-------------------" << endl;
        }
    }

    void deleteNote()
    {
        if (noteCount == 0)
        {
            cout << "No notes to delete." << endl;
            return;
        }

        string title;
        cout << "Enter the title of the note to delete: ";
        cin.ignore();
        getline(cin, title);
        int index = -1;
        for (int i = 0; i < noteCount; ++i)
        {
            if (notes[i].title == title)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            for (int i = index; i < noteCount - 1; ++i)
            {
                notes[i] = notes[i + 1];
            }
            --noteCount;
            cout << "Note deleted successfully!" << endl;
        }
        else
        {
            cout << "Note with the given title not found." << endl;
        }
    }

    void dfsTraversal()
    {
        cout << "DFS Traversal of Notes:" << endl;
        for (int i = 0; i < noteCount; ++i)
        {
            notes[i].displayNote();
            cout << "-------------------" << endl;
        }
    }

    void mergeSortNotes()
    {
        if (noteCount > 0)
        {
            mergeSort(0, noteCount - 1);
        }
    }

private:
    void loadNotes()
    {
        ifstream inFile(NOTES_FILE);
        if (!inFile.is_open())
        {
            cout << "Could not open notes file. Creating a new one." << endl;
            return;
        }
        int loadedNotes = 0;
        while (inFile)
        {
            string title, content;
            getline(inFile, title);
            getline(inFile, content);

            if (!title.empty() && !content.empty())
            {
                if (loadedNotes == capacity)
                {
                    int newCapacity = capacity == 0 ? 1 : capacity * 2;
                    Note *newNotes = new Note[newCapacity];

                    for (int i = 0; i < loadedNotes; ++i)
                    {
                        newNotes[i] = notes[i];
                    }

                    delete[] notes;
                    notes = newNotes;
                    capacity = newCapacity;
                }

                notes[loadedNotes].title = title;
                notes[loadedNotes].content = content;
                ++loadedNotes;
            }
        }

        noteCount = loadedNotes;
        inFile.close();
    }

    void saveNotes()
    {
        ofstream outFile(NOTES_FILE);
        if (!outFile.is_open())
        {
            cout << "Could not open notes file for saving." << endl;
            return;
        }

        for (int i = 0; i < noteCount; ++i)
        {
            outFile << notes[i].title << endl;
            outFile << notes[i].content << endl;
        }

        outFile.close();
    }
    //divide them into two halves and sort the left and right 
    void mergeSort(int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }
    //merge the two halves
    void merge(int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Note *leftNotes = new Note[n1];
        Note *rightNotes = new Note[n2];

        for (int i = 0; i < n1; ++i)
            leftNotes[i] = notes[left + i];
        for (int i = 0; i < n2; ++i)
            rightNotes[i] = notes[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (leftNotes[i].title <= rightNotes[j].title)
            {
                notes[k] = leftNotes[i];
                ++i;
            }
            else
            {
                notes[k] = rightNotes[j];
                ++j;
            }
            ++k;
        }

        while (i < n1)
        {
            notes[k] = leftNotes[i];
            ++i;
            ++k;
        }

        while (j < n2)
        {
            notes[k] = rightNotes[j];
            ++j;
            ++k;
        }

        delete[] leftNotes;
        delete[] rightNotes;
    }
};
const int MAX_DAYS = 32;

// CALENDER - CLASS
class DateInfo
{
protected:
    tm currentDate;

public:
    DateInfo()
    {
        time_t now = time(0);
        currentDate = *localtime(&now);
    }
    int getYear() const
    {
        return 1900 + currentDate.tm_year;
    }

    int getMonth() const
    {
        return 1 + currentDate.tm_mon;
    }

    int getDay() const
    {
        return currentDate.tm_mday;
    }

    virtual int getDaysInMonth(int year, int month) const
    {
        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            days = 29;
        }
        return days;
    }

    virtual int calculateFirstDay(int year, int month) const
    {
        tm firstDay = {0, 0, 0, 1, month - 1, year - 1900};
        mktime(&firstDay);
        return firstDay.tm_wday;
    }
};

class Calendar : public DateInfo
{
private:
    string events[MAX_DAYS]; // Array to store events

public:
    Calendar()
    {
        // Initialize the events
        for (int i = 0; i < MAX_DAYS; i++)
        {
            events[i] = "";
        }

        // Add specific events
        events[1] = "Labour's Day";
        events[11] = "Cousin's Birthday";
    }

    void displayCurrentMonthCalendar()
    {
        int year = getYear();
        int month = getMonth();
        int day = getDay();
        int daysInMonth = getDaysInMonth(year, month);
        int startingDay = calculateFirstDay(year, month);
        cout << "\t\t  " << year << " - " << month << "   \n";
        cout << " Su  Mo  Tu  We  Th  Fr  Sa\n";

        for (int i = 0; i < startingDay; i++)
        {
            cout << "    ";
        }

        for (int i = 1; i <= daysInMonth; i++)
        {
            if (i < 10)
                cout << " ";
            if (i == day)
                cout << "[" << i << "]";
            else
                cout << " " << i << " ";
            if ((i + startingDay) % 7 == 0 || i == daysInMonth)
                cout << endl;
        }

        // Prompt user to search for a day
        int searchDay;
        cout << "\nEnter the day to search for an event: ";
        cin >> searchDay;

        if (searchDay >= 1 && searchDay <= daysInMonth)
        {
            if (!events[searchDay].empty())
                cout << "Event on day " << searchDay << ": " << events[searchDay] << endl;
            else
                cout << "No event on day " << searchDay << "." << endl;
        }
        else
        {
            cout << "Invalid day." << endl;
        }
    }
};

// MAIN FUNCTION
int main() {
    // Load users
    int userCount;
    User* users = User::loadUsers(userCount);
    TaskList taskList;
    NoteTakingApp app;
    Calendar calendar;
    int choice;
    string description;

    // Sort users using bubble sort
    bubbleSort(users, userCount);

    // User login or registration
    bool isLoggedIn = false;
    while (!isLoggedIn) {
        cout << "1. Register new user" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
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
        } else if (choice == 2) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (linearSearch(users, userCount, username, password)) {
                cout << "Login successful." << endl;
                isLoggedIn = true;
            } else {
                cout << "Invalid username or password." << endl;
            }
        } else if (choice == 3) {
            // Free the dynamically allocated memory before exiting
            User::freeUsers(users);
            return 0;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    // Main menu for accessing notes, calendar, and tasks
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Manage Tasks\n";
        cout << "2. Notes\n";
        cout << "3. Calendar\n";
        cout << "4. Display Users\n";
        cout << "5. Sort Users\n";
        cout << "6. Search User\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Task menu
                do {
                    cout << "\nTask Manager Menu:\n";
                    cout << "1. Add Task\n";
                    cout << "2. Mark Top Task as Completed\n";
                    cout << "3. Display Tasks\n";
                    cout << "4. Search Task\n";
                    cout << "5. Return to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore(); // To ignore the newline character left by cin

                    switch (choice) {
                        case 1:
                            cout << "Enter task description: ";
                            getline(cin, description);
                            taskList.addTask(description);
                            break;
                        case 2:
                            taskList.markTaskAsCompleted();
                            break;
                        case 3:
                            taskList.displayTasks();
                            break;
                        case 4:
                            cout << "Enter task description to search: ";
                            getline(cin, description);
                            int searchResult;
                            searchResult = taskList.linearSearch(description);
                            if (searchResult != -1) {
                                cout << "\nTask \"" << description << "\" found at index " << searchResult << endl;
                            } else {
                                cout << "\nTask \"" << description << "\" not found" << endl;
                            }
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                    }
                } while (choice != 5);
                break;

            case 2:
                // Notes menu
                do {
                    cout << "\nNote Taking App Menu\n";
                    cout << "1. Create Note\n";
                    cout << "2. View Notes\n";
                    cout << "3. Delete Note\n";
                    cout << "4. DFS Traversal\n";
                    cout << "5. Merge Sort Notes\n";
                    cout << "6. Return to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            app.createNote();
                            break;
                        case 2:
                            app.viewNotes();
                            break;
                        case 3:
                            app.deleteNote();
                            break;
                        case 4:
                            app.dfsTraversal();
                            break;
                        case 5:
                            app.mergeSortNotes();
                            break;
                        case 6:
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 6);
                break;

            case 3:
                // Calendar menu
                calendar.displayCurrentMonthCalendar();
                break;

            case 4:
                // Display users
                users = User::loadUsers(userCount);
                for (int i = 0; i < userCount; ++i) {
                    cout << "Username: " << users[i].username << ", Password: " << users[i].password << endl;
                }
                User::freeUsers(users);
                break;

            case 5:
                // Sort users
                users = User::loadUsers(userCount);
                bubbleSort(users, userCount);
                cout << "Users sorted successfully!" << endl;
                for (int i = 0; i < userCount; ++i) {
                    cout << "Username: " << users[i].username << ", Password: " << users[i].password << endl;
                }
                User::freeUsers(users);
                break;

            case 6:
                // Search user
                {
                    string username, password;
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    users = User::loadUsers(userCount);
                    if (linearSearch(users, userCount, username, password)) {
                        cout << "User found!" << endl;
                    } else {
                        cout << "User not found." << endl;
                    }
                    User::freeUsers(users);
                }
                break;

            case 7:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    // Free the dynamically allocated memory
    User::freeUsers(users);

    return 0;
}