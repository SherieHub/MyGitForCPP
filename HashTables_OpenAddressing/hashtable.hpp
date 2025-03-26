#include "hash.hpp"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class HashTable {
    static const int hashGroups = 10; 
    vector<pair<int, string>> table;
    vector<bool> occupied; 

public:
    HashTable() {
        table.resize(hashGroups, {-1, ""});
        occupied.resize(hashGroups, false); 
    }

    int hashFunction(int key) {
        return key % hashGroups;
    }

    bool isEmpty() {
        for (bool slot : occupied) {
            if (slot) return false; 
        }
        return true; 
    }

    void insertItem(int key, string value) {
        int hashCode = hashFunction(key);
        int originalHash = hashCode;
        int firstKeyPos = -1;

        // Step 1: Search for an existing key
        while (occupied[hashCode]) {
            if (table[hashCode].first == key) {
                if (firstKeyPos == -1) firstKeyPos = hashCode; // Store first occurrence
            }
            hashCode = (hashCode + 1) % hashGroups;
            if (hashCode == originalHash) {
                cout << "Table is full. Cannot insert key " << key << endl;
                return;
            }
        }

        // Step 2: Find the position for the new key
        int insertPos = (firstKeyPos != -1) ? (firstKeyPos + 1) % hashGroups : hashCode;

        while (occupied[insertPos]) { // Ensure it's an empty slot
            insertPos = (insertPos + 1) % hashGroups;
            if (insertPos == originalHash) {
                cout << "Table is full. Cannot insert key " << key << endl;
                return;
            }
        }

        // Step 3: Insert the key
        table[insertPos] = {key, value};
        occupied[insertPos] = true;
        cout << "Inserted (Key: " << key << ", Value: " << value << ") at index " << insertPos << endl;
    }

    void removeItem(int key) {
        int hashCode = hashFunction(key);
        int originalHash = hashCode;

        while (occupied[hashCode]) {
            if (table[hashCode].first == key) {
                cout << "Removed (Key: " << key << ", Value: " << table[hashCode].second << ")" << endl;
                table[hashCode] = {-1, ""}; // Mark as deleted
                occupied[hashCode] = false;
                return;
            }
            hashCode = (hashCode + 1) % hashGroups;
            if (hashCode == originalHash) break;
        }

        cout << "Key not found. No item removed." << endl;
    }

    void searchItem(int key) {
        int hashCode = hashFunction(key);
        int originalHash = hashCode;

        while (occupied[hashCode]) {
            if (table[hashCode].first == key) {
                cout << "Item found at index " << hashCode << ": (Key: " << key << ", Value: " << table[hashCode].second << ")" << endl;
                return;
            }
            hashCode = (hashCode + 1) % hashGroups;
            if (hashCode == originalHash) break;
        }

        cout << "Item not found!" << endl;
    }

    void printTable() {
        cout << "[";
        for (int i = 0; i < hashGroups; i++) {
            if (occupied[i]) {
                cout << "(" << table[i].first << ", " << table[i].second << ")";
            } else {
                cout << "EMPTY";
            }
            if (i < hashGroups - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};
