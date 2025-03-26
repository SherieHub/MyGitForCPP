
#include <bits/stdc++.h>
#include <iostream>
#include "hashtable.hpp"
#include "linkedlist.hpp"
#include <cstring>
using namespace std;

class HTSepChain : public HashTable {
    // TODO
    LinkedList* table;
    LinkedList* list;
    int count;
    int N;
    
    public:
    
    HTSepChain(int N){
        this->N = N;
        table = new LinkedList[N];
        count = 0;
    }
    
    int hash_code(string key) {
        int a = 5, hash = 0, power = 1;
        int keyLength = key.length();
    
        for (int i = keyLength - 1; i >= 0; i--) {
            hash += int(key[i]) * power;
            power *= a; 
        }
        return abs(hash);  
    }
    
    int compress(int code){
        return code % N;
    }
    
     int insert(string key){
        int index = compress(hash_code(key));
        
        if(table[index].search(key) == key) throw logic_error("Already added key " + key);
        table[index].addTail(key);
        return table[index].getSize();
     }
     
     int search(string key){
         int index = compress(hash_code(key));
         
         if(table[index].search(key) == key) return table[index].getSize();
         return -1;
     }
     
     int remove(string key) {
        int index = compress(hash_code(key));
        int removed = table[index].removeNode(key); 
        
        if(removed != -1) count--;
        return removed;
    }
    
     void print(){
         for(int i = 0; i < N; i++){
             cout << i << "\t";
             table[i].print();
            cout << endl;
         }
         cout << endl;
     }
};


