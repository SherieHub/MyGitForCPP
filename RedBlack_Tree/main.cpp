#include "binarytree.hpp"
#include <iostream>
using namespace std;

int main(){
    BinaryTree* tree = new BinaryTree();
    int choice = 1;
    int num;
    
    do{
        cout << "1. insert" <<endl;
        cout << "2. delete" <<endl;
        cout << "3. print" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        
        switch(choice){
            case 1:
                cout << "Enter element to insert: ";
                cin >> num;
                if(tree->insert(num)){
                    cout << num << " is already inserted in the tree" <<endl;
                }else{
                    cout << num << " is not inserted in the tree" <<endl;
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> num;
                if(tree->_delete(num)){
                    cout << num << " is already deleted in the tree" <<endl;
                }else{
                    cout << num << " is not deleted in the tree" <<endl;
                }
                cout << endl;
                break;
            case 3:
                tree->print();
                cout << endl << endl;
                break;     
        }
    }while(choice != 0);

    return 0;
}
