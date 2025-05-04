#include "node.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class BSTree {
    node* root;
    int size;

    node* create_node(int num, node* parent) {
        node* n = (node*) malloc( sizeof(node) );
        n->element = num;
        n->parent = parent;
        n->right = NULL;
        n->left = NULL;
        return n;
    }

    bool search(node* n, int num) {
        if(!n) return false;
        
        if(num < n->element){
            return search(n->left, num);
        }else if(num > n->element){
            return search(n->right, num);
        }else if(num == n->element){
            restructure(n);
            return true;
        }
        return false;
    }
    
    node* addRoot(int num){
        if(root) throw logic_error("Already has root");
        
        root = new node;
        root->element = num;
        size++;
        return root;
    }
    
    node* addLeft(node* p, int num){
        if(p->left) throw logic_error(to_string(p->element) + "Already has left child");
        
        p->left = new node;
        p->left->element = num;
        p->left->parent = p;
        size++;
        return p->left;
    }
      
    node* addRight(node* p, int num){
        if(p->right) throw logic_error(to_string(p->element) + "Already has right child");
        
        p->right = new node;
        p->right->element = num;
        p->right->parent = p;
        size++;
        return p->right;
    } 
    
    bool insert_node(node* n, int num) {
        if(!n){
            addRoot(num);
            return true;
        }
        
        node* m;
        
        if(num < n->element){
            if(n->left) return insert_node(n->left, num);
            m = addLeft(n, num);
            restructure(m);
            return true;
        }else if(num > n->element){
            if(n->right) return insert_node(n->right, num);
            m = addRight(n, num);
            restructure(m);
            return true;
        }else{
            return false;
        }
    }
    
    bool _remove(node* n, int num){
        if(!n) return false;
        
        if(num < n->element){
            return _remove(n->left, num);
        }else if(num > n->element){
            return _remove(n->right, num);
        }else if(num == n->element){
            remove_restructure(n);
            
            node* leftSubtree = n->left;
            node* rightSubtree = n->right;
            
            if(leftSubtree) leftSubtree->parent = NULL;
            if(rightSubtree) rightSubtree->parent = NULL;
            
            delete n;
            size--;
            
            if(!rightSubtree){
                root = leftSubtree;
            }else{
                node* temp = rightSubtree;
                
                while(temp->left){
                    temp = temp->left;
                }
                
                remove_restructure(temp);
                root = temp;
                
                root->left = leftSubtree;
                if(leftSubtree) leftSubtree->parent = root;
            }
            return true;
        }
        return false;
    }

    public:
    BSTree() {
        root = NULL;
        size = 0;
    }

    bool search(int num) {
        return search(root, num);
    }
    
    bool insert(int num){
        if(!root){
            root = addRoot(num);
            return true;
        }
        return insert_node(root, num);
    }
    
    bool remove(int num){
        return _remove(root, num);
    }
    
    void zigLeft(node* x){
        node* y = x->parent;
        node* z = y->parent;
        node* t2 = x->left;
        
        if(!y || !x) return;
        
        if(z){
            if(z->left == y){
                z->left = x;
            }else{
                z->right = x;
            }
            x->parent = z;
        }else{
            root = x;
            x->parent = NULL;
        }
        
        x->left = y;
        y->parent = x;
        y->right = t2;
        
        if(t2){
            t2->parent = y;
        }
    }
    
    void zigRight(node* x){
        node* y = x->parent;
        node* z = y->parent;
        node* t2 = x->right;
        
        if(!y || !x) return;
        
        if(z){
            if(z->left == y){
                z->left = x;
            }else{
                z->right = x;
            }
            x->parent = z;
        }else{
            root = x;
            x->parent = NULL;
        }
        
        x->right = y;
        y->parent = x;
        y->left = t2;
        
        if(t2){
            t2->parent = y;
        }
    }
    
    void restructure(node* x){
        while(x->parent){
            node* y = x->parent;
            node* z = y->parent;
            
            if(!y) return;
            
            if(!z){
                if(y->right == x){
                    zigLeft(x);
                    cout << "ZIGLEFT" << endl;
                }else{
                    zigRight(x);
                    cout << "ZIGRIGHT" << endl;
                }
                break;
            }
            
            if(z->right == y && y->right == x){
                zigLeft(y);
                zigLeft(x);
                cout << "ZIGZIGLEFT" <<endl;
            }
            else if(z->right == y && y->left == x){
                zigRight(x);
                zigLeft(x);
                cout << "ZIGZAGLEFT" << endl;
            }
            else if(z->left == y && y->left == x){
                zigRight(y);
                zigRight(x);
                cout << "ZIGZIGRIGHT" <<endl;
            }
            else if(z->left == y && y->right == x){
                zigLeft(x);
                zigRight(x);
                cout << "ZIGZAGRIGHT" << endl;
            }
            root = x;
        }
    }
    
    void remove_restructure(node* x){
        while(x->parent){
            node* y = x->parent;
            node* z = y->parent;
            
            if(!y) return;
            
            if(!z){
                if(y->right == x){
                    zigLeft(x);
                }else{
                    zigRight(x);
                }
                break;
            }
            
            if(z->right == y && y->right == x){
                zigLeft(y);
                zigLeft(x);
            }
            else if(z->right == y && y->left == x){
                zigRight(x);
                zigLeft(x);
            }
            else if(z->left == y && y->left == x){
                zigRight(y);
                zigRight(x);
            }
            else if(z->left == y && y->right == x){
                zigLeft(x);
                zigRight(x);
            }
            root = x;
        }
    }
    
    // WARNING. Do not modify the methods below.
    // Doing so will nullify your score for this activity.
    void print() {
        if (isEmpty()) {
            cout << "EMPTY" << endl;
            return;
        }
        cout << "PRE-ORDER: ";
        print_preorder(root);
        cout << endl << "IN-ORDER: ";
        print_inorder(root);
        cout << endl << "POST-ORDER: ";
        print_postorder(root);
        cout << endl << "STATUS: " << check_parent(root, NULL) << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print_preorder(node* curr) {
        cout << curr->element << " ";
        if (curr->left != NULL) {
            print_preorder(curr->left);
        }
        if (curr->right != NULL) {
            print_preorder(curr->right);
        }
    }

    void print_inorder(node* curr) {
        if (curr->left != NULL) {
            print_inorder(curr->left);
        }
        cout << curr->element << " ";
        if (curr->right != NULL) {
            print_inorder(curr->right);
        }
    }

    void print_postorder(node* curr) {
        if (curr->left != NULL) {
            print_postorder(curr->left);
        }
        if (curr->right != NULL) {
            print_postorder(curr->right);
        }
        cout << curr->element << " ";
    }

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of " << curr->element << ": NULL -- must be " << par->element << endl;
            } else if (!par) {
                cout << "Illegal parent of " << curr->element << ": " << curr->parent->element << "must be NULL" << endl;
            } else {
                cout << "Illegal parent of " << curr->element << ": " << curr->parent->element << " -- must be " << par->element << endl;
            }
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }
};