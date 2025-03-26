#include "hashtable.hpp"
#include <iostream>
using namespace std;

int main() {
    HashTable<int> hashTable;
    int choice, key;
    
    do {
        cout << "\nHash Table Menu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Print" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                cout << "Collisions encountered: " << hashTable.insert(key) << endl;
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (hashTable.search(key) != -1)
                    cout << "Key found at index: " << hashTable.search(key) << endl;
                else
                    cout << "Key not found." << endl;
                break;
            case 3:
                cout << "Enter key to remove: ";
                cin >> key;
                if (hashTable.remove(key))
                    cout << "Key removed successfully." << endl;
                else
                    cout << "Key not found." << endl;
                break;
            case 4:
                hashTable.print();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}