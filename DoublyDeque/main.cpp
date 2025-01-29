
#include "doublydeque.hpp"
#include <iostream>
using namespace std;

int main(){
    Deque* d = new DoublyDeque();
    int num, res;
    char op;

    cout << endl;

    do{
        cout << "Enter op(f- addFirst, l-addLast, F-removeFirst, L- removeLast, s-size, ?-isEmpty, p-print): ";
        cin >> op;

        switch(op){
            case 'f':
                cin >> num;
            d->addFirst(num);
            break;
            case 'l':
                cin >> num;
            d->addLast(num);
            break;
            case 'F':
                cout << "Removed at First: " << d->removeFirst() <<endl;
            break;
            case 'L':
                cout << "Removed at Last: " << d->removeLast() <<endl;
            break;
            case 's':
                cout << "Size: " << d->_size() <<endl;
            break;
            case '?':
                cout << "isEmpty? ";
            if(d->isEmpty()){
                cout << "YASSS!" <<endl;
            }else{
                cout << "NAUR!" <<endl;
            }
            break;
            case 'p':
                d->_print();
            break;
            case 'x':
                cout << "Exiting..." <<endl;
        }
    }while(op != 'x');

    return 0;
}

