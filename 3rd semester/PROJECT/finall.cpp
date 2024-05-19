#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stack>

using namespace std;

const string USER_FILE = "users.txt";

// User Class
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
    Alarm() : alarmHour(0), alarmMinute(0), alarmSecond(0), remainingSeconds(0) {}

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

        for (int i = 0; i < 100000000; i++) { }

        if (a.remainingSeconds < 0)
        {
            cout << "ALARM TIME REACHED" << endl;
            cout << '\a';
            return;
        }
    }
}

// DateInfo Class
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

    int getYear() const { return 1900 + currentDate.tm_year; }
    int getMonth() const { return 1 + currentDate.tm_mon; }
    int getDay() const { return currentDate.tm_mday; }

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

// Calendar Class
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

        int daysArray[32]; // Store the days of the month for sorting
        for (int i = 0; i < startingDay; i++)
        {
            cout << "    ";
        }

        for (int i = 1; i <= daysInMonth; i++)
        {
            daysArray[i] = i; // Store the days in an array for sorting
            if (i < 10)
                cout << " ";
            if (i == day)
                cout << "[" << i << "]";
            else
                cout << " " << i << " ";
            if ((i + startingDay) % 7 == 0 || i == daysInMonth)
                cout << endl;
        }

        // Example of binary search
        int searchDay;
        cout << "\nEnter the day to search: ";
        cin >> searchDay;
        int binaryResult = binarySearch(daysArray, 1, daysInMonth, searchDay);
        if (binaryResult != -1)
            cout << "Binary Search (Found at index) " << binaryResult << endl;
        else
            cout << "Binary Search (Not found)" << endl;
    }

    // Binary Search implementation
    int binarySearch(int arr[], int low, int high, int key)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key)
                return mid;
            if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

// Stopwatch Class
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

    double getElapsedSeconds()
    {
        return difftime(stopTime, startTime);
    }
};

// Task Class
class Task
{
public:
    string description;
    bool isCompleted;

    Task(const string &desc) : description(desc), isCompleted(false) {}
};

// TaskList Class
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

        return -1;
    }
};

// Main function
int main()
{
    int choice;
    string username, password;

    cout << "1. Sign up\n2. Log in\nEnter your choice: ";
    cin >> choice;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (choice == 1)
    {
        User newUser(username, password);
        newUser.saveUser();
        cout << "User signed up successfully!" << endl;
    }
    else if (choice == 2)
    {
        if (User::isUserRegistered(username, password))
        {
            cout << "User logged in successfully!" << endl;
        }
        else
        {
            cout << "Invalid username or password!" << endl;
            return 1;
        }
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    while (true)
    {
        cout << "\nMenu:\n1. Alarm\n2. Calendar\n3. Stopwatch\n4. Task Manager\n5. Notes\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Alarm alarm;
            setandGetAlarmTime(alarm);
            timeDifference(alarm);
            startAlarm(alarm);
            break;
        }
        case 2:
        {
            Calendar calendar;
            calendar.displayCurrentMonthCalendar();
            break;
        }
        case 3:
        {
            Stopwatch stopwatch;
            stopwatch.start();
            char stop;
            cin >> stop;
            if (stop == 's')
            {
                stopwatch.stop();
                cout << "Elapsed time: " << stopwatch.getElapsedSeconds() << " seconds." << endl;
            }
            break;
        }
        case 4:
        {
            TaskList taskList;
            int taskChoice;
            do
            {
                cout << "\nTask Manager:\n1. Add Task\n2. Mark Task as Completed\n3. Display Tasks\n4. Search Task\n5. Back to Main Menu\nEnter your choice: ";
                cin >> taskChoice;

                switch (taskChoice)
                {
                case 1:
                {
                    string description;
                    cout << "Enter task description: ";
                    cin.ignore();
                    getline(cin, description);
                    taskList.addTask(description);
                    break;
                }
                case 2:
                    taskList.markTaskAsCompleted();
                    break;
                case 3:
                    taskList.displayTasks();
                    break;
                case 4:
                {
                    string description;
                    cout << "Enter task description to search: ";
                    cin.ignore();
                    getline(cin, description);
                    int index = taskList.linearSearch(description);
                    if (index != -1)
                    {
                        cout << "Task found at index " << index << endl;
                    }
                    else
                    {
                        cout << "Task not found." << endl;
                    }
                    break;
                }
                case 5:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                }
            } while (taskChoice != 5);
            break;
        }
        case 5:
        {
            // Notes functionality can be implemented here
            cout << "Notes functionality not implemented yet." << endl;
            break;
        }
        case 6:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
