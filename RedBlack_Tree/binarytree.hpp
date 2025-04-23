#include "node.hpp"
#include <iostream>
#include <stdexcept>
#include <queue>

using namespace std;

class BinaryTree {
public:
    node* root;
    int size;

    BinaryTree() : root(nullptr), size(0) {}

    node* addRoot(int num) {
        if (root) throw logic_error("Already has root");

        root = new node;
        root->elem = num;
        size++;
        return root;
    }

    node* addLeft(node* p, int num) {
        if (p->left) throw logic_error(to_string(p->elem) + " already has left child");

        p->left = new node;
        p->left->elem = num;
        p->left->parent = p;
        size++;
        return p->left;
    }

    node* addRight(node* p, int num) {
        if (p->right) throw logic_error(to_string(p->elem) + " already has right child");

        p->right = new node;
        p->right->elem = num;
        p->right->parent = p;
        size++;
        return p->right;
    }
    
    bool insert_node(node* n, int num) {
        if (!n) {
            rebalance_insert(addRoot(num));
            return true;
        }
    
        if (num < n->elem) {
            if (n->left) {
                return insert_node(n->left, num);
            }
            node* inserted = addLeft(n, num);
            rebalance_insert(inserted);
            return true;
        } else if (num > n->elem) {
            if (n->right) {
                return insert_node(n->right, num);
            }
            node* inserted = addRight(n, num);
            rebalance_insert(inserted);
            return true;
        } else {
            return false;  
        }
    }
    
     bool insert(int num){
        if(insert_node(root, num)) return true;
        return false;
    }

    void rebalance_insert(node* n) {
        if (!n) return;

        if (n == root) {
            makeBlack(n);
            return;
        }

        makeRed(n);

        node* par = n->parent;
        if (par == nullptr) return; 
        
        node* gp = par->parent;
        if (gp == nullptr) return;

        if (isRed(par)) {
            node* uncle = gp->right == par ? gp->left : gp->right; 
            if (isBlack(uncle)) {
                node* m = restructure(n);
                if (m) {
                    makeBlack(m);
                    if(m->left) makeRed(m->left);
                    if(m->right) makeRed(m->right);
                }
            } else {
                makeRed(gp);
                makeBlack(par);
                makeBlack(uncle);
                rebalance_insert(gp);
            }
        }
    }

    void makeBlack(node* n) {
        if(n) n->color = BLACK;
    }

    void makeRed(node* n) {
        if(n) n->color = RED;
    }

    bool isRed(node* n) {
        return n != nullptr && n->color == RED;
    }

    bool isBlack(node* n) {
        return n == nullptr || n->color == BLACK;
    }

    void zigLeft(node* curr) {
        node* t2 = curr->left;
        node* par = curr->parent;

        if (!par) return;

        node* gp = par->parent;

        if (gp) {
            if (gp->right == par) {
                gp->right = curr;
            } else {
                gp->left = curr;
            }
            curr->parent = gp;
        }

        curr->left = par;
        par->parent = curr;
        par->right = t2;

        if (t2) {
            t2->parent = par;
        }

        if (!gp) {
            root = curr;
            curr->parent = nullptr;
        }
    }

    void zigRight(node* curr) {
        node* t2 = curr->right;
        node* par = curr->parent;

        if (!par) return;

        node* gp = par->parent;

        if (gp) {
            if (gp->right == par) {
                gp->right = curr;
            } else {
                gp->left = curr;
            }
            curr->parent = gp;
        }

        curr->right = par;
        par->parent = curr;
        par->left = t2;

        if (t2) {
            t2->parent = par;
        }

        if (!gp) {
            root = curr;
            curr->parent = nullptr;
        }
    }

    node* restructure(node* x) {
        node* y = x->parent;
        node* z = y->parent;                // grandparent
        if (!y || !z) return nullptr;
    
        // get the “middle” node after rotation
        node* m = nullptr;
    
        // LL
        if (y == z->left && x == y->left) {
            zigRight(y);           // y up over z
            m = y;
        }
        // RR
        else if (y == z->right && x == y->right) {
            zigLeft(y);            // y up over z
            m = y;
        }
        // LR
        else if (y == z->left && x == y->right) {
            zigLeft(x);            // x up over y
            zigRight(x);           // x up over z
            m = x;
        }
        // RL
        else if (y == z->right && x == y->left) {
            zigRight(x);           // x up over y
            zigLeft(x);            // x up over z
            m = x;
        } else {
            return nullptr;
        }
        return m;
    }
    
    void removeNode(node* n) {
        Color origColor = n->color;
        node* x         = (n->right ? n->right : n->left);
        node* p         = n->parent;
    
        // ---- splice as before ----
        if (root == n) {
            root = x;
            if (x) x->parent = nullptr;
        } else {
            if (p->left == n)      p->left  = x;
            else                    p->right = x;
            if (x) x->parent = p;
        }
        delete n;
        size--;
    
        // only if we removed a BLACK node do we need to fix double-black
        if (origColor == BLACK) {
            resolveDoubleBlack(x, p);
        }
    }
    
    bool _delete(int num) {
        return remove(root, num);
    }
    
    bool remove(node* n, int elem) {
        if (!n) return false;
        if (elem < n->elem)      return remove(n->left,  elem);
        else if (elem > n->elem) return remove(n->right, elem);
        else {
            if (n->left && n->right) {
                // two-child case: swap with successor
                node* tmp = n->right;
                while (tmp->left) tmp = tmp->left;
                n->elem = tmp->elem;
                return remove(n->right, tmp->elem);
            } else {
                removeNode(n);
                return true;
            }
        }
    }
    
    void resolveDoubleBlack(node* x, node* p) {
        // x may be nullptr (treat as black), but we always have p
        while (x != root && (x == nullptr || x->color == BLACK)) {
    
            // are we on the left or right of p?
            bool isLeft = (p->left == x);
    
            node* w = isLeft ? p->right : p->left;
    
            // --- Case 1: red sibling ---
            if (w && w->color == RED) {
                w->color = BLACK;
                p->color = RED;
                if (isLeft) zigLeft(w);
                else         zigRight(w);
                // new sibling
                w = isLeft ? p->right : p->left;
            }
    
            // --- Case 2: black sibling, both kids black ---
            if (w
                && (!w->left  || w->left->color  == BLACK)
                && (!w->right || w->right->color == BLACK))
            {
                if (w) w->color = RED;
                x = p;
                p = x->parent;
            }
            else {
                // ensure we have up-to-date w
                w = isLeft ? p->right : p->left;
    
                // --- Case 3: sibling black, near kid red, far kid black ---
                if (isLeft
                    && w
                    && (!w->right || w->right->color == BLACK)
                    &&  w->left && w->left->color == RED)
                {
                    w->left->color = BLACK;
                    w->color       = RED;
                    zigRight(w->left);
                    w = p->right;
                }
                else if (!isLeft
                         && w
                         && (!w->left || w->left->color == BLACK)
                         &&  w->right && w->right->color == RED)
                {
                    w->right->color = BLACK;
                    w->color        = RED;
                    zigLeft(w->right);
                    w = p->left;
                }
    
                // --- Case 4: sibling black, far kid red ---
                if (w) w->color = p->color;
                p->color = BLACK;
                if (isLeft && w->right)     w->right->color = BLACK;
                else if (!isLeft && w->left) w->left->color  = BLACK;
    
                if (isLeft)     zigLeft(w);
                else             zigRight(w);
    
                x = root;  // done
                break;
            }
        }
    
        if (x) x->color = BLACK;
    }

    void print(){
        queue<node*> q;
        
        cout << "BinaryTree: ";
        
        q.push(root);
        
        while(!q.empty()){
            node* curr = q.front();
            q.pop();
            cout << "(" << curr->elem << ", " << (curr->color == RED ? "RED" : "BLACK") << ") ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
};

