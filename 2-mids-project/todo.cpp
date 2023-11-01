#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks

class TaskList
{
private:
    string tasks[MAX_TASKS];
    int taskCount;

public:
    TaskList() : taskCount(0)
    {
        loadTasksFromFile();
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
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    void addTask(const string &task)
    {
        if (taskCount < MAX_TASKS)
        {
            tasks[taskCount] = task;
            taskCount++;
        }
        else
        {
            cerr << "Error: Task limit reached." << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex)
    {
        if (taskIndex >= 1 && taskIndex <= taskCount)
        {
            // Mark the task as completed (implement your logic here)
        }
        else
        {
            cerr << "Error: Invalid task number." << endl;
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
            cerr << "Error: Could not open the file for writing." << endl;
        }
    }

    void loadTasksFromFile()
    {
        string task;
        ifstream file("todo.txt");

        if (file.is_open())
        {
            while (getline(file, task) && taskCount < MAX_TASKS)
            {
                tasks[taskCount] = task;
                taskCount++;
            }
            file.close();
        }
    }
};

int main()
{
    TaskList taskList;
    string task; // Move the declaration outside of the switch

    while (true)
    {
        taskList.displayTasks();

        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Quit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
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
            return 0;

        default:
            cerr << "Error: Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
