#include "list.hpp"
#include "node.hpp"
#include <iostream>
using namespace std;

class DoublyLinkedList : public List{
    node* head;
    node* tail;
    int size;
    
    //helper methods
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
        node* pred = n->prev;
        node* succ = n->next;
        pred->next = succ;
        succ->prev = pred;
        int ret = n->elem;
        free(n);
        size--;
        return ret;
    }
    
    public:
    
    DoublyLinkedList(){
        head = new node; //header
        tail = new node; //trailer
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
    
    void addAt(int num, int pos){
        if(pos < 0 || pos > size + 1) return;
        
        if(pos == 1){
            addHead(num);
        }else if(pos == size + 1){
            addTail(num);
        }else{
            node* curr = head->next;
            
            for(int i = 1; i < pos - 1; i++){
                curr = curr->next;
            }
            addBetween(num, curr, curr->next);
        }
    }
    
    
    int removeHead(){
        if(head->next == tail) return -1;
        return removeNode(head->next);
    }
    
    int removeTail(){
        if(head->next == tail) return -1;
        return removeNode(tail->prev);
    }
    
    int removeAt(int pos){
        if(pos < 0 || pos > size) return -1;
        
        if(pos == 1){
            return removeHead();
        }else if(pos == size){
            return removeTail();
        }else{
            node* curr = head->next;
            
            
            for(int i = 1; i < pos; i++){
                curr = curr->next;
            }
            return removeNode(curr);
        }
    }
    
    int get(int pos){
        if(pos < 0 || pos > size) return -1;
        node* curr = head->next;
        
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        return curr->elem;
    }
    
    void print(){
        cout << endl << "DOUBLY_LINKEDLIST: " << endl;
        node* curr = head->next;
        
        cout << "FROM HEAD: ";
        while(curr != tail){
            cout << curr->elem;
            if(curr != tail->prev){
                cout << " -> ";
            }
            curr = curr->next;
        }
        
        curr = tail->prev;
        
        cout << endl << "FROM TAIL: ";
        while(curr != head){
            cout << curr->elem;
            if(curr != head->next){
                cout << " -> ";
            }
            curr = curr->prev;
        }
        
        cout << endl << "SIZE: " << size << endl << endl;
    }
};




