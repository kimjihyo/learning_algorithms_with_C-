#include <iostream>

using namespace std;

void printArray(int *arr, int length) {
    size_t i;
    for (i = 0; i < length; i++)
        cout << arr[i] << "\t";
    
    cout << endl;
}

void mergeHalves(int *arr, int *temp, int leftStart, int rightEnd) {
    int leftEnd = (leftStart + rightEnd) / 2;
    int rightStart = leftEnd + 1;
    int left = leftStart; int right = rightStart;
    int index = leftStart;
    size_t i;
    while (left <= leftEnd && right <= rightEnd) {
        if (arr[left] < arr[right]) {
            temp[index] = arr[left];
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    while (left <= leftEnd) {
        temp[index] = arr[left];
        index++;
        left++;
    }

    while (right <= rightEnd) {
        temp[index] = arr[right];
        index++;
        right++;
    }
    
    for (i = 0; i < index; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int *temp, int leftStart, int rightEnd) {
    if (leftStart < rightEnd) {
        int mid = (leftStart + rightEnd) / 2;
        mergeSort(arr, temp, leftStart, mid);
        mergeSort(arr, temp, mid + 1, rightEnd);
        mergeHalves(arr, temp, leftStart, rightEnd);
    }
}

void mergeSort(int *arr, int length) {
    int *temp = new int[length];
    mergeSort(arr, temp, 0, length - 1);
}

int main() {

    int myArray[] = {5, 4, 3, 2, 1, 12, 9, 1, 2, -2, -6, 2 ,1 , 5, 2};
    int length = sizeof(myArray)/sizeof(int);
    printArray(myArray, length);
    mergeSort(myArray, length);
    printArray(myArray, length);

    return 0;
}