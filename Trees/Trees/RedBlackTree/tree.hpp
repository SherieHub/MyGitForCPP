#include "node.hpp"
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
class BSTree {
    node* root;
    int size;

    public:
    BSTree() {
        root = NULL;
        size = 0;
    }
    
    node* addRoot(int num){
        if(root) return nullptr;
        
        root = new node;
        root->element = num;
        root->is_red = false;
        size++;
        return root;
    }
    
    node* addLeft(node* p, int num){
        node* n = new node;
        
        n->element = num;
        n->parent = p;
        p->left = n;
        size++;
        return n;
    }
    
    node* addRight(node* p, int num){
        node* n = new node;
        
        n->element = num;
        n->parent = p;
        p->right = n;
        size++;
        return n;
    }

    bool insert(int num) {
        insertNode(root, num);
        return false;
    }
    
    bool insertNode(node* n, int num){
        if(!n){
            rebalance_insert(addRoot(num));
            return true;
        }
        if(num < n->element){
            if(n->left){
                return insertNode(n->left, num);
            }
            node* inserted = addLeft(n, num);
            inserted->is_red = true;
            rebalance_insert(inserted);
            return true;
        }
        if(num > n->element){
            if(n->right){
                return insertNode(n->right, num);
            }
            node* inserted = addRight(n, num);
            inserted->is_red = true;
            rebalance_insert(inserted);
            return true;
        }
        return false;
    }
    
    // void zigLeft(node* curr){
    //     node* t2 = curr->left;
    //     node* par = curr->parent;
        
    //     if(!par) return;
        
    //     node* gp = par->parent;
        
    //     if(gp){
    //         if(gp->left == par){
    //             gp->left = curr;
    //         }else{
    //             gp->right = curr;
    //         }
    //         curr->parent = gp;
    //     }
        
    //     curr->left = par;
    //     par->parent = curr;
    //     par->right = t2;
        
    //     if(t2){
    //         t2->parent = par;
    //     }
        
    //     if(!gp){
    //         root = curr;
    //         curr->parent = nullptr;
    //     }
    // }
    
    // void zigRight(node* curr){
    //     node* t2 = curr->right;
    //     node* par = t2->parent;
        
    //     if(!par) return;
        
    //     node* gp = par->parent;
        
    //     if(gp){
    //         if(gp->left == par){
    //             gp->left = curr;
    //         }else{
    //             gp->right = curr;
    //         }
    //         curr->parent = gp;
    //     }
        
    //     curr->right = par;
    //     par->parent = curr;
    //     par->left = t2;
        
    //     if(t2){
    //         t2->parent = par;
    //     }
        
    //     if(!gp){
    //         root = curr;
    //         curr->parent = nullptr;
    //     }
    // }
    
    node* zigLeft(node* curr){
        node* y = curr->parent;
        node* x = y->parent;
        
        if(y == root){
            root = curr;
        }else if(x->left == y){
            x->left = curr;
        }else{
            x->right = curr;
        }
        
        curr->parent = y->parent;
        y->right = curr->left;
        
        if(curr->left){
            curr->left->parent = y;
        }
        
        curr->left = y;
        y->parent = curr;
        return curr;
    }
    
    node* zigRight(node* curr){
        node* y = curr->parent;
        node* x = y->parent;
        
        if(y == root){
            root = curr;
        }else if(x->right == y){
            x->right = curr;
        }else{
            x->left = curr;
        }
        
        curr->parent = y->parent;
        y->left = curr->right;
        
        if(curr->right){
            curr->right->parent = y;
        }
        
        curr->right = y;
        y->parent = curr;
        return curr;
    }
    
    node* restructure(node* x){
        node* y = x->parent;
        node* z = y->parent;
        
        if(!y || !z) return nullptr;
        
        node* m = nullptr;
        
        if(y == z->right && x == y->right){
            zigLeft(y);
            cout << "ZIGLEFT" << endl;
            return y;
        }else if(y == z->left && x == y->left){
            zigRight(y);
            cout << "ZIGRIGHT" << endl;
            return y;
        }else if(y == z->right && x == y->left){
            cout << "ZIGZAGLEFT" << endl;
            zigRight(x);
            zigLeft(x);
            return x;
        }else if(y == z->left && x == y->right){
            cout << "ZIGZAGRIGHT" << endl;
            zigLeft(x);
            zigRight(x);
            return x;
        }
        return nullptr;
    }
    
    void rebalance_insert(node* n){
        if(!n) return;
        
        if(n == root){
            n->is_red = false;
            return;
        }
        
        node* par = n->parent;
        node* gp = par->parent;
        
        // if(!par || !gp) return;
        
        if(par->is_red){
            node* uncle = isLeft(par)? gp->right : gp->left;
            if(!uncle || !uncle->is_red){
                cout << "INSERTION Violation: Case 1" << endl;
                node* m = restructure(n);
                
                if(m){
                    m->is_red = false;
                    if(m->left) m->left->is_red = true;
                    if(m->right) m->right->is_red = true;
                    return;
                }
            }else{
                cout << "INSERTION Violation: Case 2" << endl;
                gp->is_red = true;
                par->is_red = false;
                uncle->is_red = false;
                rebalance_insert(gp);
            }
        }
    }
    
    bool isLeft(node* n){
        node* p = n->parent;
        if(p->left == n) return true;
        return false;
    }
    
    // void makeBlack(node* n){
    //     if(n) n->is_red = false;;
    // }
    
    // void makeRed(node* n){
    //     if(n) n->is_red = true;
    // }
    
    // bool isBlack(node* n){
    //     return n->is_red;
    // }
    
    // bool isRed(node* n){
    //     return n->is_red;
    // }

    // WARNING. Do not modify these methods below.
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
        cout << curr->element;
        if (curr->is_red) {
            cout << "(R) ";
        } else {
            cout << "(B) ";
        }
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
        cout << curr->element;
        if (curr->is_red) {
            cout << "(R) ";
        } else {
            cout << "(B) ";
        }
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
        cout << curr->element;
        if (curr->is_red) {
            cout << "(R) ";
        } else {
            cout << "(B) ";
        }
    }

    // WARNING. Do not modify this method.
    // Doing so will nullify your score for this activity.
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