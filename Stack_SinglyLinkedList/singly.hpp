#include "list.hpp"
#include "node.hpp"
#include <iostream>
using namespace std;

class LinkedList: public List{
    node* tail;
    int size = 0;
    
    public:
    node* head;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    void addHead(int num){
        node* n = (node*)calloc(1, sizeof(node));
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
    
    int removeHead(){
        if(!head) return -1;
        
        node* temp = head;
        int removedNum = head->elem;
        head = head->next;
        free(temp);
        size--;
        
        return removedNum;
    }
    
    int get(int pos){
        node* curr = head;
        
        for(int i = 1; i < pos; i++){
            curr = curr->next;
        }
        
        return curr->elem;
    }
    
    int getSize(){
        return size;
    }
    
    void print(){
        node* curr = head;
        
        cout << "LinkedList: ";
        while(curr){
            cout << curr->elem;
            if(curr->next != NULL){
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};



