

node* searchNode(node* n, int num){
	    if(!n) return nullptr;
	    
	    if(num < n->elem){
	        return searchNode(n->left, num);
	    }else if(num > n->elem){
	        return searchNode(n->right, num);
	    }
	    return (num == n->elem) ? n : nullptr;
	}

int predecessor(int num){ 
        node* n = searchNode(tree->getRoot(), num);
        if (!n) return -1; 
        
        node* leftChild = n->left;
        if (n->left) {
            while (leftChild->right) {
                leftChild = leftChild->right; 
            }
            return leftChild->elem;
        }
        
        node* ancestor = n->parent;
        while (ancestor && n == ancestor->left) {
            n = ancestor; 
            ancestor = ancestor->parent;
        }
        return ancestor ? ancestor->elem : -1; 
    }

int successor(int num) { 
        node* n = searchNode(tree->getRoot(), num);
        if (!n) return -1;
        
        node* rightChild = n->right;
        if (n->right) {
            while (rightChild->left) {
                rightChild = rightChild->left;
            }
            return rightChild->elem;
        } 
        
        node* ancestor = n->parent;
        while (ancestor && n == ancestor->right) {
            n = ancestor; 
            ancestor = ancestor->parent;
        }
        return ancestor ? ancestor->elem : -1; 
    }
