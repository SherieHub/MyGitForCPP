#pragma once
struct node{
    int elem;
    int num_child;
    node* parent;
    node** children;

    int depth(){
        if(!parent) return 0;
        return parent->depth() + 1;
    }

    int height(){
        int height = 0;
        for(int i = 0; i < num_child; i++){
            int innerHeight = children[i]->height() + 1;
            if(innerHeight > height) height = innerHeight;
        }
        return height;
    }
};
