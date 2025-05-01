#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    node* parent;
    node* right;
    node* left;
    int elem;

    // TODO paste your height method here
    int height() {
        if(!left && !right) return 1;
        if(!left) return 1 + right->height();
        if(!right) return 1 + left->height();
        return 1 + fmax(right->height(), left->height());
    }
};