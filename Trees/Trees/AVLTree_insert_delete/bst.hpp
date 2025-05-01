#include "mybinarytree.hpp"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BST {
	BinaryTree* tree = new MyBinaryTree();
    
	public:
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			// proceed to right
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}

    // TODO perform post-processing by checking for violation after insertion
    // from the node inserted (or from its parent) until the root
	node* insert(int num) {
		node* n = insert_node(tree->getRoot(), num);
		if (n) {
			checkBalance(n);
		}
		return n;
	}

	node* insert_node(node* n, int num) {
		if (n == NULL) {
			return tree->addRoot(num);
		}
		if (n->elem == num) {
			return NULL;
		}
		if (num > n->elem) {
			if (!n->right) {
				return tree->addRight(n, num);
			} else {
				return insert_node(n->right, num);
			}
		} else {
			if (!n->left) {
				return tree->addLeft(n, num);
			} else {
				return insert_node(n->left, num);
			}
		}
	}

    bool remove(int num){
        node* parOfRemoved = remove_node(tree->getRoot(), num);
        if(parOfRemoved){
            checkBalance(parOfRemoved);
            return true;
        }
        return false;
    }

    node* remove_node(node* n, int num){
        if(n == NULL) return NULL;
        if(n->elem == num){
            if(n->left && n->right){
                node* r = n->right;
                while(r->left){
                    r = r->left;
                }
                n->elem = r->elem;
                return remove_node(r, r->elem);
            }
            
            node* parent = n->parent;
            tree->remove(n);
            return parent;
        }
        return remove_node(num > n->elem ? n->right : n->left, num);
    }
    
    void checkBalance(node* n){
        while(n){
            int balance = getBalance(n);
            if(abs(balance) > 1){
                n = restructure(n);
            }
            n = n->parent;
        }
    }
    
    int getBalance(node* n){
        if(n == NULL){
            return 0;
        }
        int lh = n->left ? n->left->height() : -1;
        int rh = n->right ? n->right->height() : -1;
        
        return lh-rh;
    }
    
    node* restructure(node* gp) {
        node* par = (getBalance(gp) > 1 ? gp->left : gp->right);
        
        bool gtop_right = (gp->right == par);
        
        int parBalance = getBalance(par);
        node* child;
        
        if(parBalance > 0) child = par->left;
        else if(parBalance < 0) child = par->right;
        else child = gtop_right ? par->right : par->left;
        
        bool ptoc_right = (par->right == child);
        
        if(gtop_right && ptoc_right){
            zigleft(par);
            cout << "ZIGLEFT" << endl;
            
        }else if(gtop_right && !ptoc_right){
            cout << "ZIGZAGLEFT" << endl;
            zigright(child);
            zigleft(child);
        }else if(!gtop_right && !ptoc_right){
            cout << "ZIGRIGHT" <<endl;
            zigright(par);
        }else{
            cout << "ZIGZAGRIGHT" << endl;
            zigleft(child);
            zigright(child);
        }
        return child ? child : par;
    }
    
    
    void zigleft(node* curr) {
        tree->zigleft(curr);
    }

    void zigright(node* curr) {
        tree->zigright(curr);
    }

	void print() {
		tree->print();
	}
};