#include <iostream>
#include <stack>

using namespace std;

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
    stack<Task> tasks; //original stack

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

int main()
{
    TaskList taskList;
    int choice;
    string description;

    do
    {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Top Task as Completed\n";
        cout << "3. Display Tasks\n";
        cout << "4. Search Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character left by cin

        switch (choice)
        {
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
            if (searchResult != -1)
            {
                cout << "\nTask \"" << description << "\" found at index " << searchResult << endl;
            }
            else
            {
                cout << "\nTask \"" << description << "\" not found" << endl;
            }
            break;

        case 5:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
