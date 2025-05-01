#include "mybinarytree.hpp"

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

	node* insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			return tree->addRoot(num);
		}
		return insert_node(n, num);
	}

	node* insert_node(node* n, int num) {
		if (n == NULL) {
			return NULL;
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

    bool remove(int num) {
        return remove_node(tree->getRoot(), num);
    }

	bool remove_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
            if (n->left && n->right) {
                node* r = n->right;
                while (r->left) {
                    r = r->left;
                }
                int rem = tree->remove(r);
                n->elem = rem;
            } else {
    			tree->remove(n);
            }
            return true;
		}
		if (num > n->elem) {
			return remove_node(n->right, num);
		} else {
			return remove_node(n->left, num);
		}
	}

    // GIVEN the grandparent (or z), find the parent (or y), and the child (or x).
    // bool restructure(node* gp) {
    //     node* y = gp->left;
    //     if(gp->right && gp->right->height() > (y ? y->height() : -1)){
    //         y = gp->right;
    //     }
        
    //     node* x = y->left;
    //     if(y->right && y->right->height() > (x ? x->height() : -1)){
    //         x = y->right;
    //     }
        
    //     if(y == gp->right){
    //         if(x == y->left){
    //             zigright(x);
    //             zigleft(x);
    //             cout << "ZIGZAGLEFT"<<endl;
    //             return true;
    //         }else{
    //             zigleft(y);
    //             cout << "ZIGLEFT" <<endl;
    //             return true;
    //         }
    //     }else{
    //         if(x == y->left){
    //             zigright(y);
    //             cout << "ZIGRIGHT" <<endl;
    //             return true;
    //         }else{
    //             zigleft(x);
    //             zigright(x);
    //             cout << "ZIGZAGRIGHT" <<endl;
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    bool restructure(node* gp) {
        node* par;
        int left_h = gp->left == NULL ? 0 : gp->left->height();
        int right_h = gp->right == NULL ? 0 : gp->right->height();
        
        if(left_h > right_h){
            par = gp->left;
        }else{
            par = gp->right;
        }
        
        bool gtop_right = false;
        if(gp->right == par){
            gtop_right = true;
        }
        
        node* child;
        left_h = par->left == NULL ? 0 : par->left->height();
        right_h = par->right == NULL ? 0 : par->right->height();
        
        if(left_h == right_h){
            if(gtop_right){
                child = par->right;
            }else{
                child = par->left;
            }
        }else if(left_h > right_h){
            child = par->left;
        }else{
            child = par->right;
        }
        
        bool ptoc_right = false;
        if(par->right == child){
            ptoc_right = true;
        }
        
        if(gtop_right && ptoc_right){
            cout << "ZIGLEFT" << endl;
            zigleft(par);
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
        return true;
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