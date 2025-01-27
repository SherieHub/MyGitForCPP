#include <iostream>
using namespace std;

int main(){
    int arr[10];
    
    cout << "Enter 10 integers:" <<endl;
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    
    int found = 0;
    
    for(int i = 0; i < 9; i++){
        for(int j = i+1; j < 10; j++){
            if(arr[i] == arr[j]){
                found = 1;
            }
        }
    }
    
    if(found == 1){
        cout << "Duplicate found" <<endl;
    }else{
        cout << "No duplicates" <<endl;
    }
    
    return 0;
}