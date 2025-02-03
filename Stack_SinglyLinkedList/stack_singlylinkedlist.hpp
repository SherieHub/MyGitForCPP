
#include "stack.hpp"
#include "singly.hpp"

class StackLinkedList: public Stack{
    LinkedList* list;
    
    public:
    StackLinkedList(){
        list = new LinkedList();
    }
    
    void push(int num){ // T(n) = 14
        list->addHead(num);
    }
    
    int pop(){  // T(n) = 11
        return list->removeHead();
    }
    
    int top(){ // T(n) = 6
        return isEmpty() ? -1 : list->head->elem;
    }
    
    int sizeList(){ // T(n) = 2
        return list->getSize();
    }
    
    bool isEmpty(){ //T(n) = 3
        return list->getSize() == 0;
    }
};