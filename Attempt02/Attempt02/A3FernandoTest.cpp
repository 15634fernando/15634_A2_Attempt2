#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    Book() {}

    Book(string t, string a, string i, bool av, string date)
        : title(t), author(a), isbn(i), available(av), dateAdded(date) {
    }

    string getTitle() const { return title; }
    string getIsbn() const { return isbn; }
    bool isAvailable() const { return available; }

    void print() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Available: " << (available ? "Available" : "Not available") << endl;
        cout << "DateAdded: " << dateAdded << endl;
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "You borrowed \"" << title << "\"." << endl;
        }
        else {
            cout << "Sorry, \"" << title << "\" is not available." << endl;
        }
    }
};

// bubble sort by title
void sortByTitle(Book arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j].getTitle() > arr[j + 1].getTitle()) {
                Book temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(const string& label, Book arr[], int size) {
    cout << "\n" << label << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        arr[i].print();
        cout << endl;
    }
}

Book* findBookByIsbn(Book arr[], int size, const string& isbn) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getIsbn() == isbn) {
            return &arr[i];
        }
    }
    return nullptr;
}

int main() {
    const int SIZE = 3;

    // correct books
    Book b1("Chainsaw Man Vol. 01", "Tatsuki Fujimoto", "9781974709939", true, "2025-11-01");
    Book b2("The Maze Runner", "James Dashner", "9780385737951", true, "2025-11-01");
    Book b3("Attack on Titan Vol. 01", "Hajime Isayama", "9781612626154", true, "2025-11-01");

    // incorrect books – used only to show wrong initialisation
    Book wrong1("Chainsaw Man Vol. 01", "Tatsuki Fujimoto", "ABC9939", true, "01-11-2025");
    Book wrong2("The Maze Runner", "", "9780385737951", true, "2025/11/01");
    Book wrong3("Attack on Titan Vol. 01", "Hajime Isayama", "97X1612626154", true, "11-2025");

    cout << "=== Incorrect book information examples ===" << endl;
    wrong1.print();
    cout << endl;
    wrong2.print();
    cout << endl;
    wrong3.print();
    cout << "\n===========================================" << endl;

    // Arrays for sorting tests
    Book arrAsc[SIZE] = { b3, b1, b2 }; // already ascending by title
    Book arrDesc[SIZE] = { b2, b1, b3 }; // descending
    Book arrMixed[SIZE] = { b1, b3, b2 }; // mixed

    // BEFORE SORT
    printArray("Array 1 - Ascending order BEFORE sort", arrAsc, SIZE);
    printArray("Array 2 - Descending order BEFORE sort", arrDesc, SIZE);
    printArray("Array 3 - Mixed order BEFORE sort", arrMixed, SIZE);

    // SORT
    sortByTitle(arrAsc, SIZE);
    sortByTitle(arrDesc, SIZE);
    sortByTitle(arrMixed, SIZE);

    // AFTER SORT
    printArray("Array 1 - Ascending order AFTER sort", arrAsc, SIZE);
    printArray("Array 2 - Descending order AFTER sort", arrDesc, SIZE);
    printArray("Array 3 - Mixed order AFTER sort", arrMixed, SIZE);

    // Simple interactive menu using one of the arrays (sorted mixed array)
    cout << "\n=== Welcome to Fernando's Test Library ===" << endl;
    string choice;
    string inputIsbn;

    while (true) {
        cout << "\n1 - Show all books (sorted)" << endl;
        cout << "2 - Borrow a book by ISBN" << endl;
        cout << "0 - Exit test program" << endl;
        cout << "Your choice: ";
        getline(cin, choice);

        if (choice == "0") {
            cout << "Exiting test program." << endl;
            break;
        }
        else if (choice == "1") {
            printArray("Current books (sorted by title)", arrMixed, SIZE);
        }
        else if (choice == "2") {
            cout << "Type ISBN to borrow: ";
            getline(cin, inputIsbn);
            Book* found = findBookByIsbn(arrMixed, SIZE, inputIsbn);
            if (found == nullptr) {
                cout << "Book not found." << endl;
            }
            else {
                found->borrowBook();
            }
        }
        else {
            cout << "Invalid option, try again." << endl;
        }
    }

    return 0;
}
