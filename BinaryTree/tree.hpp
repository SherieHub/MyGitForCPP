#include "node.hpp"

class Tree{
    public:
    
    virtual node* addRoot(int elem) = 0;
    virtual node* addLeft(node* p, int elem) = 0;
    virtual node* addRight(node* p, int elem) = 0;
    virtual bool  removeNode(node* n) = 0;
    virtual node* getNode(node* p, int num) = 0;
    virtual void printPreOrder(node* p) = 0; //VLR
    virtual void printInOrder(node* p) = 0;  //LVR
    virtual void printPostOrder(node* p) = 0; //LRV
    virtual node* getRoot() = 0;
};