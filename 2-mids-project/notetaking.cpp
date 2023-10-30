#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_NOTES = 100;
const string NOTES_FILE = "notes.txt";

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

    const string& getTitle() const {
        return title;
    }

    const string& getContent() const {
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
        if (noteCount < MAX_NOTES) {
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
    Note notes[MAX_NOTES];
    int noteCount = 0;

    void loadNotes() {
        ifstream inFile(NOTES_FILE);
        if (!inFile.is_open()) {
            cout << "Could not open notes file. Creating a new one." << endl;
            return;
        }

        while (noteCount < MAX_NOTES && inFile) {
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
    NoteTakingApp app;
    int choice;

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

    return 0;
}
