#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

const string NOTES_FILE = "notes.txt";
const string USER_FILE = "users.txt";

// user login
class User
{
public:
    string username;
    string password;

    User(const string &uname, const string &pword)
    {
        username = uname;
        password = pword;
    }

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

    static bool isUserRegistered(const string &username, const string &password)
    {
        ifstream userFile(USER_FILE);
        string uname, pword;
        while (userFile >> uname >> pword)
        {
            if (uname == username && pword == password)
            {
                userFile.close();
                return true;
            }
        }
        userFile.close();
        return false;
    }
};

// Alarm Class
class Alarm
{
private:
    int alarmHour;
    int alarmMinute;
    int alarmSecond;
    int remainingSeconds;

public:
    Alarm()
    {
        alarmHour = 0;
        alarmMinute = 0;
        alarmSecond = 0;
        remainingSeconds = 0;
    }

    friend void setandGetAlarmTime(Alarm &a);
    friend void timeDifference(Alarm &a);
    friend void startAlarm(Alarm &a);
};

// Friend functions of Alarm Class
void setandGetAlarmTime(Alarm &a)
{
    a.alarmHour = 0;
    a.alarmMinute = 0;
    a.alarmSecond = 0;
    a.remainingSeconds = 0;
    cout << "Enter Alarm Time in 24-hour format [HH:MM:SS]: ";
    cin >> a.alarmHour;
    cin.ignore();
    cin >> a.alarmMinute;
    cin.ignore();
    cin >> a.alarmSecond;
}
void timeDifference(Alarm &a)
{
    int currentHour, currentMinute, currentSecond;
    cout << "Enter Current Time in 24-hour format [HH:MM:SS]: ";
    cin >> currentHour;
    cin.ignore();
    cin >> currentMinute;
    cin.ignore();
    cin >> currentSecond;

    a.remainingSeconds = (a.alarmHour - currentHour) * 3600 + (a.alarmMinute - currentMinute) * 60 + (a.alarmSecond - currentSecond);

    if (a.remainingSeconds < 0)
    {
        a.remainingSeconds += 86400;
    }
}

void startAlarm(Alarm &a)
{
    while (a.remainingSeconds >= 0)
    {
        int hours = a.remainingSeconds / 3600;
        int minutes = (a.remainingSeconds % 3600) / 60;
        int seconds = a.remainingSeconds % 60;

        cout << "TIME REMAINING: " << hours << ":" << minutes << ":" << seconds << endl;
        a.remainingSeconds--;

        for (int i = 0; i < 100000000; i++)
        {
        }

        if (a.remainingSeconds < 0)
        {
            cout << "ALARM TIME REACHED" << endl;
            cout << '\a';
            return;
        }
    }
}

// Base class (DateInfo) providing common functionality related to date information.
class DateInfo
{
protected:
    tm currentDate;

public:
    DateInfo()
    {
        time_t now = time(0);           // This line gets the current time in seconds
        currentDate = *localtime(&now); /* is a function that converts the total time (represented by now)
        into a more human-readable format*/
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

    // Virtual funtions in DataInfo()
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

// Derived from DateInfo to inherit date-related functionality.
class Calendar : public DateInfo
{
public:
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
    }
};

class Stopwatch
{
private:
    time_t startTime;
    time_t stopTime;

public:
    void start()
    {
        startTime = time(nullptr);
        cout << "Stopwatch started. Press 's' to stop." << endl;
    }

    void stop()
    {
        stopTime = time(nullptr);
        cout << "\a";
        cout << "Stopwatch stopped." << endl;
    }
    // This allows you to measure the elapsed time between starting and stopping the stopwatch in seconds.
    double getElapsedSeconds()
    {
        return difftime(stopTime, startTime);
    }
};

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
    stack<Task> tasks;

public:
    void addTask(const string &description)
    {
        Task task(description);
        tasks.push(task);
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

        stack<Task> tempTasks = tasks;

        cout << "Tasks:" << endl;
        while (!tempTasks.empty())
        {
            Task task = tempTasks.top();
            tempTasks.pop();

            cout << task.description << " - " << (task.isCompleted ? "Completed" : "Pending") << endl;
        }
    }
};

// Base class
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

struct NoteNode
{
    NoteBase *note;
    NoteNode *next;
};

class NoteTakingApp
{
private:
    NoteNode *head;

public:
    NoteTakingApp() : head(nullptr)
    {
        loadNotes();
    }

    ~NoteTakingApp()
    {
        saveNotes();
        // Release memory for dynamically allocated notes
        NoteNode *current = head;
        while (current != nullptr)
        {
            NoteNode *next = current->next;
            delete current->note;
            delete current;
            current = next;
        }
    }

    void createNote()
    {
        NoteNode *newNode = new NoteNode();
        newNode->note = new Note();
        newNode->next = nullptr;

        newNode->note->createNote();

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            NoteNode *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void viewNotes() const
    {
        if (head == nullptr)
        {
            cout << "No notes found." << endl;
            return;
        }

        cout << "Notes:" << endl;
        NoteNode *current = head;
        while (current != nullptr)
        {
            current->note->displayNote();
            cout << "-------------------" << endl;
            current = current->next;
        }
    }

    void deleteNote()
    {
        if (head == nullptr)
        {
            cout << "No notes to delete." << endl;
            return;
        }

        string title;
        cout << "Enter the title of the note to delete: ";
        cin.ignore();
        getline(cin, title);

        if (head->note->title == title)
        {
            NoteNode *temp = head;
            head = head->next;
            delete temp->note;
            delete temp;
            cout << "Note deleted successfully!" << endl;
            return;
        }

        NoteNode *current = head;
        while (current->next != nullptr && current->next->note->title != title)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            cout << "Note with the given title not found." << endl;
        }
        else
        {
            NoteNode *temp = current->next;
            current->next = current->next->next;
            delete temp->note;
            delete temp;
            cout << "Note deleted successfully!" << endl;
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

        while (inFile)
        {
            string title, content;
            // read lines from the file
            getline(inFile, title);
            getline(inFile, content);

            if (!title.empty() && !content.empty())
            {
                NoteNode *newNode = new NoteNode();
                newNode->note = new Note();
                newNode->next = nullptr;

                newNode->note->title = title;
                newNode->note->content = content;

                if (head == nullptr)
                {
                    head = newNode;
                }
                else
                {
                    NoteNode *current = head;
                    while (current->next != nullptr)
                    {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
        }

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

        NoteNode *current = head;
        while (current != nullptr)
        {
            outFile << current->note->title << endl;
            outFile << current->note->content << endl;
            current = current->next;
        }

        outFile.close();
    }
};

int main()
{
    try
    {
        int choice;
        bool loggedIn = false;
        Alarm myAlarm; // Create the Alarm object outside the try block

        while (!loggedIn)
        {
            cout << "\n\t\t\t\tWelcome to the\n"
                 << endl;
            cout << "T)tttttt   A)aa    S)ssss  K)   kk      M)mm mmm    A)aa   N)n   nn   A)aa     G)gggg E)eeeeee R)rrrrr  " << endl;
            cout << "   T)     A)  aa  S)    ss K)  kk      M)  mm  mm  A)  aa  N)nn  nn  A)  aa   G)      E)       R)    rr " << endl;
            cout << "   T)    A)    aa  S)ss    K)kkk       M)  mm  mm A)    aa N) nn nn A)    aa G)  ggg  E)eeeee  R)  rrr  " << endl;
            cout << "   T)    A)aaaaaa      S)  K)  kk      M)  mm  mm A)aaaaaa N)  nnnn A)aaaaaa G)    gg E)       R) rr    " << endl;
            cout << "   T)    A)    aa S)    ss K)   kk     M)      mm A)    aa N)   nnn A)    aa  G)   gg E)       R)   rr  " << endl;
            cout << "   T)    A)    aa  S)ssss  K)    kk    M)      mm A)    aa N)    nn A)    aa   G)ggg  E)eeeeee R)    rr " << endl;

            cout << "\n\n_________________________" << endl;
            cout << "\n\t1. Login" << endl;
            cout << "\t2. Signup" << endl;
            cout << "\tEnter your choice: " << endl;
            cout << "\n_________________________\n";
            cin >> choice;

            if (choice == 1)
            {
                string username, password;
                cout << "\nEnter your username: ";
                cin >> username;
                cout << "\nEnter your password: ";
                cin >> password;
                cout << "\n_________________________\n";

                if (User::isUserRegistered(username, password))
                {
                    cout << "\nLogin successful!" << endl;
                    loggedIn = true;
                }
                else
                {
                    cout << "\nLogin failed. Incorrect username or password. Please try again." << endl;
                }
            }
            else if (choice == 2)
            {
                string newUsername, newPassword;
                cout << "\n_________________________\n";
                cout << "\nEnter a new username: ";
                cin >> newUsername;
                cout << "\nEnter a new password: ";
                cin >> newPassword;
                User newUser(newUsername, newPassword);
                newUser.saveUser();
                cout << "\nUser registered successfully!" << endl;
                cout << "\n_________________________\n";
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }

        while (loggedIn)
        {
            cout << "\n<=================================>\n";
            cout << "\nWhat would you like to do?" << endl;
            cout << "\t1. Calendar" << endl;
            cout << "\t2. Stopwatch" << endl;
            cout << "\t3. Task List" << endl;
            cout << "\t4. Note Taking App" << endl;
            cout << "\t5. Alarm Clock" << endl;
            cout << "\t6. Exit" << endl;
            cout << "\tEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                Calendar calendar;
                calendar.displayCurrentMonthCalendar();
                break;
            }
            case 2:
            {
                Stopwatch stopwatch;
                char action;

                do
                {
                    cout << "\nPress 's' to start the stopwatch or 'q' to quit: ";
                    cin >> action;

                    if (action == 's')
                    {
                        stopwatch.start();

                        while (cin >> action)
                        {
                            if (action == 's')
                            {
                                stopwatch.stop();
                                break;
                            }
                        }

                        cout << "\nElapsed time: " << stopwatch.getElapsedSeconds() << " seconds" << endl;
                        cout << "\n_________________________\n";
                    }
                } while (action != 'q');

                break;
            }
            case 3:
            {
                TaskList taskList;

                while (true)
                {
                    taskList.displayTasks();

                    cout << "\nOptions:\n";
                    cout << "\t1. Add Task\n";
                    cout << "\t2. Mark Task as Completed\n";
                    cout << "\t3. Return to Main Menu\n";

                    int taskChoice;
                    cout << "\nEnter your choice: ";
                    cin >> taskChoice;
                    cin.ignore();

                    switch (taskChoice)
                    {
                    case 1:
                    {
                        string taskDescription;
                        cout << "\nEnter the task description: ";
                        getline(cin, taskDescription);
                        taskList.addTask(taskDescription);
                        break;
                    }
                    case 2:
                        taskList.markTaskAsCompleted();
                        break;
                    case 3:
                        cout << "Returning to the main menu." << endl;
                        break;
                    default:
                        cout << "Error: Invalid choice. Please try again." << endl;
                    }

                    if (taskChoice == 3)
                        break;
                }

                break;
            }

            case 4:
            {
                NoteTakingApp app;

                do
                {
                    cout << "\n_________________________\n";
                    cout << "\nNote Taking App" << endl;
                    cout << "\t1. Create Note" << endl;
                    cout << "\t2. View Notes" << endl;
                    cout << "\t3. Delete Note" << endl;
                    cout << "\t4. Exit" << endl;
                    cout << "\tEnter your choice: ";
                    cin >> choice;
                    cout << "\n_________________________\n";

                    switch (choice)
                    {
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
                        cout << "\nExiting Note Taking App." << endl;
                        break;
                    default:
                        cout << "\nInvalid choice. Please try again." << endl;
                    }
                } while (choice != 4);
                break;
            }
            case 5:
            {
                try
                {
                    setandGetAlarmTime(myAlarm);
                    timeDifference(myAlarm);
                    startAlarm(myAlarm);
                }
                catch (const exception &e)
                {
                    cerr << "An error occurred in the Alarm section: " << e.what() << endl;
                }
                break;
            }
            case 6:
                cout << "\n\nT)tttttt H)    hh   A)aa   N)n   nn K)   kk   S)ssss  " << endl;
                cout << "   T)    H)    hh  A)  aa  N)nn  nn K)  kk   S)    ss " << endl;
                cout << "   T)    H)hhhhhh A)    aa N) nn nn K)kkk     S)ss    " << endl;
                cout << "   T)    H)    hh A)aaaaaa N)  nnnn K)  kk        S)  " << endl;
                cout << "   T)    H)    hh A)    aa N)   nnn K)   kk  S)    ss " << endl;
                cout << "   T)    H)    hh A)    aa N)    nn K)    kk  S)ssss  " << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
    catch (const exception &e)
    {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}