#include "deque.hpp"
#include "linkedlist.hpp"
#include <iostream>
using namespace std;

class DoublyDeque: public Deque{
    LinkedList* list;

public:

    DoublyDeque(){
        list = new LinkedList();
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
        return list->getSize();
    }

    bool isEmpty(){
        return list->getSize() == 0;
    }

    void _print(){
        list->print();
    }
};
