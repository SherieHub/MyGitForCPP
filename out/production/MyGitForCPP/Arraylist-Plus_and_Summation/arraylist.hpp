#include <iostream>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
    int array[5];
    int size;

    public:
    ArrayList() {
        array[0] = 0;
        array[1] = 0;
        array[2] = 0;
        array[3] = 0;
        array[4] = 0;
        size = 0;
    }

    void add(int num) {
        if (size < 5) {
            array[size++] = num;
        } else {
            cout << "PUNO NA MY FRIEND" << endl;
        }
    }

    int remove(int num) {
        // Step 1: FIND the num
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                // Step 2: MOVE the elements to left
                for (int j = i; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                // Step 3: Set the size
                array[size-1] = 0;
                size = size-1;
                // Step 4: Return
                return i+1;
            } 
        }
        return -1;
    }

    int get(int pos) {
        return array[pos-1];
    }

    void plus(int term){
        for(int i = 0; i < size; i++){
            array[i] += term;
        }
    }
    
    int summation(){
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += array[i];
        }
        return sum;
    }


    void print() {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};