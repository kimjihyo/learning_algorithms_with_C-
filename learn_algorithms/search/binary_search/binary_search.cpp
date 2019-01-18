#include <iostream>

using namespace std;

bool binarySearch(int *arr, int value, size_t left, size_t right) {
    if (left > right)
        return false;
    int mid = (left + right) / 2;
    cout << "mid: " << mid << endl;
    if (arr[mid] == value)
        return true;
    else if (arr[mid] > value)
        return binarySearch(arr, value, left, mid - 1);
    else
        return binarySearch(arr, value, mid + 1, right);
}

bool binarySearch(int *arr, int length, int value) {
    return binarySearch(arr, value, 0, length - 1);
}


int main() {
    int myArray[5] = {0, 1, 2, 3, 4};
    cout << binarySearch(myArray, sizeof(myArray)/sizeof(int), 0) << endl;
    return 0;
}