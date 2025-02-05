#include "binarytree.hpp"
#include <iostream>
using namespace std;

int main() {
    BinaryTree* tree = new BinaryTree();
    int option;
    int num, parNum;
    node* temp;

    do {
        cout << "Choose operation: " <<endl;
        cout << "1. addRoot()" <<endl;
        cout << "2. addLeft()" <<endl;
        cout << "3. addRight()" <<endl;
        cout << "4. height()" <<endl;
        cout << "5. depth()" <<endl;
        cout << "6. removeNode()" <<endl;
        cout << "7. printBreadthFirst()" <<endl;
        cout << "8. printPreOrder()" <<endl;
        cout << "9. printInOrder()" <<endl;
        cout << "10. printPostOrder()" <<endl;
        cout << "0. Exit" <<endl;
        cout << "Enter choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                try{
                    cout << "Enter element to add to the root: ";
                    cin >> num;
                    tree->addRoot(num);
                    cout << endl << endl;
                }catch(exception& e){
                    cout << e.what() << endl;
                }
                break;
            }
            case 2:
                try{
                    cout << "Enter parent element to add a left child to: ";
                    cin >> parNum;
                    
                    node* p = tree->getNode(tree->getRoot(), parNum);
                    
                    if(!p) throw logic_error("Parent node not found.");
                    
                    cout << "Enter element to add to the left: ";
                    cin >> num;
                    tree->addLeft(p, num);
                    cout << endl << endl;
                }catch(exception& e){
                    cout << e.what() << endl;
                }
                break;
            case 3:
                try{
                    cout << "Enter parent element to add a right child to: ";
                    cin >> parNum;
                    
                    node* p = tree->getNode(tree->getRoot(), parNum);
                    
                    if(!p) throw logic_error("Parent node not found.");
                    
                    cout << "Enter element to add to the right: ";
                    cin >> num;
                    tree->addRight(p, num);
                    cout << endl << endl;
                }catch(exception& e){
                    cout << e.what() << endl;
                }
                break;
            case 4:
                cout << "Enter element to get its height: ";
                cin >> num;
                temp = tree->getNode(tree->getRoot(), num);
                cout << "Height of Element " << num << ": " << temp->height() <<endl;
                cout << endl << endl;
                break;
            case 5:
                cout << "Enter element to get its depth: ";
                cin >> num;
                temp = tree->getNode(tree->getRoot(), num);
                cout << "Depth of Element " << num << ": " << temp->depth() <<endl;
                cout << endl << endl;
                break;
            case 6:
                cout << "Enter element to remove: ";
                cin >> num;
                temp = tree->getNode(tree->getRoot(), num); 
                tree->removeNode(temp);
                cout << endl << endl;
                break;
            case 7:
                tree->printBreadthFirst(tree->getRoot());
                cout << endl << endl;
                break;
            case 8:
                tree->printPreOrder(tree->getRoot());
                cout << endl << endl;
                break;
            case 9:
                tree->printInOrder(tree->getRoot());
                cout << endl << endl;
                break;
            case 10:
                tree->printPostOrder(tree->getRoot());
                cout << endl << endl;
                break;
            case 0: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (option != 0);
    return 0;
}
