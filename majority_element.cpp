#include <iostream>
using namespace std;

int main(){
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int arr[size];
    int temp[10];
    
    for(int i = 0; i < 10; i++){
        temp[i] = 0;
    }
    
    cout << "Enter the elements of the array separated by space: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < size; i++){
        temp[arr[i]]++;
    }
    
    int j, majority, count = 0;
    
    for(j = 0; j < 10; j++){
        if(temp[j] > size/2){
            majority = j;
            count++;
            break;
        }
    }
    
    if(count == 0){
        cout << "No majority element found" <<endl;
    }else{
        cout << "The majority element is " << majority;
    }
    
    return 0;
}