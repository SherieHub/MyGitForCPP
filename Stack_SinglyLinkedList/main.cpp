#include "stacklinkedlist.h"
#include <iostream>
using namespace std;

int main(){
    Stack* stack = new StackLinkedList();
    int op;
    
    do{
        cout << "\n1. push()" <<endl;
        cout << "2. pop()" <<endl;
        cout << "3. top()" <<endl;
        cout << "4. size()" <<endl;
        cout << "5. isEmpty()" <<endl;
        cout << "Enter choice: ";
        cin >> op;
        
        switch(op){
            case 1:
                int num;
                cout << "Enter number to add: ";
                cin >> num;
                stack->push(num);
                break;
            case 2:
                int poppedVal;
                poppedVal = stack->pop();
                cout << "Popped Value: " << poppedVal <<endl;
                break;
            case 3:
                int topVal;
                topVal = stack->top();
                cout << "Top Value: " << topVal <<endl;
                break;
            case 4:
                cout << "Size: " << stack->sizeList() <<endl;
                break;
            case 5:
                cout << "Empty? ";
                if(stack->isEmpty()){
                    cout << "YES!";
                }else{
                    cout << "NAUR!";
                }
                cout <<endl;
                break;
        }
    }while(op != 0);
    return 0;
}
