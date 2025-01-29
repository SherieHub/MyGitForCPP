
#include "queue.hpp"
#include "singly.hpp"
#include<iostream>
using namespace std;

class Queue_SinglyLinkedList : public Queue{
    SinglyLinkedList* list;
    
    public:
    
    Queue_SinglyLinkedList(){
        list = new SinglyLinkedList();
    }
    
    void enqueue(int num){
        list->addTail(num);
    }
    
    int dequeue(){
        return isEmpty() ? -1 : list->removeHead();
    }
    
    int first(){
        return isEmpty() ? -1 : list->head->elem;
    }
    
    int _size(){
        return list->_size();
    }
    
    bool isEmpty(){
        return list->_size() == 0;
    }
};