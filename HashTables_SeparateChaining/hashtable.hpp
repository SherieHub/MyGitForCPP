#include "hash.hpp"
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable : public Hash {
    static const int hashGroups = 10; 
    list<pair<int, string>> table[hashGroups];

public:
    HashTable() {}

    bool isEmpty() {
        int sum = 0;
        for (int i = 0; i < hashGroups; i++) {
            sum += table[i].size();
        }
        return sum == 0;
    }

    int hashFunction(int key) {
        return key % hashGroups;
    }

    void insertItem(int key, string value) {
        int hashCode = hashFunction(key);
        auto& cell = table[hashCode];

        // Instead of replacing, always add a new entry
        cell.emplace_back(key, value);
        cout << "Inserted (Key: " << key << ", Value: " << value << ") successfully." << endl;
    }

    void removeItem(int key) {
        int hashCode = hashFunction(key);
        auto& cell = table[hashCode];
        auto i = cell.begin();
        bool keyExists = false;

        while (i != cell.end()) {
            if (i->first == key) {
                cout << "Removed (Key: " << i->first << ", Value: " << i->second << ") from table." << endl;
                i = cell.erase(i); // Removes only the first occurrence
                keyExists = true;
                break;
            } else {
                ++i;
            }
        }

        if (!keyExists) {
            cout << "Key not found. No item removed." << endl;
        }
    }

    void searchItem(int key) {
        int hashCode = hashFunction(key);
        auto& cell = table[hashCode];
        bool keyExists = false;
    
        for (const auto& item : cell) {
            if (item.first == key) {
                cout << "Item found: (Key: " << key << ", Value: " << item.second << ")" << endl;
                keyExists = true;
            }
        }
    
        if (!keyExists) {
            cout << "Item not found!" << endl;
        }
    }

    void printTable() {
        for (int i = 0; i < hashGroups; i++) {
            if (table[i].empty()) continue;

            cout << "Bucket [" << i << "]: ";
            for (const auto& item : table[i]) {
                cout << "(Key: " << item.first << ", Value: " << item.second << ") -> ";
            }
            cout << "NULL\n";
        }
    }
};