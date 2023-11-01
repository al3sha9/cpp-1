#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks

// Function to save tasks to a file
void saveTasksToFile(const string tasks[], int taskCount)
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

// Function to load tasks from a file
int loadTasksFromFile(string tasks[])
{
    int taskCount = 0;
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

    return taskCount;
}

int main()
{
    string tasks[MAX_TASKS];
    int taskCount = loadTasksFromFile(tasks);

    while (true)
    {
        cout << "To-Do List:" << endl;
        for (int i = 0; i < taskCount; i++)
        {
            cout << i + 1 << ". " << tasks[i] << endl;
        }

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
            if (taskCount < MAX_TASKS)
            {
                cout << "Enter the task: ";
                getline(cin, tasks[taskCount]);
                taskCount++;
            }
            else
            {
                cerr << "Error: Task limit reached." << endl;
            }
            break;

        case 2:
            int taskIndex;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskIndex;

            if (taskIndex >= 1 && taskIndex <= taskCount)
            {
                // Mark the task as completed (you can implement your logic here)
            }
            else
            {
                cerr << "Error: Invalid task number." << endl;
            }
            break;

        case 3:
            saveTasksToFile(tasks, taskCount);
            return 0;

        default:
            cerr << "Error: Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
