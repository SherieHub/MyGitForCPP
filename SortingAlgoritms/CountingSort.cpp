//
// Created by austi on 26/03/2025.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& inputArray)
{

    int N = inputArray.size();

    int M = 0;
    bool hasNegative = false;
    int min = inputArray[0];
    for (int i = 0; i < N; i++) {
        if (inputArray[i] < 0) {
            hasNegative = true;
            for (int i = 0; i < N; i++) {
                if (inputArray[i] < min) {
                    min = inputArray[i];
                }
            }
            for (int i = 0; i < N; i++) {
                inputArray[i] += abs(min);
            }
            break;
        }
    }

    // Finding the maximum element of array inputArray[].


    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);

    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);

    // Mapping each element of inputArray[] as an index
    // of countArray[] array

    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(N);

    for (int i = N - 1; i >= 0; i--)

    {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];
        for (int i = 0; i < inputArray.size(); i++) {
            cout << outputArray[i] << " ";
        }
        cout<<endl;

        countArray[inputArray[i]]--;
    }

    if (hasNegative) {
        for (int i = 0; i < N; i++) {
            outputArray[i] -= abs(min);
        }
    }

    return outputArray;
}

// Driver code
int main()

{

    // Input array
    vector<int> inputArray = { -4, 3, 12, 1, 5, 5, 3, 9 };

    // Output array
    vector<int> outputArray = countSort(inputArray);

    for (int i = 0; i < inputArray.size(); i++)
        cout << outputArray[i] << " ";

    return 0;
}
