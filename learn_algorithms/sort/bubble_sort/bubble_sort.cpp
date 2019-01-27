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
    int myArray[] = {1, 5,8, 3, 4,9, -9, -8, -7, 2, 5, 78, 1, 42, 1,42, 1,3 ,2, 312,321,321,312,312,312,312,312,3,123,213,123,12,312,312,3,123,12,312,312,3,123,123,12,3124,2,35,345,43,64,645,654,5,345,234,234,234,23,534,5634,423,4,234,2,312,312,31,423,534,5,345,43,534,423,4,24,234,234,234,23-4-23,423,-4234,-234,-23423,4,4,-234,-23,42,34,234,23,423,423,4,234,23,423,4,23,31,3,312};
    int length = sizeof(myArray)/sizeof(int);
    size_t i;
    bubbleSort(myArray, length);

    for (i = 0; i < length; i++) {
        cout << myArray[i] << "\t";
    }
    cout << endl;
    return 0;
}