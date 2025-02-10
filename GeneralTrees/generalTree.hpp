#pragma once
#include "tree.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

class GeneralTree: public Tree {
    int size;

public:
    node* root;
    GeneralTree() {
        root = nullptr;
        size = 0;
    }

    node* create_node(int elem){
        node* n = new node();
        n->num_child = 0;
        n->parent = 0;
        n->elem = elem;
        n->children = (node**)malloc(0);
        size++;
        return n;
    }

    void resizeChildren(node* p){
        p->children = (node**)realloc(p->children, p->num_child, sizeof(node*));
    }

    node* addRoot(int num) {
        if (root) throw logic_error("Root already exists");

        root = (node**)malloc(1, sizeof(node*));
        root->elem = num;
        size++;

        return root;
    }

    node* addChild(node* p, int num)  {
        node* n = create_node(e);

        p->num_child++;
        resizeChildren(p);
        p->children[p->num_child - 1] = n;
        n->parent = p;

        return n;
    }

    void removeNode(node* n){
        if(n->num_child) throw logic_error(to_string(n->elem) + " has children");

        node* p = n->parent;
        if(p){
            for(int i = 0; i < p->num_child; i++){
                if(p->children[i] == n){
                    for(int j = i; j < p->num_child-1; j++){
                        p->children[j] = p->children[j+1];
                    }
                }
            }
        }else{
            root = nullptr;
        }
        delete n;
        size--;
    }

};
