#include <iostream>

using namespace std;

bool binarySearch(int arr[], int left, int right, int target) {
}

bool binarySearch(int arr[], int length, int target) {
    return binarySearch(arr, 0, length - 1, target);
}