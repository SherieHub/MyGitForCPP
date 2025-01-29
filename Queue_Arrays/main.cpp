
#include "queue.hpp"
#include <iostream>
using namespace std;

int main(){
    Queue* q = new Queue();
    int option, num;
    
    do{
        cout << "QUEUE_ARRAYS:" <<endl;
        cout << "1 - enqueue()" <<endl;
        cout << "2 - dequeue()" <<endl;
        cout << "3 - first()"<<endl;
        cout << "4 - size()" <<endl;
        cout << "5 - isEmpty()" <<endl;
        cout << "Enter option: ";
        cin >> option;
        
        switch(option){
            case 1:
                cout << "Enter number: ";
                cin >> num;
                q->enqueue(num);
                break;
            case 2:
                cout << "Dequeued Value: " << q->dequeue() << endl <<endl;
                break;
            case 3:
                cout << "First Value: " << q->first() << endl << endl;
                break;
            case 4:
                cout << "Size: " << q->_size() << endl <<endl;
                break;
            case 5:
                cout << "isEmpty? " << (q->isEmpty() ? "Yass" : "Naur") <<endl << endl;
                break;
        }
    }while(option != 0);
    
    return 0;
}