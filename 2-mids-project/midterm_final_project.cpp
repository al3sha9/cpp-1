#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string USER_FILE = "users.txt";
const string NOTES_FILE = "notes.txt";

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

    void setAlarmTime(int hour, int minute, int second)
    {
        alarmHour = hour;
        alarmMinute = minute;
        alarmSecond = second;
    }

    void getTime()
    {
        cout << "\n_________________________\n";
        cout << "\nEnter Alarm Time in 24-hour format [HH:MM:SS]: ";
        cin >> alarmHour;
        cin.ignore();
        cin >> alarmMinute;
        cin.ignore();
        cin >> alarmSecond;
    }

    void timeDifference()
    {
        int currentHour, currentMinute, currentSecond;
        cout << "\nEnter Current Time in 24-hour format [HH:MM:SS]: ";
        cin >> currentHour;
        cin.ignore();
        cin >> currentMinute;
        cin.ignore();
        cin >> currentSecond;

        remainingSeconds = (alarmHour - currentHour) * 3600 +
                           (alarmMinute - currentMinute) * 60 +
                           (alarmSecond - currentSecond);

        if (remainingSeconds < 0)
        {
            remainingSeconds += 86400;
        }
    }

    void startAlarm()
    {
        while (remainingSeconds > 0)
        {
            int hours = remainingSeconds / 3600;
            int minutes = (remainingSeconds % 3600) / 60;
            int seconds = remainingSeconds % 60;
            cout << endl;
            cout << "TIME REMAINING: " << hours << ":" << minutes << ":" << seconds << endl;
            remainingSeconds--;

            for (int i = 0; i < 100000000; i++)
            {
            }

            if (remainingSeconds == 0)
            {
                cout << "\n_________________________\n";
                cout << "\nALARM TIME REACHED" << endl;
                cout << '\a';
                return;
            }
        }
    }
};

class TaskList
{
private:
    string tasks[100];
    bool taskCompleted[100];
    int taskCount;

public:
    TaskList() : taskCount(0)
    {
        loadTasksFromFile();
        for (int i = 0; i < 100; i++)
        {
            taskCompleted[i] = false;
        }
    }

    ~TaskList()
    {
        saveTasksToFile();
    }

    void displayTasks()
    {
        cout << "\n_________________________\n";

        cout << "\nTo-Do List:" << endl;
        for (int i = 0; i < taskCount; i++)
        {
            cout << i + 1 << ". " << (taskCompleted[i] ? "[X] " : "[ ] ") << tasks[i] << endl;
        }
    }

    void addTask(const string &task)
    {
        if (taskCount < 100)
        {
            tasks[taskCount] = task;
            taskCount++;
            taskCompleted[taskCount - 1] = false;
        }
        else
        {
            cout << "Error: Task limit reached." << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex)
    {
        if (taskIndex >= 1 && taskIndex <= taskCount)
        {
            int index = taskIndex - 1;
            if (!taskCompleted[index])
            {
                taskCompleted[index] = true;
                cout << "Task " << taskIndex << " marked as completed." << endl;
            }
            else
            {
                cout << "Task " << taskIndex << " is already completed." << endl;
            }
        }
        else
        {
            cout << "Error: Invalid task number." << endl;
        }
    }

private:
    void saveTasksToFile()
    {
        ofstream file("todo.txt");

        if (file.is_open())
        {
            for (int i = 0; i < taskCount; i++)
            {
                file << tasks[i] << endl;
            }
            file.close();
        }
        else
        {
            cout << "Error: Could not open the file for writing." << endl;
        }
    }

    void loadTasksFromFile()
    {
        ifstream file("todo.txt");

        if (file.is_open())
        {
            string task;
            while (getline(file, task) && taskCount < 100)
            {
                tasks[taskCount] = task;
                taskCompleted[taskCount] = false;
                taskCount++;
            }
            file.close();
        }
    }
};

class NoteTakingApp
{
private:
    struct Note
    {
        string title;
        string content;

        void createNote()
        {
            cout << "\nEnter note title: ";
            cin.ignore();
            getline(cin, title);
            cout << "\nEnter note content: ";
            getline(cin, content);
        }

        void displayNote()
        {
            cout << "\n\tTitle: " << title << endl;
            cout << "\tContent: " << content << endl;
        }

        bool isEmpty()
        {
            return title.empty() && content.empty();
        }

        void deleteNote()
        {
            title.clear();
            content.clear();
        }
    };

    Note notes[100];
    int noteCount;

public:
    NoteTakingApp() : noteCount(0)
    {
        loadNotes();
    }

    ~NoteTakingApp()
    {
        saveNotes();
    }

    void createNote()
    {
        if (noteCount < 100)
        {
            notes[noteCount].createNote();
            noteCount++;
            cout << "Note created successfully!" << endl;
        }
        else
        {
            cout << "Cannot create more notes. The maximum limit has been reached." << endl;
        }
    }

    void viewNotes()
    {
        if (noteCount == 0)
        {
            cout << "No notes found." << endl;
            return;
        }

        cout << "Notes:" << endl;
        for (int i = 0; i < noteCount; i++)
        {
            if (!notes[i].isEmpty())
            {
                notes[i].displayNote();
                cout << "-------------------" << endl;
            }
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

        for (int i = 0; i < noteCount; i++)
        {
            if (notes[i].title == title)
            {
                notes[i].deleteNote();
                cout << "Note deleted successfully!" << endl;
                return;
            }
        }

        cout << "Note with the given title not found." << endl;
    }

private:
    void loadNotes()
    {
        ifstream inFile(NOTES_FILE);
        if (!inFile.is_open())
        {
            cout << "\n_________________________\n";
            cout << "\nCould not open notes file. Creating a new one." << endl;
            cout << "\n_________________________\n";

            return;
        }

        while (noteCount < 100 && inFile)
        {
            string title, content;
            getline(inFile, title);
            getline(inFile, content);

            if (!title.empty() && !content.empty())
            {
                notes[noteCount].title = title;
                notes[noteCount].content = content;
                noteCount++;
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

        for (int i = 0; i < noteCount; i++)
        {
            if (!notes[i].isEmpty())
            {
                outFile << notes[i].title << endl;
                outFile << notes[i].content << endl;
            }
        }

        outFile.close();
    }
};

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

class Calendar
{
    tm currentDate;
    int year;
    int month;
    int day;
    int daysInMonth;
    int startingDay;

public:
    Calendar()
    {
        time_t now = time(0);
        currentDate = *localtime(&now);
        year = 1900 + currentDate.tm_year;
        month = 1 + currentDate.tm_mon;
        day = currentDate.tm_mday;
    }

    void displayCurrentMonthCalendar()
    {
        daysInMonth = getDaysInMonth(year, month);
        calculateFirstDay();
        cout << "\n_________________________\n";
        cout << "\n\t\t  " << year << " - " << month << "   \n";
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

private:
    int getDaysInMonth(int year, int month)
    {
        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            days = 29;
        }
        return days;
    }

    void calculateFirstDay()
    {
        tm firstDay = {0, 0, 0, 1, month - 1, year - 1900};
        mktime(&firstDay);
        startingDay = firstDay.tm_wday;
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

        cout << "\nStopwatch started. Press 's' to stop." << endl;
    }

    void stop()
    {
        stopTime = time(nullptr);
        cout << '\a';
        cout << "Stopwatch stopped." << endl;
    }

    double getElapsedSeconds()
    {
        return difftime(stopTime, startTime);
    }
};

int main()
{
    int choice;
    bool loggedIn = false;

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
            string task;

            while (true)
            {
                taskList.displayTasks();

                cout << "\nOptions:\n";
                cout << "\t1. Add Task\n";
                cout << "\t2. Mark Task as Completed\n";
                cout << "\t3. Quit\n";

                int taskChoice;
                cout << "\nEnter your choice: ";
                cin >> taskChoice;
                cin.ignore();

                switch (taskChoice)
                {
                case 1:
                    cout << "\nEnter the task: ";
                    getline(cin, task);
                    taskList.addTask(task);
                    break;
                case 2:
                    int taskIndex;
                    cout << "\nEnter the task number to mark as completed: ";
                    cin >> taskIndex;
                    taskList.markTaskAsCompleted(taskIndex);
                    break;
                case 3:
                    cout << "Goodbye!" << endl;
                    return 0;
                default:
                    cout << "Error: Invalid choice. Please try again." << endl;
                }
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
            Alarm myAlarm;
            myAlarm.getTime();
            myAlarm.timeDifference();
            myAlarm.startAlarm();
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

    return 0;
}