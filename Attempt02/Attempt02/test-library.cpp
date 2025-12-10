#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

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

    // Arrays for sorting tests (only correct books)
    Book arrAsc[SIZE]  = { b3, b1, b2 }; // ascending order added
    Book arrDesc[SIZE] = { b2, b1, b3 }; // descending order added
    Book arrMixed[SIZE]= { b1, b3, b2 }; // mixed order added

    // BEFORE SORT
    printArray("Array 1 - Ascending order BEFORE sort",  arrAsc,  SIZE);
    printArray("Array 2 - Descending order BEFORE sort", arrDesc, SIZE);
    printArray("Array 3 - Mixed order BEFORE sort",      arrMixed, SIZE);

    // SORT
    sortByTitle(arrAsc,  SIZE);
    sortByTitle(arrDesc, SIZE);
    sortByTitle(arrMixed,SIZE);

    // AFTER SORT
    printArray("Array 1 - Ascending order AFTER sort",  arrAsc,  SIZE);
    printArray("Array 2 - Descending order AFTER sort", arrDesc, SIZE);
    printArray("Array 3 - Mixed order AFTER sort",      arrMixed, SIZE);

    // Simple interactive menu using sorted mixed array
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
