#include <iostream>
using namespace std;

struct node{
    int elem;
    node* left;
    node* right;
    node* parent;
    
     int depth(){
        return parent ? 1 + parent->depth() : 0;
    }
    
    int height(){
        int leftHeight = left ? left->height() : -1;
        int rightHeight = right ? right->height() : -1;
        return 1 + max(leftHeight, rightHeight);
    }

};