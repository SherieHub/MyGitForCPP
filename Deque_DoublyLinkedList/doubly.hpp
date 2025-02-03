#include "node.hpp"
#include "list.hpp"
#include <iostream>
using namespace std;

class DoublyLinkedList : public List{
    node* head;
    node* tail;
    int size;
    
    void addBetween(int elem, node* pred, node* succ){
        node* n = new node;
        n->elem = elem;
        n->next = succ;
        n->prev = pred;
        pred->next = n;
        succ->prev = n;
        size++;
    }
    
    int removeNode(node* n){
        int ret = n->elem;
        
        node* pred = n->prev;
        node* succ = n->next;
        pred->next = succ;
        succ->prev = pred;
        
        delete n;
        size--;
        
        return ret;
    }
    
    public:
    
    DoublyLinkedList(){
        head = new node;
        tail = new node;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addHead(int num){
        addBetween(num, head, head->next);
    }
    
    void addTail(int num){
        addBetween(num, tail->prev, tail);
    }
    
    int removeHead(){
        if(size == 0) return -1;
        return removeNode(head->next);
    }
    
   int removeTail(){
       if(size == 0) return -1;
       return removeNode(tail->prev);
   }
   
   int _size(){
       return size;
   }
   
   void print(){
       cout << "DEQUE_DOUBLYLINKEDLIST:" <<endl;
       node* curr = head->next;
       
       cout << "FROM HEAD: ";
       while(curr != tail){
           cout << curr->elem;
           if(curr->next != tail){
               cout << " -> ";
           }
           curr = curr->next;
       }
       cout << endl;
       
       curr = tail->prev;
       cout << "FROM TAIL: ";
       while(curr != head){
           cout << curr->elem;
           if(curr->prev != head){
               cout << " -> ";
           }
           curr = curr->prev;
       }
       cout << endl <<endl;
   }
};