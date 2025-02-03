#pragma once
class List{
public:

    virtual void addTail(int num) = 0;
    virtual void addHead(int num) = 0;
    virtual int removeHead() = 0;
    virtual int removeTail() = 0;
    virtual int getSize() = 0;
    virtual void print() = 0;
};
