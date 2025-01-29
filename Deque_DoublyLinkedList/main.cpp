#include "dequedoubly.hpp"
#include <iostream>
using namespace std;

int main(){
    Deque* d = new Deque_DoublyLinkedList();
    int option, num;
    
    do{
        cout << "DEQUE_DOUBLYLINKEDLIST:" <<endl;
        cout << "1 - addFirst()" <<endl;
        cout << "2 - addLast()" <<endl;
        cout << "3 - removeFirst()"<<endl;
        cout << "4 - removeLast()" <<endl;
        cout << "5 - size()" <<endl;
        cout << "6 - isEmpty()" <<endl;
        cout << "7 - print()" <<endl;
        cout << "Enter option: ";
        cin >> option;
        
        cout << endl;
        
        switch(option){
            case 1:
                cout << "Enter number: ";
                cin >> num;
                d->addFirst(num);
                break;
            case 2:
                cout << "Enter number: ";
                cin >> num;
                d->addLast(num);
                break;
            case 3:
                cout << "Removed Head: " << d->removeFirst() << endl << endl;
                break;
            case 4:
                cout << "Removed Tail: " << d->removeLast() << endl << endl;
                break;
            case 5:
                cout << "Size: " << d->_size() << endl <<endl;
                break;
            case 6:
                cout << "isEmpty? " << (d->isEmpty() ? "Yass" : "Naur") <<endl << endl;
                break;
            case 7:
                d->_print();
                break;
        }
    }while(option != 0);
    
    return 0;
}