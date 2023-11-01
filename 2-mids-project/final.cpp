#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;
const string NOTES_FILE = "notes.txt";

class Calendar {
public:
    Calendar() {
        time_t now = time(0);
        currentDate = *localtime(&now);
        year = 1900 + currentDate.tm_year;
        month = 1 + currentDate.tm_mon;
        day = currentDate.tm_mday;
    }

    void displayCurrentMonthCalendar() {
        daysInMonth = getDaysInMonth(year, month);
        calculateFirstDay();

        cout << "\t\t  " << year << " - " << month << "   \n";
        cout << " Su  Mo  Tu  We  Th  Fr  Sa\n";

        for (int i = 0; i < startingDay; i++) {
            cout << "   ";
        }

        for (int i = 1; i <= daysInMonth; i++) {
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
    tm currentDate;
    int year;
    int month;
    int day;
    int daysInMonth;
    int startingDay;

    int getDaysInMonth(int year, int month) {
        const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = daysInMonth[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            days = 29;
        }
        return days;
    }

    void calculateFirstDay() {
        tm firstDay = {0, 0, 0, 1, month - 1, year - 1900};
        mktime(&firstDay);
        startingDay = firstDay.tm_wday;
    }
};

class Stopwatch {
private:
    time_t startTime;
    time_t stopTime;

public:
    void start() {
        startTime = time(nullptr);
        cout << "Stopwatch started. Press 's' to stop." << endl;
    }

    void stop() {
        stopTime = time(nullptr);
        cout << "\a";
        cout << "Stopwatch stopped." << endl;
    }

    double getElapsedSeconds() {
        return difftime(stopTime, startTime);
    }
};

class TaskList {
private:
    string tasks[100];
    int taskCount;

public:
    TaskList() : taskCount(0) {
        loadTasksFromFile();
    }

    ~TaskList() {
        saveTasksToFile();
    }

    void displayTasks() {
        cout << "To-Do List:" << endl;
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void addTask(const string &task) {
        if (taskCount < 100) {
            tasks[taskCount] = task;
            taskCount++;
        } else {
            cerr << "Error: Task limit reached." << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= taskCount) {
            // Mark the task as completed (implement your logic here)
        } else {
            cerr << "Error: Invalid task number." << endl;
        }
    }

private:
    void saveTasksToFile() {
        ofstream file("todo.txt");

        if (file.is_open()) {
            for (int i = 0; i < taskCount; i++) {
                file << tasks[i] << endl;
            }
            file.close();
        } else {
            cerr << "Error: Could not open the file for writing." << endl;
        }
    }

    void loadTasksFromFile() {
        string task;
        ifstream file("todo.txt");

        if (file.is_open()) {
            while (getline(file, task) && taskCount < 100) {
                tasks[taskCount] = task;
                taskCount++;
            }
            file.close();
        }
    }
};

class Alarm {
public:
    tm alarmTime, presentTime, differenceInTime;

    Alarm() {
        time_t now = time(0);
        presentTime = *localtime(&now);
        alarmTime = presentTime;
        alarmTime.tm_sec = 0;
    }

    void getTime() {
        string time;
        cout << "Enter Alarm Time in 24-hour format [HH:MM]: ";
        cin >> time;

        int pos = 0, h;
        while ((pos = time.find(':')) != string::npos) {
            string token = time.substr(0, pos);
            stringstream convert(token);
            convert >> alarmTime.tm_hour;
            time.erase(0, pos + 1);
        }

        stringstream convert(time);
        convert >> alarmTime.tm_min;
    }

    void timeDifference() {
        time_t now = time(0);
        int sec = difftime(mktime(&alarmTime), now);
        differenceInTime.tm_min = sec / 60;
        differenceInTime.tm_hour = differenceInTime.tm_min / 60;
        differenceInTime.tm_min = differenceInTime.tm_min % 60;
        differenceInTime.tm_sec = sec % 60;

        if (sec < 0) {
            differenceInTime.tm_hour = 24 + differenceInTime.tm_hour - 1;
            differenceInTime.tm_min = 0 - differenceInTime.tm_min;
            differenceInTime.tm_sec = 0 - differenceInTime.tm_sec;
        }
    }

    void startAlarm() {
        while (true) {
            system("clear"); // Clear the console on Linux
            time_t now = time(0);
            presentTime = *localtime(&now);
            timeDifference();
            cout << "TIME REMAINING: " << differenceInTime.tm_hour << ":" << differenceInTime.tm_min << ":" << differenceInTime.tm_sec << endl;

            if (differenceInTime.tm_hour == 0 && differenceInTime.tm_min == 0 && differenceInTime.tm_sec == 0) {
                cout << "Time Ended" << endl << ">>> Press Ctrl+C to stop the alarm <<<" << endl;
                while (true) {
                    cout << '\a';
                    sleep(1);
                }
            }

            sleep(1);
        }
    }
};

class Note {
public:
    Note() : title(""), content("") {}

    void createNote() {
        cout << "Enter note title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter note content: ";
        getline(cin, content);
    }

    void displayNote() {
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
    }

    const string &getTitle() const {
        return title;
    }

    const string &getContent() const {
        return content;
    }

    bool isEmpty() const {
        return title.empty() && content.empty();
    }

    void deleteNote() {
        title = "";
        content = "";
    }

private:
    string title;
    string content;
};

class NoteTakingApp {
public:
    NoteTakingApp() {
        loadNotes();
    }

    ~NoteTakingApp() {
        saveNotes();
    }

    void createNote() {
        if (noteCount < 100) {
            notes[noteCount].createNote();
            noteCount++;
            cout << "Note created successfully!" << endl;
        } else {
            cout << "Cannot create more notes. The maximum limit has been reached." << endl;
        }
    }

    void viewNotes() {
        if (noteCount == 0) {
            cout << "No notes found." << endl;
            return;
        }

        cout << "Notes:" << endl;
        for (int i = 0; i < noteCount; i++) {
            if (!notes[i].isEmpty()) {
                notes[i].displayNote();
                cout << "-------------------" << endl;
            }
        }
    }

    void deleteNote() {
        if (noteCount == 0) {
            cout << "No notes to delete." << endl;
            return;
        }

        string title;
        cout << "Enter the title of the note to delete: ";
        cin.ignore();
        getline(cin, title);

        for (int i = 0; i < noteCount; i++) {
            if (notes[i].getTitle() == title) {
                notes[i].deleteNote();
                cout << "Note deleted successfully!" << endl;
                return;
            }
        }

        cout << "Note with the given title not found." << endl;
    }

private:
    Note notes[100];
    int noteCount = 0;

    void loadNotes() {
        ifstream inFile(NOTES_FILE);
        if (!inFile.is_open()) {
            cout << "Could not open notes file. Creating a new one." << endl;
            return;
        }

        while (noteCount < 100 && inFile) {
            string title, content;
            getline(inFile, title);
            getline(inFile, content);

            if (!title.empty() && !content.empty()) {
                notes[noteCount] = Note();
                notes[noteCount].createNote();
                noteCount++;
            }
        }

        inFile.close();
    }

    void saveNotes() {
        ofstream outFile(NOTES_FILE);
        if (!outFile.is_open()) {
            cout << "Could not open notes file for saving." << endl;
            return;
        }

        for (int i = 0; i < noteCount; i++) {
            if (!notes[i].isEmpty()) {
                outFile << notes[i].getTitle() << endl;
                outFile << notes[i].getContent() << endl;
            }
        }

        outFile.close();
    }
};

int main() {
    int choice;
    while (true) {
        cout << "Welcome to the Dashboard!" << endl;
        cout << "1. Calendar" << endl;
        cout << "2. Stopwatch" << endl;
        cout << "3. Task List" << endl;
        cout << "4. Alarm" << endl;
        cout << "5. Note Taking App" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Calendar calendar;
                calendar.displayCurrentMonthCalendar();
                break;
            }
            case 2: {
                Stopwatch stopwatch;
                char action;

                do {
                    cout << "Press 's' to start the stopwatch or 'q' to quit: ";
                    cin >> action;

                    if (action == 's') {
                        stopwatch.start();

                        while (cin >> action) {
                            if (action == 's') {
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
            case 3: {
                TaskList taskList;
                string task;

                while (true) {
                    taskList.displayTasks();

                    cout << "\nOptions:\n";
                    cout << "1. Add Task\n";
                    cout << "2. Mark Task as Completed\n";
                    cout << "3. Quit\n";

                    int choice;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    switch (choice) {
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
                            cerr << "Error: Invalid choice. Please try again." << endl;
                    }
                }
                break;
            }
            case 4: {
                Alarm alarm;
                alarm.getTime();
                alarm.startAlarm();
                break;
            }
            case 5: {
                NoteTakingApp app;

                do {
                    cout << "Note Taking App" << endl;
                    cout << "1. Create Note" << endl;
                    cout << "2. View Notes" << endl;
                    cout << "3. Delete Note" << endl;
                    cout << "4. Exit" << endl;
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
                            cout << "Exiting Note Taking App." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 4);

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
