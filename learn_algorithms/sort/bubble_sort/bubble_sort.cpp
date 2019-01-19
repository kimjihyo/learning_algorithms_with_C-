#include <iostream>

using namespace std;

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort (int *arr, int length) {
    size_t i;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                isSorted = false;
            }
        }
    }
}

int main() {
    int myArray[7] = {2, 1, 8, 3, 4, 1, 10};
    size_t i;
    bubbleSort(myArray, 7);

    for (i = 0; i < 7; i++) {
        cout << myArray[i] << "\t";
    }
    cout << endl;
    return 0;
}