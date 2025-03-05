#include <iostream>
#include<bits/stdc++.h>
#include "hashtable.hpp"
using namespace std;

template <typename K>
class HTLinear : public HashTable<K> {
    // IMPLEMENT ME
    int N;
    int count;
    K* table;
    int a = 59, b = 17, p = 509;
    
    public:
    
    HTLinear(int N){
        this->N = N;
        table = (K*)calloc(N, sizeof(K));
        count = 0;
    }
    
    int hash_code(K key) {
        return key;
    }

    
    int compress(int code){
        return (((a * code) + b) % p) % N;
    }
    
    int insert(K key){
        int index = compress(hash_code(key));
        int collisions = 0;
        
        if(count == N) throw logic_error("Table already full");
        
        while(table[index] != 0){
            if(table[index] == key) throw logic_error("Already added key " + to_string(key));
            index = (index + 1) % N;
            collisions++;
        }
        table[index] = key;
        count++;
        return collisions;
    }
    
    int search(K key){
        int index = compress(hash_code(key));
        int check = 0;
        
        while(check < N){
            if(table[index] == key) return check;
            index = (index + 1) % N;
            check++;
        }
        return -1;
    }
    
    int remove(K key) {
        int index = compress(hash_code(key));
        int check = 0;
    
        while (check < N) {
            if(table[index] == key){
                if(table[index+1] == -1){
                    table[index] = -1;
                    count--;
                }else{
                    table[index] = 0;
                    count--;
                    return check;
                }
            }else{
                check++;
                index++;
                if(index == N) index = 0;
            }
        }
        return -1; 
    }
    
    void print(){
        for(int i = 0; i < N; i++){
            cout << i << "\t";
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            cout << table[i] << "\t";
        }
        cout << endl;
    }
};