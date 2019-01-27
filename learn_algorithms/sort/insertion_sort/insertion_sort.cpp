#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int *arr, int length) {
    size_t i;
    for (i = 0; i < length; i++)
        cout << arr[i] << "\t";

    cout << endl;
}

void swap(int *arr, int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void insertionSort(int *arr, int length) {
    size_t i, j;
    for (i = 0; i < length; i++)
        for (j = i; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr, j - 1, j);
            }
            printArray(arr, length);
        }
}

int main() {
    srand (time(NULL));

    size_t min, range;
    size_t i;
    min = 0;
    range = 10;
    int myArray[range];

    for (i = min; i < range; i++) {
        myArray[i] = rand() % range + min;
    }

    insertionSort(myArray, range);
    printArray(myArray, range);
    
    return 0;
}