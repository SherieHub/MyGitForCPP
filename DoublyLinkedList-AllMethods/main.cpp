#include "doubly.hpp"
#include <iostream>
using namespace std;

int main(){
    List* list = new DoublyLinkedList();
    int option, num, pos;
    
    do{
        cout << "1. addHead()" << endl;
        cout << "2. addTail()" << endl;
        cout << "3. addAt()" << endl;
        cout << "4. removeHead()" << endl;
        cout << "5. removeTail()" << endl;
        cout << "6. removeAt()" << endl;
        cout << "7. get()" << endl;
        cout << "8. print()" << endl;
        cout << "Enter Option: ";
        cin >> option;
        
        switch(option){
            case 1:
                cout << "Enter number to addHead: ";
                cin >> num;
                list->addHead(num);
                break;
            case 2:
                cout << "Enter number to addTail: ";
                cin >> num;
                list->addTail(num);
                break;
            case 3:
                cout << "Enter number and position to addAt: ";
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 4:
                cout << "REMOVED_HEAD: " << list->removeHead() << endl << endl;
                break;
            case 5:
                cout << "REMOVED_TAIL: " << list->removeTail() << endl << endl;
                break;
            case 6:
                cout << "Enter position to removeAt: ";
                cin >> pos;
                cout << "REMOVED_AT: " << list->removeAt(pos) << endl << endl;
                break;
            case 7:
                cout << "Enter position of number to get: ";
                cin >> pos;
                cout << "GET: " << list->get(pos) << endl << endl;
                break;
            case 8:
                list->print();
                break;
            default:
                cout << "Invalid Option! Try again." << endl;
        }
    }while(option != 9);
}