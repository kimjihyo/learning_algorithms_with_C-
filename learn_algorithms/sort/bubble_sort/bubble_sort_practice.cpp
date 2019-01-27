#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int *arr, int length) {
    int i = 0;
    for (i = 0; i < length; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

void swap(int *arr, int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void bubbleSort(int *arr, int length) {
    int i;
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

void selectionSort(int *arr, int length) {
    int i, j, minIndex;
    for (i = 0; i < length; i++) {
        minIndex = i;
        for (j = i; j < length; j++) {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr, i, minIndex);
    }
}

void insertionSort(int *arr, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr, j, j - 1);
        }
    }
}

void mergeHalves(int *arr, int leftStart, int rightEnd) {
    int mid = (leftStart + rightEnd) / 2;
    int leftSize = mid - leftStart + 1;
    int rightSize = rightEnd - mid;
    int leftArray[leftSize];
    int rightArray[rightSize];
    int left, right, index;

    for (left = 0; left < leftSize; left++)
        leftArray[left] = arr[leftStart + left];
    for (right = 0; right < rightSize; right++)
        rightArray[right] = arr[mid + 1 + right];
    
    left = 0; right = 0; index = leftStart;
    while (left < leftSize && right < rightSize) {
        if (leftArray[left] < rightArray[right]) {
            arr[index] = leftArray[left];
            left++;
        } else {
            arr[index] = rightArray[right];
            right++;
        }
        index++;
    }

    while (left < leftSize) {
        arr[index] = leftArray[left];
        left++; index++;
    }

    while (right < rightSize) {
        arr[index] = rightArray[right];
        right++; index++;
    }
}

void mergeSort(int *arr, int leftStart, int rightEnd) {
    if (leftStart < rightEnd) {
        int mid = (leftStart + rightEnd) / 2;
        mergeSort(arr, leftStart, mid);
        mergeSort(arr, mid + 1, rightEnd);
        mergeHalves(arr, leftStart, rightEnd);
    }
}

void mergeSort(int *arr, int length) {
    mergeSort(arr, 0, length - 1);
}

int main() {
    int length = 10;
    int arr[length];
    int i;
    srand (time(NULL));

    for (i = 0; i < length; i++)
        arr[i] = rand() % 10;

    printArray(arr, length);
    mergeSort(arr, length);
    printArray(arr, length);
    return 0;
}
