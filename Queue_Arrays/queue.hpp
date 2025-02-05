#include <iostream>
#include <stdexcept>
using namespace std;

class Queue{
    int arr[5];
    int size;
    
    public:
    
    Queue(){
        size = 0;
        for(int i = 0; i < size; i++){
            arr[i] = 0;
        }
    }
    
    //addLast
    void enqueue(int num){ //T(n) = 3
        if(size == 5) throw logic_error("Queue is Full!");
        arr[size++] = num;
    }
    
    //removeFirst
    int dequeue(){
        if(isEmpty()) throw logic_error("Queue is Empty!");
        
        int dequeued = arr[0];
        for(int i = 0; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
        return dequeued;
    }
    
    int first(){
        if(isEmpty()) throw logic_error("Queue is Empty!");
        
        return arr[0];
    }
    
    int _size(){
        return size;
    }
    
    bool isEmpty(){
        return size == 0;
    }
};