#include "list.hpp"
#include <iostream>
using namespace std;

class SinglyLinkedList : public List{
    node* head;
    node* tail;
    int size;
    
    public:
    
    SinglyLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void addHead(int num){
        node* n = new node;
        n->elem = num;
        
        if(!head){
            head = n;
            tail = head;
        }else{
            n->next = head; 
            head = n;
        }
        size++;
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
    
    void addAt(int num, int pos){
        if(pos < 1 || pos > size + 1) return;
        
        if(pos == 1){
            addHead(num);
        }else if(pos == size + 1){
            addTail(num);
        }else{
            node* n = new node;
            n->elem = num;
            node* curr = head;
            
            for(int i = 1; i < pos-1; i++){
                curr = curr->next;
            }
            
            n->next = curr->next;
            curr->next = n;
            
            size++;
        }
    }

    int removeHead(){
        if(!head) return -1;
        
        node* temp = head;
        int ret = head->elem;
        
        if(size == 1){
            head = nullptr;
            tail = nullptr;
        }else{
            head = head->next;
        }
        delete temp;
        size--;
        return ret;
    }
    
    int removeTail(){
        if(!head) return -1;
        
        node* curr = head;
        node* prev = nullptr;
        int ret = tail->elem;
            
        if(size == 1){
            head = nullptr;
            tail = nullptr;
        }else{
            while(curr->next){
                prev = curr;
                curr = curr->next;
            }
            tail = prev;
            tail->next = nullptr;
        }
        delete curr;
        size--;
        return ret;
    }
    
    int removeAt(int pos){
        if(!head) return -1;
        if(pos < 1 || pos > size) return -1;
        
        if(pos == 1){
            return removeHead();
        }else if(pos == size){
            return removeTail();
        }else{
            node* curr = head;
            node* prev = nullptr;
        
            for(int i = 1; i < pos; i++){
                prev = curr;
                curr = curr->next;
            }
            int ret = curr->elem;
            prev->next = curr->next;
            delete curr;
            size--;
            return ret;
        }
    }
    
    int get(int pos){
        node* curr = head;
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        return curr->elem;
    }
    
    void print(){
        cout << "SINGLYLINKEDLIST: ";
        node* curr = head;
        
        while(curr){
            cout << curr->elem;
            if(curr->next != NULL){
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
        
        cout << "SIZE: " << size << endl << endl;
    }
    
};