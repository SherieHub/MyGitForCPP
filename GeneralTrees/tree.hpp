#pragma once
#include "node.hpp"
using namespace std;
class Tree {

    virtual node* create_node() = 0;
    virtual void resizeChildren(node* p) = 0;
    virtual node* addRoot(int num) = 0;
    virtual node* addChild(node* p, int num) = 0;
    virtual void removeNode(node* n) = 0;

};