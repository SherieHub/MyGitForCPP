#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    bool flag;
    
    for(int i = 0; i < size; i++){
        flag = false;
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!flag) break;
    }
}

void selectionSort(int arr[], int size){
    int min;
    for(int i = 0; i < size-1; i++){
        min = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min]) min = j;
        }
        
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void countingSort(int arr[], int size){
    int max = arr[0];
    
    for(int i = 0; i < size; i++){
        if(arr[i] > max) max = arr[i];
    }
    
    int count[max+1];
    for(int i = 0; i < max+1; i++){
        count[i] = 0;
    }
    
    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    
    for(int i = 1; i < max+1; i++){
        count[i] += count[i-1];
    }
    
    int output[size];
    
    for(int i = size-1; i >= 0; i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    
    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

int partition(int arr[], int start, int end, int size){
    int pivot = arr[start];
    int i = start+1;
    
    for(int j = start+1; j <= end; j++){
        if(arr[j] < pivot){
            if(i != j && arr[i] != arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            i++;
        }
    }
    
    if(start != i-1 && arr[start] != arr[i-1]){
        int temp = arr[start];
        arr[start] = arr[i-1];
        arr[i-1] = temp;
    }
        
    return i - 1;
}

void quickSort(int arr[], int start, int end, int size){
    if(start >= end) return;
    
    int pivot = partition(arr, start, end, size);
    quickSort(arr, start, pivot-1, size);
    quickSort(arr, pivot+1, end, size);
}

void merge(int leftArr[], int leftSize, int rightArr[], int rightSize, int arr[]){
    int i = 0, l = 0, r = 0;
    int size = leftSize + rightSize;
    
    while(l < leftSize && r < rightSize){
        if(leftArr[l] < rightArr[r]){
            arr[i++] = leftArr[l++];
        }else{
            arr[i++] = rightArr[r++];
        }
    }
    
    while(l < leftSize){
        arr[i++] = leftArr[l++];
    }
    
    while(r < rightSize){
        arr[i++] = rightArr[r++];
    }
}

void mergeSort(int arr[], int size){
    if(size <= 1) return;
    
    int middle = size/2;
    int leftArr[middle];
    int rightArr[size-middle];
    
    for(int i = 0; i < middle; i++){
        leftArr[i] = arr[i];
    }
    
    for(int i = middle; i < size; i++){
        rightArr[i-middle] = arr[i];
    }
    
    mergeSort(leftArr, middle);
    mergeSort(rightArr, size-middle);
    merge(leftArr, middle, rightArr, size-middle, arr);
}

void shellSort(int arr[], int size){
    for(int gap = size/2; gap > 0; gap/=2){
        for(int i = gap; i < size; i++){
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j-gap] > temp; j-=gap){
                arr[j] = arr[j-gap];
            }
            
            if(j != i){
                arr[j] = temp;
            }
        }
    }
}

void counting(int arr[], int size, int exp){
    int max = arr[0];
    
    for(int i = 0; i < size; i++){
        if(arr[i] > max) max = arr[i];
    }
    
    int count[max+1];
    for(int i = 0; i < max+1; i++){
        count[i] = 0;
    }
    
    for(int i = 0; i < size; i++){
        count[(arr[i]/exp)%10]++;
    }
    
    for(int i = 1; i < max+1; i++){
        count[i] += count[i-1];
    }
    
    int output[size];
    
    for(int i = size-1; i >= 0; i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    
    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size){
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > max) max = arr[i];
    }
    
    for(int exp = 1; max/exp > 0; exp *= 10){
        counting(arr, size, exp);
    }
}

int main(){
    int arr[] = {45, 83, 11, 5, 23, 60, 34, 76, 1, 51, 15, 22, 89, 123, 16};
    int size = 15;
    
    cout << "Original Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    radixSort(arr, size);
    
    cout << "Sorted Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}


