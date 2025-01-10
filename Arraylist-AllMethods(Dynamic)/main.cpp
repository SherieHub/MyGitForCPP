#include "arraylist.hpp"
#include <iostream>
using namespace std;

int main(){
    List* list = new ArrayList();
    int option, num, pos;
    
    do{
        cout << "1. addFirst()" << endl;
        cout << "2. addLast()" << endl;
        cout << "3. addAt()" << endl;
        cout << "4. removeFirst()" << endl;
        cout << "5. removeLast()" << endl;
        cout << "6. removeAt()" << endl;
        cout << "7. get()" << endl;
        cout << "8. print()" << endl;
        cout << "Enter Option: ";
        cin >> option;
        
        switch(option){
            case 1:
                cout << "Enter number to addFirst: ";
                cin >> num;
                list->addFirst(num);
                break;
            case 2:
                cout << "Enter number of addLast: ";
                cin >> num;
                list->addLast(num);
                break;
            case 3:
                cout << "Enter number and position to addAt: ";
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 4:
                cout << endl << "RemoveFirst: " << list->removeFirst() << endl << endl;
                break;
            case 5:
                cout << endl << "RemoveLast: " << list->removeLast() << endl << endl;
                break;
            case 6:
                cout << "Enter position to removeAt: ";
                cin >> pos;
                cout << endl << "RemoveAt: " << list->removeAt(pos) << endl << endl;
                break;
            case 7:
                cout << "Enter position to get: ";
                cin >> pos;
                cout << endl << "Get: " << list->get(pos) << endl << endl;
                break;
            case 8:
                list->print();
                break;
            default:
                cout << "Invalid Option! Try again." << endl;
        }
    }while(option != 9);
    
    return 0;
}