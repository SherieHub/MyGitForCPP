#include "tree.hpp"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BinaryTree : public Tree{
    node* root;
    int size;
    
    public:
    
    BinaryTree(){
        root = nullptr;
        size = 0;
    }
    
    node* addRoot(int elem){
        if(root) throw logic_error("Already has root!");
        
        root = new node;
        root->elem = elem;
        size++;
        return root;
    }
    
    node* addLeft(node* p, int elem){
        if(p->left) throw logic_error(to_string(p->elem) + "already has left child");
        
        p->left = new node;
        p->left->elem = elem;
        p->left->parent = p;
        size++;
        return p->left;
    }
    
    node* addRight(node* p, int elem){
        if(p->right) throw logic_error(to_string(p->elem) + "already has right child");
        
        p->right = new node;
        p->right->elem = elem;
        p->right->parent = p;
        size++;
        return p->right;
    }
    
    bool removeNode(node* n){
        if(!n->left || !n->right){
            int temp = n->elem;
            node* child = n->right ? n->right: n->left;
            
            if(n == root){
                root = child;
                if(child){
                    child->parent = NULL;
                }
            }else{
                node* p = n->parent;
                
                if(p->right == n){
                    p->right = child;
                }else{
                    p->left = child;
                }
            
                if(child){
                    child->parent = p;
                }
            }
            free(n);
            size--;
            return temp;
        }
        throw logic_error("Cannot remove since " + to_string(n->elem) + " has 2 children.");
    }
    
    node* getNode(node* p, int num) {
        if (!p) return NULL;

        if (p->elem == num) return p;

        node* foundNode = getNode(p->left, num);
        if (!foundNode) {  
            foundNode = getNode(p->right, num);
        }
        return foundNode;
    }

    
    void printPreOrder(node* p){ //VLR
        if(!p) return;
        cout << p->elem << " ";
        printPreOrder(p->left);
        printPreOrder(p->right);
    }
    
    void printInOrder(node* p){ //LVR
        if(!p) return;
        printInOrder(p->left);
        cout << p->elem << " ";
        printInOrder(p->right);
    }  
    
    void printPostOrder(node* p){ //LRV
        if(!p) return;
        printPostOrder(p->left);
        printPostOrder(p->right);
        cout << p->elem << " ";
    } 
    
    void printBreadthFirst(node* p){
        queue<node*> q;
        
        q.push(p);
        
        while(!q.empty()){
            node* curr = q.front();
            cout << curr->elem << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            q.pop();
        }
    }
    
    node* getRoot(){
        return root;
    }
};
