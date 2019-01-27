#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int *arr, int length) {
    size_t i;
    for (i = 0; i < length; i++)
        cout << arr[i] << "\t";
    
    cout << endl;
}

void mergeHalves(int *arr, int leftStart, int rightEnd) {
    int mid = (leftStart + rightEnd) / 2;
    int leftSize = mid - leftStart + 1;
    int rightSize = rightEnd - mid;
    size_t left, right, index;
    int leftArray[leftSize], rightArray[rightSize];

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
        left++;
        index++;
    }

    while (right < rightSize) {
        arr[index] = rightArray[right];
        right++;
        index++;
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
    srand (time(NULL));

    size_t min, range;
    size_t i;
    min = 0;
    range = 20000;
    int myArray[range];

    for (i = min; i < range; i++) {
        myArray[i] = rand() % range + min;
    }

    mergeSort(myArray, range);
    printArray(myArray, range);
    
    return 0;
}