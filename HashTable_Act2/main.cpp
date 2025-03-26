#include "hashtable.hpp"
#include <iostream>
using namespace std;

int main() {
    HashTable ht;
    int choice;
    string key;

    do {
        cout << "\nHash Table Menu:\n";
        cout << "1. Insert\n2. Search\n3. Remove\n4. Print\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter string to insert: ";
                getline(cin, key);
                cout << "Inserted at index: " << ht.insert(key) << endl;
                break;
            case 2:
                cout << "Enter string to search: ";
                getline(cin, key);
                cout << "Found at index: " << ht.search(key) << endl;
                break;
            case 3:
                cout << "Enter string to remove: ";
                getline(cin, key);
                cout << (ht.remove(key) ? "Deleted successfully" : "Not found") << endl;
                break;
            case 4:
                ht.print();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}