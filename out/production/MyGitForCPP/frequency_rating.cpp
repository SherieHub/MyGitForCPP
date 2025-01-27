#include <iostream>
using namespace std;

int main(){
    int n, rating, i = 0, frequency = 0;
    
    cout << "Enter n: ";
    cin >> n;
    
    int arr[n];
    
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Rating to count: ";
    cin >> rating;
    
    while(i < n){
        if(arr[i] == rating){
            frequency++;
        }
        i++;
    }
    
    cout << "FREQUENCY = " << frequency;
    
    return 0;
}