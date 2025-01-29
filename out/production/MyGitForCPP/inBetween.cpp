#include <iostream>
using namespace std;

int main(){
    int n, x, y, i = 0, count = 0;
    
    cout << "Enter n: ";
    cin >> n;
    
    int arr[n];
    
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Values of x and y: ";
    cin >> x >> y;
    
    cout << "Numbers in between = ";
    while(i < n){
        if(arr[i] >= x && arr[i] <= y){
            cout << arr[i] << " ";
            count++;
        }
        i++;
    }
    
    if(count == 0){
        cout << "(none)";
    }
    
    return 0;
}