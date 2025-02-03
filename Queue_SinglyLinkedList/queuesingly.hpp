
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
    
    void enqueue(int num){ //T(n) = 12
        list->addTail(num);
    }
    
    int dequeue(){ // T(n) = 14
        return isEmpty() ? -1 : list->removeHead();
    }
    
    int first(){ //T(n) = 6
        return isEmpty() ? -1 : list->head->elem;
    }
    
    int _size(){ //T(n) = 2
        return list->_size();
    }
    
    bool isEmpty(){ //T(n) = 3
        return list->_size() == 0;
    }
};