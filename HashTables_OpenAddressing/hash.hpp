#include <iostream>
#include <cstring>
using namespace std;

class Hash {
    public:
        virtual bool isEmpty() = 0;
        virtual int hashFunction(int key) = 0;
        virtual void insertItem(int key, string value) = 0;
        virtual void removeItem(int key) = 0;
        virtual void searchItem(int key) = 0;
        virtual void printTable() = 0;
};
