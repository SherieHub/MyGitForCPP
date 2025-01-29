#include <iostream>
using namespace std;

void getElem(int arr[], int n);
void getGaps(int arr[], int n);

int main(){
    int n;
    
    cout << "Enter n: ";
    cin >> n;
    
    int arr[n];
    getElem(arr, n);
    getGaps(arr, n);
    
    return 0;
}

void getElem(int arr[], int n){
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void getGaps(int arr[], int n){
    int start = arr[0], end = arr[n-1], x = arr[0], found, count = 0;
    
    cout << "Filling in gaps = ";
    
    for(int i = start; i < end; i++){
        found = 0;
        for(int j = 0; j < n; j++){
            if(x == arr[j]){
               found = 1;
            }
        }
        if(found == 0){
            cout << x << " ";
            count++;
        }
        x++;
    }
    if (count == 0){
        cout << "(none)";
    }
}