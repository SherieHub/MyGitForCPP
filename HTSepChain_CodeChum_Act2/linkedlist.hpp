
#include <bits/stdc++.h>
#include "node.hpp"
#include <iostream>
using namespace std;
class LinkedList {
    // IMPLEMENT ME
    node* head;
    node* tail;
    int size;
    
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void addTail(string elem) {
        node* n = new node;
        n->elem = elem;
        n->next = nullptr;  

        if (!head) {
            head = n;
            tail = head;
        } else {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void addHead(string elem) {
        node* n = new node;
        n->elem = elem;
        n->next = head;  

        if (!head) {
            tail = n;  
        }
        head = n;
        size++;
    }

    int removeNode(string elem) {
        node* curr = head;
        node* prev = nullptr;

        while (curr) {
            if (curr->elem == elem) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = head->next;
                }

                if (curr == tail) {
                    tail = prev;  
                }

                delete curr;
                size--;

                if (size == 0) {
                    head = tail = nullptr;  
                }

                return getSize();  
            }
            prev = curr;
            curr = curr->next;
        }
        return -1;  
    }

    string search(string elem) {
        node* curr = head;

        while (curr) {
            if (curr->elem == elem) {
                return curr->elem;
            }
            curr = curr->next;
        }
        return "";  
    }

    int getSize() {
        return size;
    }

    void print() {
        node* curr = head;
        if (!curr) return;  

        while (curr) {
            cout << curr->elem << "\t";
            curr = curr->next;
        }
    }
};