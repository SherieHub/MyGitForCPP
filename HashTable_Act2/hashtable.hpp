#include <iostream>
#include <cmath>
using namespace std;

const int TABLE_SIZE = 10;
const int MULTIPLIER = 31;
const int A = 3; 
const int B = 5; 
const int P = 17; 

struct Node {
    string value;
    Node* next;
};

class HashTable {
    Node** table;

    int hash_code(string key) {
        int hash = 0;
        for (char ch : key) {
            int charValue = (ch - 'a' + 1); 
            hash = hash * MULTIPLIER + charValue;
        }
        return hash;
    }

    int compress(int code) {
        return ((A * abs(code) + B) % P) % TABLE_SIZE;
    }

public:
    HashTable() {
        table = new Node*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    int insert(string key) {
        int code = hash_code(key);
        int index = compress(code);
        Node* newNode = new Node{key, table[index]}; //list initialization
        table[index] = newNode;
        return index;
    }

    int search(string key) {
        int code = hash_code(key);
        int index = compress(code);
        Node* curr = table[index];
        while (curr) {
            if (curr->value == key) return index;
            curr = curr->next;
        }
        return -1;
    }

    int remove(string key) {
        int index = compress(hash_code(key));
        Node* curr = table[index];
        Node* prev = nullptr;
        
        while (curr) {
            if (curr->value == key) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    table[index] = curr->next;
                }
                delete curr;
                return 1;
            }
            prev = curr;
            curr = curr->next;
        }
        return 0;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << curr->value << " -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }
};