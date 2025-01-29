#include "stack.hpp"
#include <iostream>
using namespace std;

int main(){
    Stack* st = new Stack();
    int num, option;
    
    do{
        cout << "STACK:" <<endl;
        cout << "1 - push()" <<endl;
        cout << "2 - pop()" <<endl;
        cout << "3 - top()" <<endl;
        cout << "4 - size()" <<endl;
        cout << "5 - isEmpty()" <<endl;
        cout << "Enter option: ";
        cin >> option;
        
        switch(option){
            case 1:
                cout << "Enter number: ";
                cin >> num;
                st->push(num);
                break;
            case 2:
                cout << "Popped Value: " << st->pop() << endl << endl;
                break;
            case 3:
                cout << "Top Value: " << st->top() << endl <<endl;
                break;
            case 4:
                cout << "Size: " << st->_size() <<endl << endl;
                break;
            case 5:
                cout << "isEmpty? " << (st->isEmpty() ? "Yass" : "Naur") <<endl <<endl;
                break;
        }
    }while(option != 0);
    
    return 0;
}