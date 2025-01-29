#include "list.hpp"
#include "node.hpp"
#include <iostream>
using namespace std;

class LinkedList : public List{
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
        node* pred = n->prev;
        node* succ = n->next;
        pred->next = succ;
        succ->prev = pred;
        int removedNum = n->elem;
        free(n);
        size--;
        return removedNum;
    }

public:

    LinkedList(){
        head = new node;  //header
        tail = new node;  //trailer
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    void addTail(int elem){
        addBetween(elem, tail->prev, tail);
    }

    void addHead(int elem){
        addBetween(elem, head, head->next);
    }


    int removeHead(){
        return removeNode(head->next);
    }

    int removeTail(){
        return removeNode(tail->prev);
    }

    int getSize(){
        return size;
    }

    void print(){
        node* curr = head->next;

        if(size == 0){
            cout << "List is Empty!" <<endl;
        }

        cout << "\nFrom HEAD: ";
        while(curr != tail){
            cout << curr->elem;
            if(curr->next != tail){
                cout << " -> ";
            }
            curr = curr->next;
        }

        curr = tail->prev;

        cout << "\nFrom TAIL: ";
        while(curr != head){
            cout << curr->elem;
            if(curr->prev != head){
                cout << " -> ";
            }
            curr = curr->prev;
        }

        cout << endl;
    }
};
