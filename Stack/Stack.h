//
// Created by austi on 29/01/2025.
//
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Stack{
private:
    int top;
    int arr[5];

public:
    Stack(){
        top = -1;
        for(int i = 0; i < 5; i++){
            arr[i] = 0;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(top == 4){
            return true;
        }else{
            return false;
        }
    }

    void push(int val){
        if(isFull()){
            cout << "Stack Overflow";
        }else{
            top++;
            arr[top] = val;
        }
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow";
            return 0;
        }else{
            int popVal = arr[top];
            arr[top] = 0;
            top--;
            return popVal;
        }
    }


    int count(){
        return (top + 1);
    }

    int peek(int pos){
        if(isEmpty()){
            cout << "Stack Underflow";
            return 0;
        }else{
            return arr[pos];
        }
    }

    int change(int val, int pos){
        arr[pos] = val;
        cout << "Value changed at position" <<pos<<endl;
    }

    void display(){
        cout << "All Values in the Stack are: "<<endl;
        for(int i = 0; i < 5; i++){
            cout << arr[i] <<endl;
        }
    }
};

