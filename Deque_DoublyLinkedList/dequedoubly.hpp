#include "doubly.hpp"
#include "deque.hpp"
#include <iostream>
using namespace std;

class Deque_DoublyLinkedList : public Deque{
    DoublyLinkedList* list;
      
    public:
      
    Deque_DoublyLinkedList(){
        list = new DoublyLinkedList();
    }
  
    void addFirst(int num){
      list->addHead(num);
    }
    
    void addLast(int num){
      list->addTail(num);
    }
    
    int removeFirst(){
        return isEmpty() ? -1 : list->removeHead();
    }
    
    int removeLast(){
        return isEmpty() ? -1 : list->removeTail();
    }
    
    int _size(){
        return list->_size();
    }
    
    bool isEmpty(){
        return _size() == 0;
    }
    
    void _print(){
        list->print();
    }

};
