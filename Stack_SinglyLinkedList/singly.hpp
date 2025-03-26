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
    
    void addHead(int num){ // T(n) = 12
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
    
    int removeHead(){ // T(n) = 9
        if(!head) return -1;
        
        node* temp = head;
        int removedNum = head->elem;
        head = head->next;
        free(temp);
        size--;
        
        return removedNum;
    }
    
    int get(int pos){ //T(n) =
        node* curr = head;
<<<<<<< HEAD
        
        for(int i = 1; i < pos; i++){
=======
        for (int i = 1; i < pos; i++) {
>>>>>>> 699068edbef174ec0ab845b475686dffc7bd8948
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



