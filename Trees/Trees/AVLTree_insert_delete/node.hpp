#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    node* parent;
    node* right;
    node* left;
    int elem;
    
    int height() {
        int lh = left ? left->height() : -1;
        int rh = right? right->height() : -1;
        return 1 + max(lh, rh);
    }
};