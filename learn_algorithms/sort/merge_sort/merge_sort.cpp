#include <iostream>

using namespace std;

void printArray(int *arr, int length) {
    size_t i;
    for (i = 0; i < length; i++)
        cout << arr[i] << "\t";
    
    cout << endl;
}

void mergeHalves(int *arr, int leftStart, int rightEnd, int mid) {
    int leftSize = mid + 1 - leftStart;
    int rightSize = rightEnd - mid;
    int leftArray[leftSize], rightArray[rightSize];
    int i, j, index;
    for (i = 0; i < leftSize; i++)
        leftArray[i] = arr[leftStart + i];

    
    for (j = 0; j < rightSize; j++)
        rightArray[j] = arr[mid + 1 + j];


    i = 0; j = 0; index = leftStart;


    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            arr[index] = leftArray[i];
            i++;
        } else {
            arr[index] = rightArray[j];
            j++;
        }
        index++;
    }


    while (i < leftSize) {
        arr[index] = leftArray[i];
        i++;
        index++;
    }

    while (j < rightSize) {
        arr[index] = rightArray[j];
        j++;
        index++;
    }

    cout << index << endl;
}

void mergeSort(int *arr, int leftStart, int rightEnd) {
    if (leftStart < rightEnd) {
        int mid = leftStart + (rightEnd - leftStart) / 2;
        mergeSort(arr, leftStart, mid);
        mergeSort(arr, mid + 1, rightEnd);

        mergeHalves(arr, leftStart, rightEnd, mid);
    }
}


int main() {
    int myArray[] = {1, 5,8, 3, 4,9};
    mergeSort(myArray, 0, sizeof(myArray)/sizeof(int) - 1);
    printArray(myArray, sizeof(myArray)/sizeof(int));
    return 0;
}