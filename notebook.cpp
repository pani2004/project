#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
class Note {
public:
    Note(const string& title, const string& content)
        : title(title), content(content) {}

    void display() const {
        cout << "Title: " << title << "\nContent: " << content << "\n\n";
    }
    const string& getTitle() const {
        return title;
    }
private:
    string title;
    string content;
};
class Notebook {
public:
    void addNote() {
        string title, content;
        cout << "Enter note title: ";
        getline(cin, title);

        cout << "Enter note content: ";
        getline(cin, content);

        notes.push_back(Note(title, content));
        cout << "Note added successfully!\n";
    }

    void viewNotes() const {
        if (notes.empty()) {
            cout << "No notes available.\n";
        } else {
            for (const auto& note : notes) {
                note.display();
            }
        }
    }

    void deleteNote() {
        string title;
        cout << "Enter the title of the note to delete: ";
        getline(cin, title);

        auto it = find_if(notes.begin(), notes.end(), [title](const Note& note) {
            return note.getTitle() == title;
        });

        if (it != notes.end()) {
            notes.erase(it);
            cout << "Note deleted successfully!\n";
        } else {
            cout << "Note with title '" << title << "' not found.\n";
        }
    }

private:
    vector<Note> notes;
};

int main() {
    Notebook notebook;
    int choice;

    do {
        cout << "Notebook Menu:\n";
        cout << "1. Add Note\n";
        cout << "2. View Notes\n";
        cout << "3. Delete Note\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                notebook.addNote();
                break;
            case 2:
                notebook.viewNotes();
                break;
            case 3:
                notebook.deleteNote();
                break;
            case 4:
                cout << "Exiting the notebook. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
