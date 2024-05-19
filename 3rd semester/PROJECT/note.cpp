#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

const string NOTES_FILE = "notes.txt";

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

class NoteTakingApp
{
private:
    Note* notes;
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
            Note* newNotes = new Note[newCapacity];

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
                    Note* newNotes = new Note[newCapacity];

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

    void merge(int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Note* leftNotes = new Note[n1];
        Note* rightNotes = new Note[n2];

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

int main()
{
    NoteTakingApp app;
    int choice;

    do
    {
        cout << "\nNote Taking App Menu\n";
        cout << "1. Create Note\n";
        cout << "2. View Notes\n";
        cout << "3. Delete Note\n";
        cout << "4. DFS Traversal\n";
        cout << "5. Merge Sort Notes\n";
        cout << "6. Exit\n";
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
            app.dfsTraversal();
            break;
        case 5:
            app.mergeSortNotes();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
