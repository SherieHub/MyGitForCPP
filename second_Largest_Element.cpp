#include <iostream>
using namespace std;

int main(){
    int N;
    
    cout << "Enter the number of elements: ";
    cin >> N;
    
    int arr[N];
    
    cout << "Enter elements: ";
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    bool flag;
    
    for(int i = 0; i < N; i++){
        flag = false;
        for(int j = 0; j < N-i-1; j++){
            if(arr[j] < arr[j+1]){
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == false){
            break;
        }
    }
    
    cout << "The second largest element is " << arr[1];
    
    return 0;
}