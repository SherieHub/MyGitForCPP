#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int A = 3; 
const int B = 5; 
const int P = 17; 

template <typename K>
class HashTable{
    K table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    int hash_code(K key) {
        return key; 
    }

    int compress(int code) {
        return ((A * code + B) % P) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            occupied[i] = false;
        }
    }

    int insert(K key) {
        int code = hash_code(key);
        int index = compress(code);
        int collisions = 0;

        while (occupied[index]) {
            index = (index + 1) % TABLE_SIZE;
            collisions++;
        }
        
        table[index] = key;
        occupied[index] = true;
        return collisions;
    }

    int search(K key) {
        int code = hash_code(key);
        int index = compress(code);
        int originalIndex = index;

        while (occupied[index]) {
            if (table[index] == key) return index;
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) break; 
        }
        return -1;
    }

    int remove(K key) {
        int index = search(key);
        if (index != -1) {
            occupied[index] = false;
            return 1;
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << "\t";
        }
        cout << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (occupied[i])
                cout << table[i] << "\t";
            else
                cout << "_\t"; 
        }
        cout << endl;
    }
};

