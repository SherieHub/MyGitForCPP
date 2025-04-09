#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    int elem;
    node* parent;
    node* left;
    node* right;

    int height() {
        int lh = left ? left->height() : -1;
        int rh = right ? right->height() : -1;
        return 1 + max(lh, rh);
    }
};
