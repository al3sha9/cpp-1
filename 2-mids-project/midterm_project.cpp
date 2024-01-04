#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

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
        cout << "Enter Alarm Time in 24-hour format [HH:MM:SS]: ";
        cin >> alarmHour;
        cin.ignore();
        cin >> alarmMinute;
        cin.ignore();
        cin >> alarmSecond;
    }

    void timeDifference()
    {
        int currentHour, currentMinute, currentSecond;
        cout << "Enter Current Time in 24-hour format [HH:MM:SS]: ";
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

            cout << "TIME REMAINING: " << hours << ":" << minutes << ":" << seconds << endl;
            remainingSeconds--;

            for (int i = 0; i < 100000000; i++)
            {
            }

            if (remainingSeconds == 0)
            {
                cout << "ALARM TIME REACHED" << endl;
                cout << '\a';
                return;
            }
        }
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
        cout << "To-Do List:" << endl;
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
            cout << "Enter note title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter note content: ";
            getline(cin, content);
        }

        void displayNote()
        {
            cout << "Title: " << title << endl;
            cout << "Content: " << content << endl;
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
            cout << "Could not open notes file. Creating a new one." << endl;
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

int main()
{
    int choice;

    while (true)
    {
        cout << "Welcome to the Dashboard!" << endl;
        cout << "1. Calendar" << endl;
        cout << "2. Stopwatch" << endl;
        cout << "3. Task List" << endl;
        cout << "4. Note Taking App" << endl;
        cout << "5. Alarm Clock" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
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
                cout << "Press 's' to start the stopwatch or 'q' to quit: ";
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

                    cout << "Elapsed time: " << stopwatch.getElapsedSeconds() << " seconds" << endl;
                }
            } while (action != 'q');

            cout << "Goodbye!" << endl;
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
                cout << "1. Add Task\n";
                cout << "2. Mark Task as Completed\n";
                cout << "3. Quit\n";

                int taskChoice;
                cout << "Enter your choice: ";
                cin >> taskChoice;
                cin.ignore();

                switch (taskChoice)
                {
                case 1:
                    cout << "Enter the task: ";
                    getline(cin, task);
                    taskList.addTask(task);
                    break;
                case 2:
                    int taskIndex;
                    cout << "Enter the task number to mark as completed: ";
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
                cout << "Note Taking App" << endl;
                cout << "1. Create Note" << endl;
                cout << "2. View Notes" << endl;
                cout << "3. Delete Note" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

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
                    cout << "Exiting Note Taking App." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
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
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
