#include <iostream>

using namespace std;

void printArray(int *arr, int length) {
    size_t i;
    for (i = 0; i < length; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;
}

void swap(int *arr, int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void selectionSort(int *arr, int length) {
    size_t i, j;
    size_t minIndex;
    for (i = 0; i < length; i++) {
        minIndex = i;
        for (j = i; j < length; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
}


int main() {
    int myArray[] = {2, 1, 5, 4, 3, 20, 15, 19, 18, 16, 17, 11, 31, 26, 5, 8};
    int length = sizeof(myArray)/sizeof(int);
    printArray(myArray, length);
    selectionSort(myArray, length);
    printArray(myArray, length);
    return 0;
}