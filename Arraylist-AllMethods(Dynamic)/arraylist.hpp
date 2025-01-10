#include "list.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class ArrayList : public List{
    int* array;
    int capacity;
    int size;
    
    public:
    
    ArrayList(){
        capacity = 5;
        size = 0;
        array = (int*)malloc(capacity * sizeof(int));
    }
    
    void increaseCapacity(){
        if(size == capacity){
            capacity = ceil(capacity * 1.5);
            array = (int*)realloc(array, capacity * sizeof(int));
        }
    }
    
    void decreaseCapacity(){
        if(size <= ceil(2.0/3.0 * capacity)){
            capacity = floor(capacity * 0.7);
            
            if(capacity < 5){
                capacity = 5;
            }
        }
        array = (int*)realloc(array, capacity * sizeof(int));
    }
    
    void addFirst(int num){
        increaseCapacity();
        
        for(int i = size; i > 0; i--){
            array[i] = array[i-1];
        }
        size++;
        
        array[0] = num;
    }
    
    void addLast(int num){
        increaseCapacity();
        array[size++] = num;
    }
    
    void addAt(int num, int pos){
        if(pos < 1 || pos > size + 1) return;
        increaseCapacity();
        
        for(int i = size; i > pos-1; i--){
            array[i] = array[i-1];
        }
        size++;
        
        array[pos-1] = num;
    }
    
    int removeFirst(){
        if(size == 0) return -1;
        
        int ret = array[0];
        
        for(int i = 0; i < size-1; i++){
            array[i] = array[i+1];
        }
        size--;
        decreaseCapacity();
        
        return ret;
    }
    
    int removeLast(){
        if(size == 0) return -1;
        decreaseCapacity();
        
        return array[--size];
    }
    
    int removeAt(int pos){
        if(size == 0) return -1;
        if(pos < 1 || pos > size) return -1;
        
        int ret = array[pos-1];
        
        for(int i = pos-1; i < size-1; i++){
            array[i] = array[i+1];
        }
        size--;
        decreaseCapacity();
        
        return ret;
    }
    
    int get(int pos){
        if(pos < 1 || pos > size) return -1;
        return array[pos-1];
    }
    
    void print(){
        cout << endl << "ARRAYLIST: ";
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
        cout << "SIZE: " << size << " / " << capacity << endl << endl;
    }
};