#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct node {
    int elem;
    node* left;
    node* right;
    node* parent;
    Color color;
};