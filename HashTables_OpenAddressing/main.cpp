#include "hashtable.hpp"
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main() {
    HashTable hashTable;
    int choice, key;
    string value;

    do {
        // Displaying the menu
        cout << "\nHash Table Menu:\n";
        cout << "1. Insert Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Print Table\n";
        cout << "5. Check if Table is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Insert Item
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                hashTable.insertItem(key, value);
                break;

            case 2:
                // Remove Item
                cout << "Enter key to remove: ";
                cin >> key;
                hashTable.removeItem(key);
                break;

            case 3:
                // Search Item
                cout << "Enter key to search: ";
                cin >> key;
                hashTable.searchItem(key);
                break;

            case 4:
                // Print Table
                hashTable.printTable();
                break;

            case 5:
                // Check if Table is Empty
                if (hashTable.isEmpty()) {
                    cout << "The hash table is empty.\n";
                } else {
                    cout << "The hash table is not empty.\n";
                }
                break;

            case 6:
                // Exit the program
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
