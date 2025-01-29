
#include "stack.hpp"
#include "singly.hpp"

class StackLinkedList: public Stack{
    LinkedList* list;
    
    public:
    StackLinkedList(){
        list = new LinkedList();
    }
    
    void push(int num){
        list->addHead(num);
    }
    
    int pop(){
        return list->removeHead();
    }
    
    int top(){
        return isEmpty() ? -1 : list->head->elem;
    }
    
    int sizeList(){
        return list->getSize();
    }
    
    bool isEmpty(){
        return list->getSize() == 0;
    }
};