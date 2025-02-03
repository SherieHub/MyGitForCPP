#include<iostream>
#include<stdexcept>
using namespace std;

class Stack{
    int arr[5];
    int size;
    
    public:
    
    Stack(){
        size = 0;
        for(int i = 0; i < 5; i++){
            arr[i] = 0;
        }
    }
    
    public:
    void push(int num){
        if(size == 5) throw logic_error("Stack is Full!");
        arr[size++] = num;
    }
    
    int pop(){
        if(isEmpty()) throw logic_error("Stack is Empty!");
        int popped = arr[size-1];
        size--;
        return popped;
    }
    
    int top(){
        if(isEmpty()) throw logic_error("Stack is Empty!");
        return arr[size-1];
    }
    
    int _size(){
        return size;
    }
    
    bool isEmpty(){
        return (size == 0) ? true : false;
    }
};
