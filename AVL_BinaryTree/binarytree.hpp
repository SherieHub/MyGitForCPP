#include "node.hpp"
#include <string>
#include <queue>
#include <iostream>
using namespace std;

class BinaryTree{
    public:
    node* root;
    int size;
    
    BinaryTree(){
        root = NULL;
        size = 0;
    }
    
    void zigleft(node* n) {
        node* y = n->right;
        n->right = y->left;
        if (y->left) y->left->parent = n;
        
        y->left = n;
        y->parent = n->parent;
        
        if (!n->parent) root = y;
        else if (n->parent->left == n) n->parent->left = y;
        else n->parent->right = y;
        
        n->parent = y;
    }
    
    void zigright(node* n) {
        node* y = n->left;
        n->left = y->right;
        if (y->right) y->right->parent = n;
    
        y->right = n;
        y->parent = n->parent;
    
        if (!n->parent) root = y;
        else if (n->parent->left == n) n->parent->left = y;
        else n->parent->right = y;
    
        n->parent = y;
    }

    void restructure(node* n) {
        node* y = n->left;
        if (n->right && n->right->height() > (y ? y->height() : -1)) {
            y = n->right;
        }
    
        node* x = y->left;
        if (y->right && y->right->height() > (x ? x->height() : -1)) {
            x = y->right;
        }
    
        if (y == n->right) {
            if (x == y->left) {
                zigright(y);
                zigleft(n);
            } else {
                zigleft(n);
            }
        } else {
            if (x == y->left) {
                zigright(n);
            } else {
                zigleft(y);
                zigright(n);
            }
        }
    }

    
    node* addRoot(int elem){
        if(root) throw logic_error("Already has root!");
        
        root = new node();
        root->elem = elem;
        size++;
        return root;
    }
    
    node* addLeft(node* p, int elem){
        if(p->left) throw logic_error(to_string(p->elem) + "already has left child");
        
        p->left = new node();
        p->left->elem = elem;
        p->left->parent = p;
        size++;
        return p->left;
    }
    
    node* addRight(node* p, int elem){
        if(p->right) throw logic_error(to_string(p->elem) + "already has right child");
        
        p->right = new node();
        p->right->elem = elem;
        p->right->parent = p;
        size++;
        return p->right;
    }
    
    void removeNode(node* n){
    if(!n->left || !n->right){
        node* child = n->right ? n->right : n->left;
        node* par = n->parent;

        if(root == n){
            root = child;
            if(child){
                child->parent = nullptr;
            }
        }else{
            if(par->left == n){
                par->left = child;
            }else{
                par->right = child;
            }

            if(child) child->parent = par;
        }

        delete n;
        size--;

        while(par){
            int lh = par->left ? par->left->height() : -1;
            int rh = par->right ? par->right->height() : -1;

            if(abs(lh - rh) > 1){
                restructure(par);
            }
            par = par->parent;
        }
    }
}

    
    bool insert(node* n, int elem){
        if(!n){
            addRoot(elem);
            return true;
        }
    
        if(elem < n->elem){
            if(n->left) return insert(n->left, elem);
            addLeft(n, elem);
    
            node* par = n;
            while(par){
                int lh = par->left ? par->left->height() : -1;
                int rh = par->right ? par->right->height() : -1;
    
                if(abs(lh - rh) > 1){
                    restructure(par);
                    break; 
                }
                par = par->parent;
            }
            return true;
    
        }else if(elem > n->elem){
            if(n->right) return insert(n->right, elem);
            addRight(n, elem);
    
            node* par = n;
            while(par){
                int lh = par->left ? par->left->height() : -1;
                int rh = par->right ? par->right->height() : -1;
    
                if(abs(lh - rh) > 1){
                    restructure(par);
                    break; 
                }
                par = par->parent;
            }
            return true;
    
        }else{
            return false; 
        }
    }
    
    bool search(node* n, int elem){
        if(!n) return false;
        if(elem < n->elem){
            return search(n->left, elem);
        }else if(elem > n->elem){
            return search(n->right, elem);
        }
        return (elem == n->elem) ? true : false;
    }
    
    bool _remove(node* n, int elem){
        if(!n) return false;
    
        if(elem < n->elem){
            return _remove(n->left, elem);
        }else if(elem > n->elem){
            return _remove(n->right, elem);
        }else{
            if(n->left && n->right){
                node* temp = n->right;
                while(temp->left){
                    temp = temp->left;
                }
                n->elem = temp->elem;
                _remove(n->right, temp->elem);
                return true;
            }else{
                removeNode(n);  
                return true;
            }
        }
        return false;
    }

    
    bool verify_preorder(int* arr, int begin, int end) {
        if (begin >= end) return true;  
    
        int root = arr[begin];  
        int boundary = begin + 1;
    
        while (boundary < end && arr[boundary] < root) {
            boundary++;
        }
    
        for (int i = boundary; i < end; i++) {
            if (arr[i] < root) return false;
        }
        return verify_preorder(arr, begin + 1, boundary) && verify_preorder(arr, boundary, end);
    }
    

    void print(){
        queue<node*> q;
        
        cout << "BinaryTree: ";
        
        q.push(root);
        
        while(!q.empty()){
            node* curr = q.front();
            q.pop();
            cout << curr->elem << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    
};
