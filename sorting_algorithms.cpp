#include <iostream>
using namespace std;

void swap(int* arr, int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// 1. BUBBLE SORT
void bubbleSort(int* arr, int size){
    bool flag;
    
    for(int i = 0; i < size; i++){
        flag = false;
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                flag = true;
                swap(arr, j, j+1);
            }
        }
        if(!flag) break;
    }
}

// 2. SELECTION SORT
void selectionSort(int* arr, int size){
    for(int i = 0; i < size-1; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            swap(arr, i, min);
        }
    }
}

// 3. INSERTION SORT
void insertionSort(int* arr, int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 4. COUNTING SORT
void countingSort(int* arr, int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    int* count = new int[max+1];
    
    for(int i = 0; i < size; i++){
        count[arr[i]]++;
    }
    
    for(int i = 1; i <= max; i++){
        count[i] += count[i-1];
    }
    
    int* output = new int[size];
    
    for(int i = size-1; i >= 0; i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    
    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

int partition(int* arr, int start, int end){
    int pivot = arr[end];
    int i = start-1;
    
    for(int j = start; j < end; j++){
        if(arr[j] < pivot) {
            i++;
            swap(arr, j, i);
        }
    }
    i++;
    swap(arr, i, end);
    return i;
}

// 5. QUICK SORT
void quickSort(int* arr, int start, int end){
    if(end <= start) return;
    
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}

void merge(int* leftArr, int leftSize, int* rightArr, int rightSize, int* arr){
    int l = 0, r = 0, i = 0;
    int length = leftSize + rightSize;
    
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

// 6. MERGE SORT
void mergeSort(int* arr, int size){
    if(size <= 1) return;
    
    int middle = size/2;
    int* leftArr = new int[middle];
    int* rightArr = new int[size-middle];
    
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

// 7. SHELL SORT
void shellSort(int* arr, int size){
    for(int gap = size/2; gap > 0; gap /= 2){
        for(int i = gap; i < size; i++){
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j-gap] > temp; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

void count(int* arr, int size, int exp){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    int* count = new int[max+1];
    
    for(int i = 0; i < size; i++){
        count[(arr[i] / exp) % 10]++;
    }
    
    for(int i = 1; i <= max; i++){
        count[i] += count[i-1];
    }
    
    int* output = new int[size];
    
    for(int i = size-1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10]-1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

// 8. RADIX SORT
void radixSort(int* arr, int size){
    int max = 0;
    
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    for(int exp = 1; max/exp > 0; exp *= 10){
        count(arr, size, exp);
    }
}

int main(void) {
    int arr[] = {6, 8, 3, 1, 4, 5, 2, 7, 10, 9};
    int size = 10;
    
    cout << "Unsorted Array: ";
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
};

