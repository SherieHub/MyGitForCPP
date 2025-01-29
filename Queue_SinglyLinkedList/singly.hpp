
#include "node.hpp"
#include "list.hpp"
#include <iostream>
using namespace std;

class SinglyLinkedList: public List{
    node* tail;
    int size;
    
    public:
    node* head;
    
    SinglyLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void addTail(int num){
        node* n = new node;
        n->elem = num;
        
        if(!head){
            head = n;
            tail = head;
        }else{
            tail->next = n;
            tail = n;
        }
        size++;
    }
    
    int removeHead(){
        node* temp = head;
        int ret = head->elem;
        
        head = head->next;
        delete temp;
        size--;
        
        return ret;
    }
    
   int _size(){
       return size;
   }
   
   void print(){
       cout << "SinglyLinkedList: ";
       node* curr = head;
       
       while(curr){
           cout << curr->elem;
           if(curr->next != nullptr){
               cout << " -> ";
           }
           curr = curr->next;
       }
       cout << endl;
   }
    
};







